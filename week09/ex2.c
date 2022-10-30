#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "stdlib.h"

#define SIZE (10 * 1024 * 1024)

int main() {
    int* ptr;
    for(int i = 0; i < 9; ++i){
        ptr = malloc(SIZE);
        memset(ptr, 0, SIZE);
        sleep(1);
    }
    ptr = malloc(SIZE);
    memset(ptr, 0, SIZE);
    return EXIT_SUCCESS;
}