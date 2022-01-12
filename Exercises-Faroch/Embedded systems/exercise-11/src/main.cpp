/**
 * @file main.cpp
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief Make a secret code program according to the requirements below:
 *          1. The program shall ask the user to start a new game
 *          2. If the user presses any key then a new game shall start.
 *          3. The program shall generate a random positive num in the range of CODE_MIN and CODE_MAX as the secret code.
 *          4. The program shall generate shall turn the builtin LED on.
 *          5. The program shall ask max. MAX_ATTEMPTS times the user to guess the secret code.
 *          6. If the user enters a wrong code, the program shall print a message to the terminal to indicate the entered code is wrong.
 *          7. If the user guesses the secret code within MAX_ATTEMPTS attempts, the program shall print a message to the terminal and turn the LED off.
 *          8. Else the program shall print a message consist of the secret code  to the terminal to indicate that the user couldn't guess the secret code.
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

void setup()
{
}

void loop()
{
}