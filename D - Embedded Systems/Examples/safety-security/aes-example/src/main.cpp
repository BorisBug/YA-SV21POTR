#include "AES256.h"
#include <Arduino.h>

static void print_data(uint8_t *data, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    Serial.printf("%02X ", data[i]);
  }

  Serial.println();
}

static uint8_t randfunc(void)
{
  return (uint8_t)random(0xFF);
}

void setup()
{
  Serial.begin(9600);
  delay(2000);

  aes256_init(randfunc);
}

void loop()
{
  const uint8_t *key = aes256_init_key(NULL);

  Serial.print("\nAES Key: ");
  print_data((uint8_t *)key, AES_KEY_SIZE);

  uint8_t message[] = "Hello World!";
  Serial.printf("Message: %s\n", (char *)message);

  uint8_t cipher[AES_CIPHER_SIZE] = {0};

  (void)aes256_encrypt(message, sizeof(message), cipher);

  Serial.print("Cipher: ");
  print_data(cipher, AES_CIPHER_SIZE);

  memset(message, 0, sizeof(message));
  (void)aes256_decrypt(cipher, message);
  Serial.printf("Message: %s\n", (char *)message);

  delay(1000);
}