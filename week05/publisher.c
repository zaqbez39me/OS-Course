#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<signal.h>

int publisher;

void handler(int signum) {
    close(publisher);
    exit(signum);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handler);
    remove("/tmp/ex1");
    unlink("/tmp/ex1");
    long int n;
    char *end;
    if(argc != 2)
        handler(EXIT_SUCCESS);
    n = strtol(argv[1], &end, 10);
    char msg[1024];
    mkfifo("/tmp/ex1", 0777);
    publisher = open("/tmp/ex1", O_RDWR);
    if(publisher == -1) handler(EXIT_FAILURE);
    while(1) {
        fgets(msg, 1024, stdin);
        for(int i = 0; i < n; ++i) {
            if (write(publisher, msg, strlen(msg) + 1) == -1)
                handler(2);
            usleep(1e6 / n);
        }
    }
    close(publisher);
    return EXIT_SUCCESS;
}
