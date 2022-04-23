#include <Arduino.h>
#include <ctype.h>
#include <string.h>
#include "SHA256.h"

#define MSG_SIZE 64

void setup()
{
    Serial.begin(9600);
    while(!Serial)
    {
        delay(100);
    }
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

void loop()
{
    char msg[MSG_SIZE];
    uint8_t hash[HASH_SIZE];

    Serial.printf("Enter a message: ");
    get_message(msg, MSG_SIZE);
    Serial.printf("The message is: %s\n", msg);

    sha256((uint8_t*)msg, strlen(msg), hash);
    Serial.printf("The hash is: ");
    print_data(hash, HASH_SIZE);

    Serial.println();
}
