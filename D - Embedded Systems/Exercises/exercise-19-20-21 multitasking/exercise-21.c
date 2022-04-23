#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define LOOP_NUM 10
#define STORED_MAX 5

static sem_t mutex;
static sem_t sem_produced;
static sem_t sem_consumed;

static volatile uint8_t stored_count = 0;

void *producer(void *arg)
{
    (void)arg;

    for (uint8_t i = 0; i < LOOP_NUM; i++)
    {
        if (STORED_MAX == stored_count)
        {
            printf("Storage full, producer is waiting ...\n");
        }
        sem_wait(&sem_consumed);

        sleep(1); // production rate

        sem_wait(&mutex);
        stored_count++;
        sem_post(&mutex);

        printf("Producer -> stored_count : %d\n", stored_count);
        sem_post(&sem_produced);
    }
}

void *consumer(void *arg)
{
    (void)arg;

    for (uint8_t i = 0; i < LOOP_NUM; i++)
    {
        if (0 == stored_count)
        {
            printf("Storage empty, consumer is waiting ...\n");
        }
        sem_wait(&sem_produced);

        sleep(2); // consumption rate

        sem_wait(&mutex);
        stored_count--;
        sem_post(&mutex);

        printf("Consumer -> stored_count : %d\n", stored_count);
        sem_post(&sem_consumed);
    }
}

int main(void)
{
    pthread_t cthrd, pthrd;
    sem_init(&mutex, 0, 1);                 // Binary semaphore acts like a mutex
    sem_init(&sem_produced, 0, 0);          // A semaphore for the number of available products
    sem_init(&sem_consumed, 0, STORED_MAX); // A semaphore for the number of empty places

    if (pthread_create(&cthrd, NULL, consumer, NULL))
    {
        perror("Failed to create the consumer thread!\n");
        exit(1);
    }

    if (pthread_create(&pthrd, NULL, producer, NULL))
    {
        perror("Failed to create the producer thread!\n");
        exit(1);
    }

    pthread_join(cthrd, NULL);
    pthread_join(pthrd, NULL);

    sem_destroy(&sem_consumed);
    sem_destroy(&sem_produced);
    sem_destroy(&mutex);

    return 0;
}
