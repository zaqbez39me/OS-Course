# include <stdio.h>
#include <malloc.h>

int main () {
    char foo[] = "Hello World";
    char **s = malloc(sizeof(foo));
    *s = foo;
    printf( "s is %s\n" ,*s) ;
    s[0] = foo;
    printf ( "s[0] is %s \n" ,s[0]) ;
    free(s);
    return (0) ;
}