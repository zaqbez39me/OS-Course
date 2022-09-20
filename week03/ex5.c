#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef void* (*oper)(const void*, const void*);

void* vaggregate(void* base, size_t size, int n, void* initial_value,
                 int number, ...);

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

// Vaggreagate function that applies n functions to the initial array
void* vaggregate(void* base, size_t size, int n, void* initial_value,
                 int number, ...){
    va_list args;
    void *output = malloc(size);

    va_start(args, number);

    for(int j = 0; j < number; j++) {
        if (size == sizeof(int)) { // base is a pointer to an integer
            oper a = (va_arg(args, oper));
            if(j == 0)
                *((int*) output) = *((int *) initial_value);
            for (int i = 0; i < n; ++i) {
                int *temp = (int *) a(output, (int *) base + i);
                *((int*)output) = *temp;
                free(temp);
            }
            if (a == meanInt)
                *((int*)output) = *((int *) output) / n;
        } else { // base is a pointer to a a double
            oper a = (va_arg(args, oper));
            if(j == 0)
                *((double*)output) = *((double *) initial_value);
            for (int i = 0; i < n; ++i) {
                double *temp = (double *) a(output, (double *) base + i);
                *((double*)output) = *temp;
                free(temp);
            }
            if (a == meanDouble)
                *((double*)output) = *((double *) output) / n;
        }
    }
    va_end(args);
    return output;
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
    result1a = (int*) vaggregate(ints, sizeof(int), n, p1, 1, addInt);

    printf("%d\n", *result1a);

    double* result2a;

    result2a = (double*) vaggregate(doubles, sizeof(double), n, p1, 1, addDouble);

    printf("%f\n", *result2a);


    // Multiplication

    int* result1m;

    result1m = (int*) vaggregate(ints, sizeof(int), n, p2, 1, mulInt);

    printf("%d\n", *result1m);

    double* result2m;

    result2m = (double*)vaggregate(doubles, sizeof(double), n, p3, 1, mulDouble);

    printf("%f\n", *result2m);



    // Mean

    int* result1mean;

    result1mean = (int*) vaggregate(ints, sizeof(int), n, p1, 1, meanInt);

    printf("%d\n", *result1mean);

    double* result2mean;

    result2mean = (double*) vaggregate(doubles, sizeof(double), n, p1, 1, meanDouble);

    printf("%f\n", *result2mean);

    // Mean and then Mul starting from mean

    double* result2mean_and_mul;

    result2mean_and_mul = (double*) vaggregate(doubles, sizeof(double), n, p1, 2, meanDouble, mulDouble);

    printf("%f\n", *result2mean_and_mul);

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
    free(result2mean_and_mul);

    return EXIT_SUCCESS;
}
