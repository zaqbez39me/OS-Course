#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    DIR * d = opendir("/");
    struct dirent * dir;
    while ((dir = readdir(d)) != NULL)
        printf("%s ", dir->d_name);
    return EXIT_SUCCESS;
}