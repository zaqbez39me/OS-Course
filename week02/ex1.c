#include "limits.h"
#include "stdio.h"
#include "float.h"

int main(){
    int i = INT_MAX;
    unsigned short int usi = USHRT_MAX;
    long int li = LONG_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    fprintf(stdout, "SIZES:\nINT = %lu\nUNSIGNED SHORT INT = %lu\nLONG_INT = %lu\nFLOAT = %lu\n DOUBLE = %lu\n",
           sizeof(i), sizeof(usi), sizeof(li), sizeof(f), sizeof(d));
    fprintf(stdout, "VALUES:\nINT = %d\nUNSIGNED SHORT INT = %hu\nLONG_INT = %ld\nFLOAT = %f\n DOUBLE = %lf",
           i, usi, li, f, d);
}