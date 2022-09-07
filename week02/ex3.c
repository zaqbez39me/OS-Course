#include "stdio.h"

_Bool in_range(int x, int from, int to){
    return from <= x && x <= to ? 1 : 0;
}

void rec_convert(long long int x, unsigned int to){
    if (x == 0)
        return;
    rec_convert(x / to, to);
    fprintf(stdout, "%lli", x % to);
}

void convert(long long int x, unsigned int from, unsigned int to){
    if (!in_range(from, 2, 10) || !in_range(to, 2, 10)) {
        fprintf(stdout,"cannot convert!");
        return;
    }
    long long int x_copy = x;
    while(x_copy > 0){
        if (!in_range(x_copy % 10, 0, from - 1)) {
            fprintf(stdout,"cannot convert!");
            return;
        }
        x_copy /= 10;
    }
    if(from == to) {
        fprintf(stdout, "%lli", x);
        return;
    }
    x_copy = x;
    long long digit = 1;
    long long int in_system = 0;
    while(x_copy){
        in_system += (x_copy % 10) * digit;
        digit *= from;
        x_copy /= 10;
    }
    rec_convert(in_system, to);
}

int main(){
    long long int number = 0;
    unsigned int source, target;
    printf("Write your number: ");
    scanf("%lli", &number);
    printf("Write your source system: ");
    scanf("%ui", &source);
    printf("Write your target system: ");
    scanf("%ui", &target);
    convert(number, source, target);
}