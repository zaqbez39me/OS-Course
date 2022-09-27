#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    clock_t t;
    t = clock();
    pid_t main_child;
    main_child = fork();
    if(main_child == 0)
        t = clock();
    else {
        main_child = fork();
        if (main_child == 0)
            t = clock();
    }
    printf("Process id is %d, process parent id is %d\n", getpid(), getppid());
    wait(NULL);
    printf("process %d full execution time is %f\n", getpid(), ((float) (clock() - t)) / CLOCKS_PER_SEC * 1000);
    return EXIT_SUCCESS;
}