#include <Arduino.h>
#include <TimeLib.h>

#define DT_LENGTH 19U

typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} datetime_t;

/**
 * @brief This function is used to display the menu on the terminal.
 *        The menu has two options. One for setting date and time of
 *        the RTC and the onther one for getting the current date and
 *        time of the RTC and display it on the terminal.
 *
 */
static void display_menu(void)
{
    Serial.println("S) Set datetime");
    Serial.println("G) Get datetime");
    Serial.print("Enter the command: ");
}

/**
 * @brief This function is used to read the command from the user.
 *        The commands can be 'S' for setting date and time of the RTC,
 *        'G' for getting the current date and time of the RTC and display it or
 *        a new line for printing a new line and displaying the menu.
 *
 * @return The command can be 'S', 'G' or new line.
 */
static char read_command(void)
{
    char command = 0;

    while ((command != 'S') && (command != 'G') && (command != '\n'))
    {
        if (Serial.available())
        {
            command = toupper(Serial.read());
        }
    }
    Serial.printf("%c\n\n", command);

    return command;
}

/**
 * @brief This function is used to read date and time in the fromat of YYYY-MM-DD hh:mm:ss
 *        from the user and format it in the structure of datetime_t and return it.
 *
 * @return datetime_t The formated date and time in the structure of datetime_t.
 */
static datetime_t read_datetime(void)
{
    Serial.clear();
    Serial.printf("Enter the current datetime (YYYY-MM-DD HH:MM:SS): ");

    uint8_t i = 0;
    char text[DT_LENGTH + 1] = {0};

    while (i < DT_LENGTH)
    {
        if (Serial.available())
        {
            char temp = Serial.read();
            if (temp == '\n')
            {
                break;
            }
            else if (isdigit(temp) || isspace(temp) || (temp == '-') || (temp == ':'))
            {
                Serial.print(temp);
                text[i] = temp;
                i++;
            }
        }
    }
    Serial.println();

    datetime_t datetime = {0};

    sscanf(text, "%04d-%02d-%02d %02d:%02d:%02d",
           &datetime.year, &datetime.month, &datetime.day,
           &datetime.hour, &datetime.minute, &datetime.second);

    return datetime;
}

/**
 * @brief This function is used to set date and time of the RTC.
 *        To set date and time of the RTC you can use the setTime function.
 *
 * @param datetime The structured date and time which is used to initialize the RTC.
 */
static void set_datetime(datetime_t datetime)
{
    setTime(datetime.hour, datetime.minute, datetime.second, datetime.day, datetime.month, datetime.year);
}

/**
 * @brief This function is used to get the current date and time of the RTC and display it for the user.
 *        To get the current date and time of the RTC, you can use the year, month, day, hour, minute and second functions.
 *        The displayed date and time shall be in the formate of YYYY-MM-DD hh:mm:ss.
 *
 */
static void get_current_datetime(void)
{
    Serial.print("Current datetime: ");
    Serial.printf("%04d-%02d-%02d %02d:%02d:%02d\n\n", year(), month(), day(), hour(), minute(), second());
}

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        ;
    }
}

void loop()
{
    display_menu();

    char command = read_command();

    if (command == 'S')
    {
        datetime_t temp = read_datetime(); // Get date and time from the user
        set_datetime(temp);                // Set the RTC
    }
    else if (command == 'G')
    {
        get_current_datetime(); // Get the current date and time of the RTC and Display it for the user
    }
    else if (command == '\n')
    {
        Serial.println();
    }
}
