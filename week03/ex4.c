
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
    void *output;
    if (size==sizeof(int)){ // base is a pointer to an integer
        *((int*)output) = *((int*)initial_value);
        for(int i = 0; i < n; ++i)
            *((int *) output) = *((int *) opr(output, (int*)base + i));
        if(opr == meanInt)
            *((int*)output) = *((int*)output) / n;
        return (int*) output;
    }else{ // base is a pointer toa a double
        double *output = malloc(sizeof(double));
        *((double*)output) = *((double*)initial_value);
        for(int i = 0; i < n; ++i) {
            *((double *) output) = *((double *) opr(output, (double *) base + i));
        }
        if(opr == meanDouble)
            *((double*)output) = *((double*)output) / n;
        return (double*) output;
    }
    return output;
}




int main(){
    int* ints = malloc(sizeof(int)*5);
    double* doubles = malloc(sizeof(double)*5);
    int n = 5, addAndMeanInit = 0, mulInitI = 1;
    int* p1 = malloc(sizeof (int)), *p2 = malloc(sizeof(int));
    double *p3 = malloc(sizeof(double));
    *p1 = addAndMeanInit, *p2 = mulInitI, *p3 = mulInitI;
    for(int i = 0; i < n; ++i)
        ints[i] = doubles[i] = 5;

    int* result1a = malloc(sizeof (int));
    *result1a = *((int*) aggregate(ints, sizeof(int), n, p1, addInt));

    printf("%d\n", *result1a);

    double* result2a = malloc(sizeof (double));

    *result2a = *((double*) aggregate(doubles, sizeof(double), n, p1, addDouble));

    printf("%f\n", *result2a);


    // Multiplication

    int* result1m = malloc(sizeof (int));

    *result1m = *((int*) aggregate(ints, sizeof(int), n, p2, mulInt));

    printf("%d\n", *result1m);

    double* result2m = malloc(sizeof (double));

    *result2m = *((double*)aggregate(doubles, sizeof(double), n, p3, mulDouble));

    printf("%f\n", *result2m);



    // Mean

    int* result1mean = malloc(sizeof (int));

    *result1mean = *((int*) aggregate(ints, sizeof(int), n, p1, meanInt));

    printf("%d\n", *result1mean);

    double* result2mean = malloc(sizeof (double));

    *result2mean = *((double*)aggregate(doubles, sizeof(double), n, p1, addDouble));

    printf("%f\n", *result2mean);



    return EXIT_SUCCESS;
}
