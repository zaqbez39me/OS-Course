#include <stdio.h>
#include <stdlib.h>


int foo(int age){
    return 2022 - age;
}

int main(){
    int const x = 10;
    int const *q = &x;
    int const * const p = (int *) malloc(sizeof(int) * 5);
    int * const p_c = p; // to access protected cells
    for(int i = 0; i < 5; ++i) {
        p_c[i] = *q;
        printf("%p\n", (p + i));
    }
    for(int i = 0; i < 5; ++i) {
        fscanf(stdin, "%i", p_c + i);
    }
    for(int i = 0; i < 5; ++i){
        p_c[i] = foo(p[i]);
    }
    free(p_c);
    return EXIT_SUCCESS;
}