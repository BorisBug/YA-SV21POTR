#ifndef DATETIME_H
#define DATETIME_H

#include <stdbool.h>

#define TIME_FORMAT "hh:mm:ss"
#define DATE_FORMAT "YYYY-MM-DD"
#define DATETIME_FORMAT "YYYY-MM-DD hh:mm:ss"

/**
 * @brief This function is used to validate date, time and datetime.
 *        The date time format is YYYY-MM-DD hh:mm:ss.
 *
 * @param dtstr The date, time or datetime string to validate
 * @return bool true if dtstr is valid; otherwise false
 */
bool validate_datetime(const char *dtstr);

#endif /* DATETIME_H */
