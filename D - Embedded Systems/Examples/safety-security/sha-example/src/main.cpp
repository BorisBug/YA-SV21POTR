#include "SHA256.h"
#include <Arduino.h>

#define MSGLEN 64

static void print_data(uint8_t *data, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    Serial.printf("%02X ", data[i]);
  }

  Serial.println();
}

void setup()
{
  Serial.begin(9600);
  delay(2000);
}

void loop()
{
  uint8_t length = random(1, MSGLEN);
  uint8_t message[MSGLEN + 1] = {0};

  for (uint8_t i = 0; i < length; i++)
  {
    message[i] = 'A' + random(26);
  }

  Serial.printf("\nMessage: %s\n", (char *)message);

  uint8_t hash[HASH_SIZE] = {0};

  sha256(message, length, hash);

  Serial.print("Hash: ");
  print_data(hash, HASH_SIZE);

  delay(1000);
}