#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;
int counter = 0;

sem_t mutex, empty, full;

void* producer(void* arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        item = i;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        printf("Producer produced item: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        counter++;
        sem_post(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;
    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        printf("Consumer consumed item: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        counter--;
        sem_post(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
