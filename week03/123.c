#include "stdio.h"
#include "string.h"

struct File{
    int id;
    char name[64], data[1024];
    int size;
    struct Directory * directory;// The parent directory
};

int main(){
    char r[20];
    struct File file;
    printf("%d", file.size);
}

