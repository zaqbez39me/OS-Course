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

void convert(long long x, unsigned int from, unsigned int to){
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
    long long int digit = 1;
    if(from != 10) {
        long long int in_system = 0;
        while (x) {
            in_system += (x % 10) * digit;
            digit *= from;
            x /= 10;
        }
        rec_convert(in_system, to);
    }
    else
        rec_convert(x, to);
}

int main(){
    long long int number;
    unsigned int source, target;
    fprintf(stdout, "Write your number: ");
    fscanf(stdin, "%lli", &number);
    fprintf(stdout,  "Write your source system: ");
    fscanf(stdin, "%ui", &source);
    fprintf(stdout, "Write your target system: ");
    fscanf(stdin, "%ui", &target);
    convert(number, source, target);
}
