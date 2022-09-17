#include <stdio.h>
#include <stdlib.h>


int foo(int age){
    return 2022 - age;
}

int main(){
    int const x = 10;
    int const *q = &x;
    int * const p = (int *) malloc(sizeof(int) * 5);
    for(int i = 0; i < 5; ++i) {
        p[i] = *q;
        printf("%p\n", (p + i));
    }
    for(int i = 0; i < 5; ++i) {
        fscanf(stdin, "%i", p + i);
    }
    for(int i = 0; i < 5; ++i){
        p[i] = foo(p[i]);
    }
    free(p);
    return EXIT_SUCCESS;
}