# Teensy 3.5 and RTC & Serial

## Requirements

    1. It shall be possible to have a menu system to set and get date and time of the RTC.

    2. The date and time format shall be YYYY-MM-DD hh:mm:ss
    
    3. The menu system shall have an option to get date and time from the user via a terminal
    
    4. It shall be possible to initialize the RTC with the gotten date and time from the user.
    
    5. The menu system shall have an option to get the current date and time form the RTC and display it for the user.

## Development

    1. Make a repository, real-time-clock, on Github. Initialize it with README.md.
    
    2. Invite your teammate as a collaborator.
    
    3. Make a project for your repository. Use Automated kanban with review as the tepmlate.
    
    4. Create a milestone, Sprint 1, for the project. Set the due date to 2020-12-02.

    5. Make the issues for the project.

    6. Use Github Flow strategy.

    7. Push frequently.

### RTC Functions (include TimeLib.h)

RTC(Readl-time Clock) is a unit which is used to keep track of date and time.
To get date and time of the RTC in Arduino, you can use year(), month(), day(), hour(), minute() and second() functions.
To set date and time of the RTC in Arduino, you can use setTime function.

### Serial communication to the terminal

To communicate with the user, usb serial shall be used. In Arduino there is an object, Serial, which has different functions in order to send and recieve data to/from the terminal. Serial.avaiable, Serial.printf, Serial.print, Serial.println, Serial.write and Serial.read are some of those useful functions which can be used to implement the project.
