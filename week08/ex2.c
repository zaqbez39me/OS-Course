#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("N = ");
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i) arr[i] = i;
    for(int i = 0; i < n; ++i) printf("arr[i] = %d\n", arr[i]);
    free(arr);
    return 0;
}
