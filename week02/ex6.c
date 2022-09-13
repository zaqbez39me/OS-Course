#include "stdio.h"

void first(int n){
    int line = 0;
    int cur = 1;
    while(cur <= n){
        fputc('*', stdout);
        line++;
        if(line == cur){
            line = 0;
            cur++;
            fputc('\n', stdout);
        }
    }
}
void second(int n){
    int line = 0;
    int cur = 1;
    while(cur <= n){
        fputc('*', stdout);
        line++;
        if(line == cur || cur > n / 2 && n - cur + 1 == line){
            line = 0;
            cur++;
            fputc('\n', stdout);
        }
    }
}

void third(int n){
    int line = 0;
    int cur = 1;
    while(cur <= n){
        fputc('*', stdout);
        line++;
        if(line == n){
            line = 0;
            cur++;
            fputc('\n', stdout);
        }
    }
}

int main(){
    fprintf(stdout, "Choose pattern: \n"
    " 1: *      2: *    3: ******\n"
    "    **        **      ******\n"
    "    ***       ***     ******\n"
    "    ****      ****    ******\n"
    "    *****     ***     ******\n"
    "    ******    **      ******\n"
    "    *******   *       ******\n");
    unsigned int pattern_num;
    fscanf(stdin, "%ui", &pattern_num);
    unsigned int n;
    fprintf(stdout, "Enter n:\n");
    fscanf(stdin, "%ui", &n);
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
            fprintf(stdout, "No such pattern!");
    }
}