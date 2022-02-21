#include "RSA.h"
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

  rsa_init(randfunc);
}

void loop()
{
  uint8_t public_key[RSA_SIZE] = {0};
  uint8_t private_key[RSA_SIZE] = {0};

  (void)rsa_generate_keys(public_key, private_key);

  Serial.print("\nPublic Key: ");
  print_data(public_key, sizeof(public_key));

  Serial.print("Private Key: ");
  print_data(private_key, sizeof(private_key));

  uint8_t message[RSA_SIZE] = "Hello World!";
  Serial.printf("Message: %s\n", (char *)message);

  uint8_t cipher[RSA_SIZE] = {0};
  (void)rsa_public_encrypt(message, strlen((char *)message), public_key, cipher);

  Serial.print("Cipher: ");
  print_data(cipher, sizeof(cipher));

  memset(message, 0, sizeof(message));
  (void)rsa_private_decrypt(cipher, public_key, private_key, message);

  Serial.printf("Message: %s\n", (char *)message);
}