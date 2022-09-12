#include "stdio.h"
#include "string.h"

#define END_SYM '.'

unsigned int get_end(char *x){
    int i, x_length = strlen(x);
    if (x_length == 0)
        return -1;
    for(i = 0; i < x_length; ++i){
        if(*(x + i) == END_SYM)
            return i;
    }
    return i - 1;
}

void print_reversed(char *x, int length){
    fputc('\"', stdout);
    for(int i = length - 1; i >= 0; --i){
        fputc(*(x + i), stdout);
    }
    fputc('\"', stdout);
}

int main(){
    char str[256];
    fgets(str, 256, stdin);
    print_reversed(str, get_end(str));
}