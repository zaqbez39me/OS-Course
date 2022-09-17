#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//<WRITE YOUR CODE HERE>

int last_id = 0;
struct Directory;
struct File;

struct File{
    int id;
    char name[64], *data;
    unsigned long int size;
    struct Directory * directory;// The parent directory
};

struct Directory{
    int nf;
    int nd;
    struct File *files[256];
    struct Directory *directories[8];
    char path[2048];
};

typedef struct Directory Directory;
typedef struct File File;


// Operations on files
void add_to_file(File *file, const char * content);
void append_to_file(File *file, const char * content);
void pwd_file(File * file);


// Operations on directories
void add_file(File* file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you

// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

int main(){

    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";



    Directory home, bin, root;

    strcpy(home.path, "/home");
    strcpy(bin.path, "/bin");
    strcpy(root.path, "/");
    home.nf = 0;
    bin.nf = 0;
    root.nf = 0;
    home.nd = 0;
    bin.nd = 0;
    root.nd = 0;

    // Example: the path of the folder home is /home

    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);

    File bash, ex31, ex32;
    strcpy(bash.name, "bash");
    strcpy(ex31.name, "ex3_1.c");
    strcpy(ex32.name, "ex3_2.c");

    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32, &home);

    add_to_file(&ex31, content1);
    add_to_file(&ex32, content3);
    add_to_file(&bash, content4);


    append_to_file(&ex31, content2);

    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);

    free(bash.data);
    free(ex31.data);
    free(ex32.data);

    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir){
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf - 1; i++){
        show_file(dir->files[i]);
        printf(", ");
    }
    if(dir->nf > 0) {
        show_file(dir->files[dir->nf - 1]);
        printf(" ");
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");

    for (int i = 0; i < dir->nd; i++){
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

// Prints the name of the File file
void show_file(File *file){
    printf("%s", file->name);
}

// Shows details of the File file
void show_file_detailed(File *file){
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}



// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char * content) {
    if(file) {
        if(strlen(content) + 1 > 1024)
            printf("Error, exceeded max data length");
        else
            if(file->data != NULL) {
                file->data = (char*) malloc(sizeof(char) * (strlen(content) + 1));
                strcpy(file->data, content);
                file->size = strlen(file->data) + 1;
            } else {
                char *temp = (char*) realloc(file->data, sizeof(char) * (strlen(content) + 1));
                free(file->data);
                file->data = temp;
                strcpy(file->data, content);
                file->size = strlen(file->data) + 1;
            }
    }
}

// Appends the content to the File file
void append_to_file(File *file, const char * content) {
    if(file) {
        if (file->data != NULL) {
            if (strlen(content) + 1 > 1024)
                printf("Error, exceeded max data length");
            else {
                file->data = (char *) realloc(file->data, sizeof(char) * (strlen(content) +
                                                                          strlen(file->data) + 1));;
                strcat(file->data, content);
                file->size = strlen(file->data) + 1;
            }
        } else
            add_to_file(file, content);
    }
}

// Prints the path of the File file
void pwd_file(File * file) {
    printf("%s/%s\n", file->directory->path, file->name);
    // Example: the path for bash file is /bin/bash

}


// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File* file, Directory *dir) {
    if(dir) {
        if(dir->nf < 256) {
            dir->files[dir->nf] = file;
            dir->nf++;
            file->id = last_id++;
            file->directory = dir;
        }
        else
            printf("Error, exceeded max number of files in this directory");
    }
}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2){
        if (dir1 && dir2) {
            if(dir2->nd < 8) {
                dir2->directories[dir2->nd] = dir1;
                dir2->nd++;
            }
            else
                printf("Error, exceeded max number of sub-directories in this directory");
        }
}