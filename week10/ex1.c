#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MSB_ONE 0x80000000

void set_bit(unsigned int* a){
    *a |= 1 << 31;
}

void clear_bit(unsigned int* a){
    *a &= ~(1 << 31);
}

int get_min(const unsigned int *arr, const int *frames, int n) {
    int min = UINT_MAX, min_ind = -1;
    for(int i = 0; i < n; ++i) {
        if(frames[i] == -1)
            return i;
        if (min > arr[i]) {
            min_ind = i;
            min = arr[i];
        }
    }
    return min_ind;
}

int get_index(const int *arr, int n, int value){
    for(int i = 0; i < n; ++i)
        if(arr[i] == value)
            return i;
    return -1;
}

_Bool access_memory(unsigned int *values, int *frame_indices, int page_frames_num, int to_access) {
    int index = get_index(frame_indices, page_frames_num, to_access);
    if(index == -1) {
        int min_ind = get_min(values, frame_indices, page_frames_num);
        for(unsigned int i = 0; i < page_frames_num; ++i)
            if(values[i] != 0) {
                values[i] >>= 1;
                clear_bit(values + i);
            }
        values[min_ind] = MSB_ONE;
        frame_indices[min_ind] = to_access;
        return 0;
    } else {
        for(unsigned int i = 0; i < page_frames_num; ++i)
            if(values[i] != 0) {
                values[i] >>= 1;
                clear_bit(values + i);
            }
        set_bit(values + index);
        return 1;
    }
}

int main(int argc, char* argv[]){
    FILE *input = fopen("Lab 09 input.txt", "r");
    int page_frames_num = atoi(argv[1]), n = 1, sym = fgetc(input);
    if(sym == EOF) {
        printf("No elements to access!");
        return EXIT_SUCCESS;
    }
    while(sym != EOF) {
        n += sym == ' ';
        sym = fgetc(input);
    }
    fclose(input);
    input = fopen("Lab 09 input.txt", "r");
    int frame_indices[page_frames_num];
    unsigned int values[page_frames_num];
    for(int i = 0; i < page_frames_num; ++i) {
        values[i] = 0;
        frame_indices[i] = -1;
    }
    int hits_number = 0, misses_number;
    for(int i = 0; i < n; ++i){
        int temp;
        fscanf(input, "%d", &temp);
        hits_number += access_memory(values, frame_indices, page_frames_num, temp);
    }
    misses_number = n - hits_number;
    printf("Hits: %d, Misses: %d, Hit/Miss ratio: %lf\n", hits_number, misses_number, (double) hits_number /
        (double) (misses_number));
    fclose(input);
    return EXIT_SUCCESS;
}