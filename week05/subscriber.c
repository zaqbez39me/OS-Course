#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <signal.h>
#include <stdlib.h>

int subscriber;

void handler(int signum) {
    close(subscriber);
    exit(signum);
}

int main() {
    signal(SIGINT, handler);
    char msg[1024];
    subscriber = open("/tmp/ex1", O_RDONLY);
    if(subscriber == -1) return 1;
    while(1){
        if(read(subscriber, msg, sizeof(msg)) == -1) return 2;
        printf("%s", msg);
    }
}