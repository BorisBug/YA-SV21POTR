#include <Arduino.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "AES256.h"

#define MSG_SIZE 20

static uint8_t rand_generator(void)
{
    return (uint8_t)random(0xFF);
}

static void print_data(const uint8_t *data, uint8_t size)
{
    for(uint8_t i=0; i<size; i++)
    {
        Serial.printf("%02X ", data[i]);
    }
    Serial.println();
}

static void get_message(char *msg, unsigned int size)
{
    bool repeat = true;
    uint8_t index = 0;

    while(repeat)
    {
        if(Serial.available())
        {
            int chr = Serial.read();
            if(chr=='\r' || chr=='\n')
            {
                msg[index] = 0;
                if(index>0)
                    repeat = false;
            }
            else
            //if(isalnum(chr) || isspace(chr))
            if(index<size-1)
            {
                msg[index++] = chr;
                Serial.print((char)chr);
            }
        }
    }

    Serial.println();
}

void setup()
{
    Serial.begin(9600);
    while(!Serial)
    {
        delay(100);
    }

    aes256_init(rand_generator);
}

void loop()
{
    // Read a string of max. 20 characters from a terminal.
    uint8_t message[MSG_SIZE] = "Hi!";
    Serial.printf("Enter a message: ");
    get_message((char*)message, sizeof(message));
    Serial.printf("Message: %s\n", (char *)message);

    // Generate a random AES256 key.
    const uint8_t *key = aes256_init_key(NULL);
    Serial.print("AES Key: ");
    print_data((uint8_t *)key, AES_KEY_SIZE);

    // Encrypt the string and print the ciphers to the terminal.
    uint8_t cipher[AES_CIPHER_SIZE] = {0};
    //(void)aes256_encrypt(message, sizeof(message), cipher);
    (void)aes256_encrypt(message, strlen((char*)message), cipher);
    Serial.print("Cipher: ");
    print_data(cipher, AES_CIPHER_SIZE);

    // Decrypt the ciphers and print them to the terminal
    memset(message, 0, sizeof(message));
    (void)aes256_decrypt(cipher, message);
    Serial.printf("Message: %s\n", (char *)message);

    Serial.println();
}




