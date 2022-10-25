#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* own_realloc(void* initial, size_t new_size, size_t old_size){
    if(initial == NULL) return malloc(new_size);
    void *new;
    if(new_size == 0) {
        new = NULL;
    } else {
        new = malloc(new_size);
        size_t min = old_size < new_size ? old_size : new_size;
        memcpy(new, initial, min);
    }
    free(initial);
    return new;
}

int main() {
    int n;
    printf("Enter the length of initial array:\nN = ");
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i) arr[i] = i;
    for(int i = 0; i < n; ++i) printf("arr[i] = %d\n", arr[i]);
    int new_size;
    printf("Enter the length of initial array:\nN = ");
    scanf("%d", &new_size);
    arr = own_realloc(arr, new_size * sizeof(int), n * sizeof(int));
    for(int i = 0; i < new_size; ++i) printf("arr[i] = %d\n", arr[i]);
    free(arr);
    return 0;
}
