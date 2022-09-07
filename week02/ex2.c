#include "stdio.h"
#include "string.h"

#define END_SYM '.'

unsigned int get_end(char *x){
    int i, x_length = strlen(x) - 1;
    if (x_length == 0)
        return -1;
    for(i = 0; i < x_length; ++i){
        if(*(x + i) == END_SYM)
            return i - 1;
    }
    return i - 1;
}

void print_reversed(char *x, int length){
    putchar('\"');
    for(int i = length; i >= 0; --i){
        putchar(*(x + i));
    }
    putchar('\"');
}

int main(){
    char str[256];
    fgets(str, 256, stdin);
    print_reversed(str, get_end(str));
}