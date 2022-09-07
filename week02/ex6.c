#include "stdio.h"

void first(int n){
    int line = 0;
    int cur = 1;
    while(cur <= n){
        printf("*");
        line++;
        if(line == cur){
            line = 0;
            cur++;
            printf("\n");
        }
    }
}
void second(int n){
    int line = 0;
    int cur = 1;
    while(cur <= n){
        printf("*");
        line++;
        if(line == cur || cur > n / 2 && n - cur + 1 == line){
            line = 0;
            cur++;
            printf("\n");
        }
    }
}

void third(int n){
    int line = 0;
    int cur = 1;
    while(cur <= n){
        printf("*");
        line++;
        if(line == n){
            line = 0;
            cur++;
            printf("\n");
        }
    }
}

int main(){
    fprintf(stdout, "Select pattern(1-3): ");
    unsigned int pattern_num;
    scanf("%ui", &pattern_num);
    unsigned int n;
    printf("Choose n(> 0): ");
    scanf("%ui", &n);
    switch (pattern_num) {
        case 1:
            first(n);
            break;
        case 2:
            second(n);
            break;
        case 3:
            third(n);
            break;
        default:
            printf("No such pattern!");
    }
}