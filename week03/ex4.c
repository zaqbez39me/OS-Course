#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int *res = malloc(sizeof(int));
    *res = (int) *((const int*) a) + *((const int*) b);
    return res;
}

void* addDouble(const void* a, const void* b){
    double *res = malloc(sizeof(double));
    *res = (double) *((const double*) a) + *((const double*) b);
    return res;
}

void* mulInt(const void* a, const void* b){
    int *res = malloc(sizeof(int));
    *res = (int) *((const int*) a) * *((const int*) b);
    return res;
}

void* mulDouble(const void* a, const void* b){
    double *res = malloc(sizeof(double));
    *res = (double) *((const double*) a) * *((const double*) b);
    return res;
}

void* meanInt(const void* a, const void* b){
    int *res = malloc(sizeof(int));
    *res = (int) *((const int*) a) + *((const int*) b);
    return res;
}

void* meanDouble(const void* a, const void* b){
    double *res = malloc(sizeof(double));
    *res = (double) *((const double*) a) + *((const double*) b);
    return res;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){
    if (size==sizeof(int)){ // base is a pointer to an integer
        int *output = malloc(sizeof(int));
        *output = *((int*)initial_value);
        for(int i = 0; i < n; ++i) {
            int *temp = (int *) opr(output, (int *) base + i);
            *output = *temp;
            free(temp);
        }
        if(opr == meanInt)
            *output = *((int*)output) / n;
        return output;
    }
    else{ // base is a pointer to a a double
        double *output = malloc(sizeof(double));
        *output = *((double*)initial_value);
        for(int i = 0; i < n; ++i) {
            double *temp = (double *) opr(output, (double*) base + i);
            *output = *temp;
            free(temp);
        }
        if(opr == meanDouble)
            *output = *((double*)output) / n;
        return output;
    }
}




int main(){
    int* ints = malloc(sizeof(int)*5);
    double* doubles = malloc(sizeof(double)*5);

    int n = 5;
    for(int i = 0; i < n; ++i)
        doubles[i] = ints[i] = 5;

    int* p1 = malloc(sizeof (int)), *p2 = malloc(sizeof(int));
    double *p3 = malloc(sizeof(double));
    *p1 = 0, *p2 = 1, *p3 = 1.0f;


    // Summation

    int* result1a;
    result1a = (int*) aggregate(ints, sizeof(int), n, p1, addInt);

    printf("%d\n", *result1a);

    double* result2a;

    result2a = (double*) aggregate(doubles, sizeof(double), n, p1, addDouble);

    printf("%f\n", *result2a);


    // Multiplication

    int* result1m;

    result1m = (int*) aggregate(ints, sizeof(int), n, p2, mulInt);

    printf("%d\n", *result1m);

    double* result2m;

    result2m = (double*)aggregate(doubles, sizeof(double), n, p3, mulDouble);

    printf("%f\n", *result2m);



    // Mean

    int* result1mean;

    result1mean = (int*) aggregate(ints, sizeof(int), n, p1, meanInt);

    printf("%d\n", *result1mean);

    double* result2mean;

    result2mean = (double*)aggregate(doubles, sizeof(double), n, p1, meanDouble);

    printf("%f\n", *result2mean);

    free(ints);
    free(doubles);
    free(p1);
    free(p2);
    free(p3);
    free(result1a);
    free(result2a);
    free(result1m);
    free(result2m);
    free(result1mean);
    free(result2mean);

    return EXIT_SUCCESS;
}
