#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct Thread {
    pthread_t id;
    int i;
    char message[256];
} thread;

void* thread_function(void *args) {
    thread *t = (thread*) args;
    printf("%s\n", t->message);
}


int main(){
    int n;
    scanf("%d", &n);
    thread threads[n];
    for(int i = 0; i < n; ++i){
        threads[i].i = i;
        char temp[256];
        sprintf(temp, "Hello from thread %d", i);
        strcpy(threads[i].message, temp);
        pthread_create(&threads[i].id, NULL, &thread_function, &threads[i]);
        printf("Thread %d is created\n", threads[i].id);
        pthread_join(threads[i].id, NULL);
    }
    return EXIT_SUCCESS;
}
