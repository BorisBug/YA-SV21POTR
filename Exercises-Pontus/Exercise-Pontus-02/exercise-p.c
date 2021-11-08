#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

static uint32_t EXER_REGISTER_SENDER;
static uint32_t EXER_REGISTER_RECEIVER;
static uint32_t EXER_BUFFER;

// start and end could easily swap places depending on the interpretation.. L->R or R->L
#define MSG_START 25
#define MSG_END 10

#define MASK_MSG 0x03FFFC00
#define MASK_CHKS 0xFC000000
#define MASK_FLAGS 0x000000FF

/*
4 checksum bits, 2 zero bits, 16 bits for message, 2 zero bits, 8 bits for flags

[0000][00][0000 0000 0000 0000][00][0000 0000]

Calculate checksum by adding all bits in the message togheter
Zero bits are just zero's
8bits for flag is for control

pos 0 = On / Off
pos 1 = Sending or reciving
pos 2 = Keep message after sending
pos 3 = Use checksum or not
pos 4 = Not used
pos 5 = Not used
pos 6 = Not used
pos 7 = Not used

Store the message in one register calculate the checksum, sending it to a buffer. 
Then get the message from the buffer using the other register, verifying and printing it out.

Remember to send along the checksum, if you need to.
Delete the message in the sender, if need to.

Try and make it so, setting flags is easy
*/

typedef enum FLAG
{
    F_ON = 0x0001,
    F_SENDING = 0x0002,
    F_KEEP_MSG = 0x0004,
    F_USE_CHECKSUM = 0x0008,
} flag_t;

/********************************************
Checksum functions
********************************************/

uint32_t calc_checksum(uint32_t x)
{
    // checksum in message placed between bits 10-25
    uint32_t chksum = 0;
    for(int i=MSG_START; i>=MSG_END; i--)
        chksum += (x>>i)&1 ? 1 : 0;

    return chksum << 28;
}


/********************************************
Message functions
********************************************/

uint16_t get_message(uint32_t reg)
{
    reg &= MASK_MSG;
    reg >>= MSG_END; 
    return reg;
}

void set_message(uint32_t *reg, uint16_t msg)
{
    *reg &= ~MASK_MSG; 
    *reg |= ((uint32_t)msg)<<MSG_END;
}

/********************************************
Flag functions
********************************************/

bool get_flag(uint32_t reg, flag_t flag)
{
    return (reg&flag) != 0;
}

void set_flag(uint32_t *reg, flag_t flag, bool on)
{
    if(on)
        *reg |= flag;
    else
        *reg &= ~flag;
}

/********************************************
Testing/debugging functions
********************************************/

void print_register(uint32_t reg)
{
    uint32_t bits = sizeof(reg)*8;

    printf("[chks][00][ - m e s s a g e - ][00][f l a g s]\n");
    printf("[");

    for(int i=bits-1; i>=0; i--)
    {
        if (i==7 || i==9 || i==25 || i==27)
            printf("][");
        else if (i==3 || i==13 || i==17 || i==21)
            printf(" ");

        printf("%c", (reg>>i)&1 ? '1' : '0');
    }

    printf("] <- %08X\n", reg);
}

void print_values(uint32_t reg)
{
    uint32_t chk = calc_checksum(reg) >> 28;
    uint32_t msg = get_message(reg);
    bool on = get_flag(reg, F_ON);
    bool send = get_flag(reg, F_SENDING);
    bool keep = get_flag(reg, F_KEEP_MSG);
    bool usechk = get_flag(reg, F_USE_CHECKSUM);

    printf("[%4u] << [  %6u = 0x%04X  ]    [flags: USECHK=%d KEEP=%d SND=%d ON=%d]\n", chk, msg, msg, usechk, keep, send, on);
}

void print_test(uint32_t reg, const char *txt)
{
    printf("Test: %s\n", txt);
    print_register(reg);
    print_values(reg);
    printf("\n");
}


/********************************************
Original exercise functions, ready to edit
********************************************/

/*
uint32_t get_checksum(uint32_t reg)
{
    return (reg & MASK_CHKS);
}

void set_checksum(uint32_t *reg, uint32_t chksum)
{
    *reg &= ~MASK_CHKS;
    *reg |= chksum; 
}*/

bool send(uint32_t *sender, uint32_t *buffer)
{
    bool status = false;

    // reset
    *buffer = 0;

    // add message
    *buffer |= (*sender) & MASK_MSG;

    // add checksum
    *buffer |= calc_checksum(*sender);

    // set flags
    *buffer |= F_USE_CHECKSUM;
    *buffer |= F_SENDING;

    // harcoded ?
    status = true;
    return status;
}

bool get(uint32_t *receiver, uint32_t *buffer)
{
    bool status = false;

    if(get_flag(*buffer, F_USE_CHECKSUM) && (calc_checksum(*buffer) != (*buffer&MASK_CHKS)))
    {
        status = false;
    }
    else
    {
        status = true;

        // reset
        *receiver = 0;

        // add message
        *receiver |= (*buffer) & MASK_MSG;

        // add flags
        *receiver |= (*buffer) & MASK_FLAGS;

        // basically we could just do
        // *receiver = *buffer
    }

    return status;
}

int main(void)
{
    print_test(MASK_MSG, "Calculate cheksum for FULL message");
    printf("..note how the CHKS becomes 0 because of overflow.. correct?\n\n");

    print_test(~MASK_MSG, "Calculate cheksum for EMPTY message"); 
    print_test(0x02AAA800, "Try zig-zag values for message");

    EXER_REGISTER_SENDER = 0x02AAA800; // MASK_MSG;
    EXER_REGISTER_RECEIVER = 0;
    EXER_BUFFER = 0;

    /*
    Store the message in one register calculate the checksum, sending it to a buffer.
    Then get the message from the buffer using the other register, verifying and printing it out.

    Remember to send along the checksum, if you need to.
    Delete the message in the sender, if need to.

    Try and make it so, setting flags is easy
    */

    print_test(EXER_REGISTER_SENDER, "Sending ...");

    if (send(&EXER_REGISTER_SENDER, &EXER_BUFFER))
    {
        print_test(EXER_BUFFER, "In buffer ...");

        if (get(&EXER_REGISTER_RECEIVER, &EXER_BUFFER))
        {
            print_test(EXER_REGISTER_RECEIVER, "Received ...");
        }
    }

    return 0;
}