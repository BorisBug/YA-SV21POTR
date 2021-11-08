/**
 * @file exercise-33.c
 * @author Boris Snäll (borissnaell@gmail.com)
 * @brief Exercise 33
 * @version 0.1
 * @date 2021-10-25
 */

#include <stdio.h>
#include <stdint.h>

/*
Beskrivning
Read about the hanoi tower puzzle and solve it for 64 disks.
https://romek.info/games/hanoi3e.html

Make a program to find how many years it takes to move 64 disks
from a peg to another one if each move takes 1 second.
*/

#define PRINT_LOG 1

#if PRINT_LOG
#define LOG(fmt,n,from,to)  printf((fmt), (n), (from), (to))
#else
#define LOG(fmt,n,from,to)  {;}
#endif

void tower(int n, char from, char to, char aux, uint64_t *counter)
{
    *counter = (*counter) + 1;

    if (n == 1)
    {
        LOG("Move disk %d from %c to %c\n", n, from, to);
    }
    else
    {
        tower(n - 1, from, aux, to, counter);
        LOG("Move disk %d from %c to %c\n", n, from, to);
        tower(n - 1, aux, to, from, counter);
    }
}

int main()
{
    int n = 4; // amount of disks
    uint64_t counter = 0;
    tower(n, 'A', 'C', 'B', &counter); // A, B and C are names of rods
    printf("Iterations: %llu\n", counter);

    // what a surprise!
    // 8 = 255 (UINT8_MAX)
    // 16 = 65535 (UINT16_MAX)
    // then for n = 64 iterations should be UINT64_MAX

    /* From google...
    If you had 64 golden disks you would have to use a minimum of 2^64-1 moves.
    If each move took one second, it would take around 585 billion years to complete the puzzle!
    https://www.mathscareers.org.uk/tower-of-hanoi/
    */

    // it = iterations
    uint64_t it = UINT64_MAX; // seconds
    printf("Hanoi towers with 64 disks will take %llu seconds to solve\n", it);
    it /= 60; // seconds->minutes
    printf("Hanoi towers with 64 disks will take %llu minutes to solve\n", it);
    it /= 60; // minutes->hours
    printf("Hanoi towers with 64 disks will take %llu hours to solve\n", it);
    it /= 24; // hours->days
    printf("Hanoi towers with 64 disks will take %llu days to solve\n", it);
    uint64_t m = it/30; // days->months
    printf("Hanoi towers with 64 disks will take %llu months to solve\n", m);
    uint64_t y = m/12; // days->months
    printf("Hanoi towers with 64 disks will take %llu years to solve\n", y);
    it /= 365; // days->years
    printf("Hanoi towers with 64 disks will take %llu years to solve (v2)\n", it);

    return 0;
}