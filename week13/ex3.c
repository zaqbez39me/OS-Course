#include <linux/input.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int file_descriptor;
_Bool P, E, C, A, T;
FILE *output;

void handler(int signum) {
    close(file_descriptor);
    fclose(output);
    exit(signum);
}

void change_state(__u16 code, _Bool status){
    switch (code) {
        case KEY_P:
            P = status;
            break;
        case KEY_E:
            E = status;
            break;
        case KEY_C:
            C = status;
            break;
        case KEY_A:
            A = status;
            break;
        case KEY_T:
            T = status;
            break;
        default:
            return;
    }
}

int main(){
    file_descriptor =  open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    output = fopen("ex3.txt", "w");
    struct input_event event;
    P = E = C = A = T = 0;
    short pressed_num = 0;
    _Bool first_key = 1;
    signal(SIGINT, handler);
    setvbuf(output, NULL, _IONBF, 0);
    fprintf(stdout, "Available Shortcuts:\nP + E = print \"I passed the Exam!\"\n"
                    "C + A + P = print \"Get some cappuccino!\"\n"
                    "P + T (custom shortcut) = print \"This is the custom message!\"\n");
    while(1) {
        read(file_descriptor, &event, sizeof(event));
        if(event.type == EV_KEY) {
            if(event.value == 1) {
                if(first_key){
                    pressed_num = 1;
                    first_key = 0;
                } else ++pressed_num;
                change_state(event.code, 1);
            }
            else if(event.value == 0) {
                --pressed_num;
                change_state(event.code, 0);
            }
            if(pressed_num == 2 && P && E) {
                fprintf(output, "I passed the Exam!\n");
            } else if(pressed_num == 3 && C && A && P){
                fprintf(output, "Get some cappuccino!\n");
            } else if(pressed_num == 2 && P && T) {
                fprintf(output, "This is the custom message!\n");
            }
        }
    }
    return EXIT_SUCCESS;
}