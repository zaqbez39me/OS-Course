#include<stdio.h>
#include<stdlib.h>
//<WRITE YOUR CODE HERE>


struct Directory;
struct File;

struct File{
    int id;

    //<WRITE YOUR CODE HERE>;

    struct Directory * directory;// The parent directory
};

struct Directory{
    int nf;
    int nd;

    //<WRITE YOUR CODE HERE>;
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

    //<WRITE YOUR CODE HERE>

    // Example: the path of the folder home is /home

    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);

    File bash, ex31, ex32;

    //<WRITE YOUR CODE HERE>

    //add_file();
    //add_file();
    //add_file();

    //add_to_file();
    //add_to_file();
    //add_to_file();


    //append_to_file();

    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);

    return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir){
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++){
        show_file(dir->files[i]);
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
    printf("%s ", file->name);
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

    //<WRITE YOUR CODE HERE>

}

// Appends the content to the File file
void append_to_file(File *file, const char * content) {

    //<WRITE YOUR CODE HERE>

}

// Prints the path of the File file
void pwd_file(File * file) {

    //<WRITE YOUR CODE HERE>
    // Example: the path for bash file is /bin/bash

}


// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File* file, Directory *dir) {

    //<WRITE YOUR CODE HERE>

}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2){
    if (dir1 && dir2){
        dir2->directories[dir2->nd] = dir1;
        dir2->nd++;
    }
}