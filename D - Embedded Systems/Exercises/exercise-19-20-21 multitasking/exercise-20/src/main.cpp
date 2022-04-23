/**
 * @brief Multithreading using TeensyThreads.
 * In this example, 3 threads are synchornized in a way that the threads print 1, 2 and 3 in order.
 * @date 2020-11-23
 */

#include <Arduino.h>
#include <TeensyThreads.h>

#define ONE (1U)
#define TWO (2U)
#define THREE (3U)

static Threads::Mutex mutex;
static volatile uint8_t number = ONE;

static void print_one(void)
{
    while (1)
    {
        threads.delay(500); // This function makes a context switch

        mutex.lock(); // Acquires the mutex
        while (number != ONE)
        {
            // These 3 lines of code are equivalent to wait in condition variables
            mutex.unlock();
            threads.yield(); // This function is used to suspend the task and pass the control to a waiting thread. A context switch occures.
            mutex.lock();
        }

        Serial.print("1 - ");
        number = TWO;

        mutex.unlock();  // Releases the mutex
        threads.yield(); // A context switch occures.
    }
}

static void print_two(void)
{
    while (1)
    {
        mutex.lock();
        while (number != TWO)
        {
            mutex.unlock();
            threads.yield();
            mutex.lock();
        }

        Serial.print("2 - ");
        number = THREE;

        mutex.unlock();
        threads.yield();
    }
}

static void print_three(void)
{
    while (1)
    {
        mutex.lock();
        while (number != THREE)
        {
            mutex.unlock();
            threads.yield();
            mutex.lock();
        }

        Serial.println(THREE);
        number = ONE;

        mutex.unlock();
        threads.yield();
    }
}

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);

    Serial.begin(9600);
    while (!Serial)
    {
    }

    // Creating the threads
    threads.addThread(print_one);
    threads.addThread(print_two);
    threads.addThread(print_three);
}

void loop()
{
    digitalWrite(LED_BUILTIN, LOW);
    threads.delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
    threads.delay(500);
}
