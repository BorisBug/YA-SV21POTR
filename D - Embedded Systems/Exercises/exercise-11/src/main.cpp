/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a secret code program according to the requirements below:
 *          1. The program shall ask the user to start a new game
 *          2. If the user presses any key then a new game shall start.
 *          3. The program shall generate a random positive number in the range of CODE_MIN and CODE_MAX as the secret code.
 *          4. The program shall turn the builtin LED on.
 *          5. The program shall ask max. MAX_ATTEMPTS times the user to guess the secret code.
 *          6. If the user enters a wrong code, the program shall print a message to the terminal to indicate the entered code is wrong.
 *          7. If the user guesses the secret code within MAX_ATTEMPTS attempts, the program shall print a message to the terminal and turn the LED off.
 *          8. Else the program shall print a message consist of the secret code to the terminal to indicate that the user couldn't guess the secret code.
 *       To learn using Serial, look at https://www.arduino.cc/reference/en/language/functions/communication/serial/
 *       Look at the example output.
 * @version 0.1
 * @date 2022-01-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <Arduino.h>

#define CODE_MIN 100
#define CODE_MAX 105
#define MAX_ATTEMPTS 5

#define STRINGIFY(x) (#x)
#define LENGTH(x) (sizeof(STRINGIFY(x)) - 1)

static uint32_t gen_secret_code(void)
{
    randomSeed(micros());

    return random(CODE_MIN, CODE_MAX);
}

static uint32_t get_user_code(void)
{
    uint8_t i = 0;
    uint32_t code = 0;

    while (i < LENGTH(CODE_MAX))
    {
        if (0 < Serial.available())
        {
            char chr = Serial.read();

            if (chr == '\n')
            {
                break;
            }
            else if (isdigit(chr))
            {
                code = 10 * code + (chr - '0');
                Serial.print(chr);
                i++;
            }
        }
    }

    Serial.clear();

    return code;
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);
    while (!Serial)
    {
        ;
    }
}

void loop()
{
    Serial.print("\nPress any key to start a new game...");

    // Wait on the user to press a key
    while (0 == Serial.available())
    {
        ;
    }

    Serial.clear(); // Clear the input buffer

    uint8_t attempts = 0;
    uint32_t secret_code = gen_secret_code();

    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("\n\nThe secret code was generated...");

    while (attempts < MAX_ATTEMPTS)
    {
        Serial.print("\nEnter the secret code: ");

        if (secret_code == get_user_code())
        {
            Serial.printf("\nGreat job! You guessed the secret code in %d attempts.\n", attempts + 1);
            digitalWrite(LED_BUILTIN, LOW);
            break;
        }
        else
        {
            Serial.println("\nThe entered code is wrong...");
        }

        attempts++;
    }

    if (attempts == MAX_ATTEMPTS)
    {
        Serial.printf("\nFailed to guess it. The secret code is %d\n\n", secret_code);
    }
}