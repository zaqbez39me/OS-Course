#include "stdio.h"

void qsort_rec(int *arr, int begin, int end){
    int l = begin, r = end;
    int v = arr[(l + r - 1) / 2];
    while(l <= r){
        while(arr[l] <= v) ++l;
        while(arr[r] >= v) --r;
        if(l <= r){
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            ++l, --r;
        }
    }
    if(l < end)
        qsort_rec(arr, l, end);
    if(r > begin)
        qsort_rec(arr, begin, r);
}

void qsort(int *arr, int n){
    qsort_rec(arr, 0, n);
}

int main(){
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    printf("Preforming sort...\n");
    qsort(arr, n);
    printf("Sorted array:\n");
    for(int i = 0; i < n; ++i)
       printf("%d ", arr[i]);

}