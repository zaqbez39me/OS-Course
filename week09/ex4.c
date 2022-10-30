#include <stdio.h>
#include "unistd.h"
#include "string.h"
#include "stdlib.h"
#include "sys/resource.h"

#define SIZE (10 * 1024 * 1024)

int main() {
    int* ptr;
    struct rusage result;
    for(int i = 0; i < 9; ++i){
        ptr = malloc(SIZE);
        memset(ptr, 0, SIZE);
        getrusage(RUSAGE_SELF, &result);
        printf("Memory usage: %ld KB\n",result.ru_maxrss);
        sleep(1);
    }
    ptr = malloc(SIZE);
    memset(ptr, 0, SIZE);
    getrusage(RUSAGE_SELF, &result);
    printf("Memory usage: %ld KB\n",result.ru_maxrss);
    return EXIT_SUCCESS;
}