#include <stdio.h>
#include <string.h>
#include "unistd.h"
#include "stdlib.h"
#include "sys/resource.h"

#define SIZE (10 * 1024 * 1024)

int main() {
    char* ptr[10];
    struct rusage result;
    for(int i = 0; i < 9; ++i){
        ptr[i] = malloc(SIZE);
        memset(ptr[i], 0, SIZE);
        getrusage(RUSAGE_SELF, &result);
        printf("Memory usage: %ld kibibytes\n", result.ru_maxrss);
        sleep(1);
    }
    ptr[9] = malloc(SIZE);
    memset(ptr[9], 0, SIZE);
    getrusage(RUSAGE_SELF, &result);
    printf("Memory usage: %ld kibibytes\n", result.ru_maxrss);
    for(int i = 0; i < 10; ++i)
        free(ptr[i]);
    return EXIT_SUCCESS;
}