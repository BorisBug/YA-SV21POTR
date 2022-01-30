#include <TSPISlave.h>

#define STRLEN 32
#define SPI_SCK 14

static uint8_t counter = 0;
static uint8_t string[STRLEN] = {0};
static TSPISlave slave = TSPISlave(SPI, PIN_SPI_MISO, PIN_SPI_MOSI, SPI_SCK, PIN_SPI_SS);

void receive(void)
{
    counter = 0;

    while (slave.active())
    {
        if (slave.available())
        {
            uint8_t data = slave.popr();

            if (data == 0)
            {
                slave.pushr(toupper(string[counter]));
            }
            else
            {
                string[counter] = data;
            }

            counter = (counter + 1) % STRLEN;
        }
    }
}

void setup()
{
    slave.onReceive(receive);
}

void loop()
{
}
