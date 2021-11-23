# Date time validation

## Requirements

Using TDD, develop a function to validate date, time and date time.

The date time format shall be YYYY-MM-DD hh:mm:ss.

For example:

validate_datetime(“23:12:36”) shall return true and validate_datetime(“40:30:90”) shall return false.

validate_datetime(“2021-10-06”) shall return true and validate_datetime(“2021-30-10”) shall return false.

validate_datetime(“2021-10-06 21:02:21”) shall return true and validate_datetime(“2021-10-10 30:30:30”) shall return false.

Compile and link unity to the test program

Make a Makefile to build and run the test.
