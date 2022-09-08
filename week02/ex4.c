#include "stdio.h"
#include "string.h"

#define len 256

char from_capital(char x){
    if(65 <= x && 90 >= x)
        x += 32;
    return x;
}

unsigned short int count(char str[], char x){
    int number = 0;
    for(int i = 0; i < strlen(str); ++i)
        if(from_capital(x) == from_capital(str[i]))
            ++number;
    return number;
}

void countAll(char str[]){
    char temp;
    for(int i = 0; i < strlen(str) - 2; ++i) {
        temp = from_capital(str[i]);
        fprintf(stdout, "%c:%hu, ", temp, count(str, temp));
    }
    temp = from_capital(str[strlen(str) - 2]);
    fprintf(stdout, "%c:%hu", temp, count(str, temp));
}

int main(){
    char str[len];
    fgets(str, len, stdin);
    countAll(str);
}