#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void aggregate(const int* arr1, const int* arr2, unsigned int begin, unsigned int end, FILE *file){
    int t = 0;
    for(;begin < end; ++begin)
        t += arr1[begin] * arr2[begin];
    fprintf(file, "%d ", t);
}

int main(){
    pid_t main = getpid();
    int j;
    FILE *output = fopen("temp.txt", "w");
    int vec1[120], vec2[120];
    for(int i = 0; i < 120; ++i) {
        vec1[i] = rand() % 100;
        vec2[i] = rand() % 100;
    }
    unsigned int n;
    scanf("%ui", &n);
    pid_t poll[n];
    for(int i = 0; i < n; ++i){
        poll[i] = fork();
        if(!poll[i]) {
            j = i;
            break;
        }
    }
    if(getppid() == main){
        aggregate(vec1, vec2, j * 120 / n, (j + 1) * 120 / n, output);
        exit(0);
    }
    fclose(output);
    while (wait(NULL) > 0);
    FILE *input = fopen("temp.txt", "r");
    int res = 0;
    for(int i = 0; i < n; ++i){
        int temp;
        fscanf(input, "%d", &temp);
        res += temp;
    }
    fclose(input);
    printf("Result: %d", res);
    return 0;
}