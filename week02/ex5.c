#include "stdio.h"

long long int tribonacci(unsigned short int x){
    long long int x1 = 0, x2 = 1, x3 = 1, cur = 0;
    for(int i = 0; i <= x; ++i){
        if (i > 1) {
            if (i == 2)
                cur = 1;
            else {
                cur = x1 + x2 + x3;
                x1 = x2;
                x2 = x3;
                x3 = cur;
            }
        }
    }
    return cur;
}

int main(){
    fprintf(stdout,"For argument 4: %lli\n", tribonacci(4));
    fprintf(stdout,"For argument 36: %lli\n", tribonacci(36));
}