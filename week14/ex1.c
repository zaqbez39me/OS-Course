#include <stdio.h>
#include <stdlib.h>

int get_lines_num(){
    FILE *input = fopen("input.txt", "r");
    int n = 1;
    int i = 0;
    char prev = 0;
    for(char temp = getc(input);;prev = temp, temp = getc(input)){
        if(temp == EOF) {
            if (prev == '\n')
                n -= 1;
            break;
        }
        n += (temp == '\n' ? i != 0 : 0);
        i = (temp == '\n' ? 0 : i + 1);

    }
    fclose(input);
    return n;
}

void error(FILE* input, int *a){
    fclose(input);
    *a = -1;
}

int check_matrix(FILE* input, const int* const a){
    int a_rows = 0, num_spaces = 1;
    char prev = 0;
    for(char temp = getc(input);;temp = getc(input)){
        if(temp == EOF) {
            if (prev != '\n')
                a_rows += 1;
            return a_rows;
        }
        if(temp == '\n') {
            if (temp == prev)
                break;
            if(prev == ' ')
                num_spaces -= 1;
            if(num_spaces != *a)
                return -1;
            num_spaces = 1;
            a_rows += 1;
        } else
        if(temp == ' ' && prev != temp)
            num_spaces += 1;
        prev = temp;
    }
    return a_rows;
}

void get_numbers(int *const a, int* b){
    FILE *input = fopen("input.txt", "r");
    char temp;
    *a = 1;
    for(temp = getc(input); temp != '\n'; *a += temp == ' ', temp = getc(input));
    int a_check = 1;
    if(fgetc(input) != '\n') return error(input, a);
    for(temp = getc(input); temp != '\n' && a_check <= *a; a_check += temp == ' ', temp = getc(input));
    if(fgetc(input) != '\n' || a_check != *a) return error(input, a);
    int n_lines = get_lines_num(), rows_num = (n_lines - 2);
    char prev = 0;
    int num_spaces = 1;
    int a_rows = check_matrix(input, a);
    if(a_rows == -1) return error(input, a);
    if(a_rows != check_matrix(input, a)) return error(input, a);
    *b = a_rows;
    fclose(input);
}

int main(){
    int n_types = 0, n_proc = 0;
    get_numbers(&n_types, &n_proc);
    if(n_types == -1) {
        printf("Input malformed!");
        return EXIT_FAILURE;
    }
    FILE *input = fopen("input.txt", "r");
    int E[n_types], A[n_types], check[n_types], executed = 0;
    int C[n_proc][n_types], R[n_proc][n_types];
    _Bool marked[n_types];
    for(int j = 0; j < n_types; ++j) fscanf(input, "%d", E + j);
    for(int j = 0; j < n_types; ++j) {
        fscanf(input, "%d", A + j);
        check[j] = 0;
    }
    for(int i = 0; i < n_proc; ++i)
        for(int j = 0; j < n_types; ++j) {
            fscanf(input, "%d", &C[i][j]);
            check[j] += C[i][j];
        }
    for(int i = 0; i < n_types; ++i)
        if(check[i] + A[i] != E[i]){
            fclose(input);
            printf("Input malformed!");
            return EXIT_FAILURE;
        }
    for(int i = 0; i < n_proc; ++i)
        for(int j = 0; j < n_types; ++j)
            fscanf(input, "%d", &R[i][j]);
    _Bool something_executed = 0;
    while (1) {
        for (int i = 0; i < n_proc; ++i) {
            _Bool can_execute = 1;
            for(int j = 0; j < n_types; ++j){
                if(R[i][j] > A[j]) {
                    can_execute = 0;
                    break;
                }
            }
            if(can_execute){
                for(int j = 0; j < n_types; ++j)
                    A[j] += C[i][j];
                something_executed = 1;
                executed += 1;
            }
            if (i == n_proc - 1 && !something_executed) {
                printf("Deadlocked N: %d\n", n_proc - executed);
                return EXIT_SUCCESS;
            }
            if(executed == n_proc) {
                printf("No deadlock is detected!");
                return EXIT_SUCCESS;
            }
        }
    }
}