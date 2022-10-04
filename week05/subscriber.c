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
    if(subscriber == -1) handler(EXIT_FAILURE);
    while(1){
        int code = read(subscriber, msg, sizeof(msg));
        if(code == -1) handler(2);
        if(code == 0) handler(SIGINT);
        printf("%s", msg);
    }
}