#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long int n;
    char *end;
    if(argc != 2)
        return EXIT_SUCCESS;
    n = strtol(argv[1], &end, 10);
    for(long int i = 0; i < n; ++i){
        fork();
        sleep(5);
    }
    return EXIT_SUCCESS;
}
