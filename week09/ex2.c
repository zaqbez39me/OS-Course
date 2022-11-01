#include <string.h>
#include "unistd.h"
#include "stdlib.h"

#define SIZE (10 * 1024 * 1024)

int main() {
    char* ptr[10];
    for(int i = 0; i < 9; ++i){
        ptr[i] = malloc(SIZE);
        memset(ptr[i], 0, SIZE);
        sleep(1);
    }
    ptr[9] = malloc(SIZE);
    memset(ptr[9], 0, SIZE);
    for(int i = 0; i < 10; ++i)
        free(ptr[i]);
    return EXIT_SUCCESS;
}

/* For the tests I have increased SIZE to 1.953125 GB to actually see some significant changes.
 * Exercise 2 comments:
 *  The number of swaps in and swaps out increased after execution. Moreover, the memory amount of memory being swapped
 * during the execution of ex2 increased in multiple times. That means that our physical memory has no enough memory for
 * program execution. Therefore, it has to swap the parts of memory in and out.
 * Exercise 3 comments:
 *  First of all, I have found that after the first cycle iteration ex2 becomes the top 1 of all executable
 * processes. Moreover, after 9th iteration my program exceeds the size of physical memory because it occupies
 * 17.578125 GB of virtual memory while on my computer is only 16 GB of actual RAM.
 */