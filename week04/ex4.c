#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    char com[100], path[100], main_file[100];
    system("pwd > path.txt");
    FILE *input = fopen("path.txt", "r");
    fscanf(input, "%s", main_file);
    strcat(main_file, "/");
    strcpy(path, main_file);
    strcat(main_file, "path.txt");
    fclose(input);
    pid_t main = getpid();
    while(1){
        printf("%s", path);
        if(strcmp(fgets(com, 100, stdin), "exit\n") == 0)
            break;
        if(strstr(com, "exit") != 0)
            break;
        com[strlen(com) - 1] = '\0';
        char new_com[100];
        strcpy(new_com, "cd ");
        strcat(new_com, path);
        strcat(new_com, " && ");
        strcat(new_com, com);
        if(com[0] == 'c' && com[1] == 'd' && com[2] == ' '){
            strcat(new_com, " && pwd > ");
            strcat(new_com, main_file);
            pid_t console_p = fork();
            if(getpid() != main) {
                system(new_com);
                exit(0);
            }
            wait(NULL);
            input = fopen("path.txt", "r");
            fscanf(input, "%s", path);
            strcat(path, "/");
            fclose(input);
        } else {
            system(new_com);
        }
    }
}