#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x, y;
} Point;

float distance(Point A, Point B){
    return sqrtf(powf(A.x - B.x, 2) + powf(A.y - B.y, 2));
}

float area(Point A, Point B, Point C){
    return 1.0f / 2.0f * fabsf(A.x*B.y - B.x*A.y + B.x*C.y - C.x*B.y + C.x*A.y - A.x*C.y);
}

int main(void){
    Point A, B, C;
    A.x = 2.5f;
    B.x = 1;
    C.x = 10;
    A.y = 6;
    B.y = 2.2f;
    C.y = 6;

    float f = distance(A, B);
    printf("A -- B distance is %f\n", f);


    float a = area(A, B, C);
    printf("Area of triangle ABC is %f\n", a);

    return EXIT_SUCCESS;
}