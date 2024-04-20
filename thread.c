#include <stdio.h>
#include <pthread.h>

#define SIZE 10
#define NUM_THREADS 4

int arr[SIZE] = {4, 2, 8, 5, 1, 9, 7, 3, 6, 0};
int target = 7;
int found = 0;

void* linearSearch(void* threadId) {
    long tid = (long)threadId;
    int start = tid * (SIZE / NUM_THREADS);
    int end = start + (SIZE / NUM_THREADS);
    
    for (int i = start; i < end; i++) {
        if (arr[i] == target) {
            found = 1;
            printf("Thread %ld: Found the target %d at index %d\n", tid, target, i);
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, linearSearch, (void*)i);
    }

    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    if (!found) {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}
