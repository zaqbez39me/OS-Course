#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <signal.h>

void handler(int signum) {
    exit(signum);
}

int main() {
    signal(SIGINT, handler);
    int fd[2];
    // fd[0] - read end
    // fd[1] - write end
    if(pipe(fd) == -1)
        return EXIT_FAILURE;
    char msg[1024];
    int id = fork();
    if (id == 0) {
        close(fd[0]);
        while(1) {
            fgets(msg, 1024, stdin);
            if (write(fd[1], msg, strlen(msg) + 1) == -1)
                return 2;
            sleep(1);
        }
    } else {
        close(fd[1]);
        while(1) {
            if (read(fd[0], msg, sizeof(msg)) == -1)
                return 2;
            printf("%s", msg);
        }
    }

    return EXIT_SUCCESS;
}