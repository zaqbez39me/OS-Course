#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "stdio.h"

int get_index(const __ino_t *ino, int n, __ino_t find){
    for(int i = 0; i < n; ++i){
        if(ino[i] == find)
            return i;
    }
    return -1;
}

int get_first_empty(const __ino_t *ino, int n){
    for(int i = 0; i < n; ++i){
        if(ino[i] == -1)
            return i;
    }
    return -1;
}

void print_all(__ino_t target, int number){
    struct __dirstream *dirp = opendir("./tmp");
    struct dirent *dp;
    int i = 0;
    while (( dp = readdir(dirp)) != NULL ) {
        if(dp->d_ino == target){
            if(i + 1 == number)
                printf("%s, ", dp->d_name);
            else
                printf("%s", dp->d_name);
        }
        ++i;
    }
    printf("\n");
    closedir(dirp);
}

int main(){
    struct __dirstream *dirp = opendir ( "./tmp" ) ;
    if ( dirp == NULL ) { return EXIT_FAILURE; }
    struct dirent *dp;
    int n = 0;
    while (( dp = readdir(dirp)) != NULL ) {
        n++;
    }
    closedir(dirp);
    dirp = opendir("./tmp");
    __ino_t ino[n];
    int ino_number[n];
    for(int i = 0; i < n; ++i) {
        ino[i] = -1;
    }
    while (( dp = readdir(dirp)) != NULL ) {
        int index = get_index(ino, n, dp->d_ino);
        if(index == -1) {
            int first_empty = get_first_empty(ino, n);
            ino[first_empty] = dp->d_ino;
            ino_number[first_empty] = 1;
        } else{
            ++ino_number[index];
        }
    }
    closedir(dirp);
    dirp = opendir("./tmp");
    int counter = 0;
    while (( dp = readdir(dirp)) != NULL ) {
        int index = get_index(ino, n, dp->d_ino);
        if(ino_number[index] >= 2) {
            printf("%s - ", dp->d_name);
            print_all(dp->d_ino, ino_number[index]);
        }
        ++counter;
    }
    closedir (dirp);
}