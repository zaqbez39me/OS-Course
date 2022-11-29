#include <linux/input.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int file_descriptor;
FILE *output;

void handler(int signum) {
    close(file_descriptor);
    fclose(output);
    exit(signum);
}

int main(){
    file_descriptor =  open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    output = fopen("ex2.txt", "w");
    struct input_event event;
    signal(SIGINT, handler);
    setvbuf(output, NULL, _IONBF, 0);

    while(1) {
        read(file_descriptor, &event, sizeof(event));
        if(event.type == EV_KEY) {
            if(event.value == 1)
                fprintf(output, "PRESSED: %04X (%hu)\n", event.code,event.code);
            else if(event.value == 0)
                fprintf(output, "RELEASED: %04X (%hu)\n", event.code,event.code);
        }
    }
    return EXIT_SUCCESS;
}