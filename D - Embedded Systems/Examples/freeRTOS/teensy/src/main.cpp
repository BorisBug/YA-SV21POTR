#include <Arduino.h>

/**
 * ******************************* NOTICE ***********************************
 *
 * To use FreeRTOS on Teensy you need to change the prototype of 2 functions(systick_isr and pendablesrvreq_isr) in kinetis.h
 * You need to append __attribute__((weak)) to the prototypes. I.e. they shall be like:
 * 	   __attribute__((weak)) extern void pendablesrvreq_isr(void);
 *     __attribute__((weak)) extern void systick_isr(void);
 */
#include <FreeRTOS_ARM.h>

#define DELAY (500U)

static SemaphoreHandle_t ping_sem, pong_sem; // Declare the semaphore handles.

// The thread function for printing Ping.
static void print_ping(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        // Sleep for 500 milliseconds.
        vTaskDelay(DELAY / portTICK_PERIOD_MS);

        xSemaphoreTake(ping_sem, portMAX_DELAY); // Wait for signal from print_pong.
        Serial.print("Ping - ");
        Serial.flush();
        xSemaphoreGive(pong_sem); // Signal print_pong to print Pong.
    }
}

// The thread function for printing Pong.
static void print_pong(void *pvParameters)
{
    (void)pvParameters;

    while (1)
    {
        xSemaphoreTake(pong_sem, portMAX_DELAY); // Wait for signal from print_pong.
        Serial.println("Pong");
        Serial.flush();
        xSemaphoreGive(ping_sem); // Signal print_ping to print Pong.
    }
}

// The thread function to toggle the LED every exact 500ms.
// Instead of vTaskDelay, we have to use vTaskDelayUntil.
static void blinking(void *pvParameters)
{
    (void)pvParameters;

    pinMode(LED_BUILTIN, OUTPUT);

    TickType_t xLastWakeTime = xTaskGetTickCount(); // Initialise the xLastWakeTime variable with the current time.

    while (1)
    {
        // Wait for the next cycle.
        vTaskDelayUntil(&xLastWakeTime, DELAY / portTICK_PERIOD_MS);

        // Toggle the LED.
        digitalWrite(LED_BUILTIN, (LOW == digitalRead(LED_BUILTIN)) ? HIGH : LOW);
    }
}

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        ;
    }

    // Initialize the binary semaphores
    ping_sem = xSemaphoreCreateCounting(1, 1);
    pong_sem = xSemaphoreCreateCounting(1, 0);

    // Create the print_ping task at priority one
    BaseType_t ping_task = xTaskCreate(print_ping, "Ping", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Create the print_pong task at priority one
    BaseType_t pong_task = xTaskCreate(print_pong, "Pong", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

    // Create the blinking task at priority two
    BaseType_t blink_task = xTaskCreate(blinking, "Blinking", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

    // Check for creation errors
    if (ping_sem == NULL || pong_sem == NULL || ping_task != pdPASS || pong_task != pdPASS || blink_task != pdPASS)
    {
        while (1)
        {
            Serial.println("Creation error!");
            vTaskDelay(2 * DELAY / portTICK_PERIOD_MS);
        }
    }

    // Start the scheduler
    vTaskStartScheduler();

    while (1)
    {
        Serial.println("Failed to start the scheduler!");
        vTaskDelay(2 * DELAY / portTICK_PERIOD_MS);
    }
}

void loop()
{
    // Not used.
}
