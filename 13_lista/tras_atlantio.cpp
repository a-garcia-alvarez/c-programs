#include<stdio.h>
#include<stdlib.h>

int main(){

    char palindromo[] = "aahhaa";
    char *letra = palindromo;

    fprintf(stderr,"pal:   %p\n", palindromo);
    fprintf(stderr,"letra: %p\n", letra);

    while( *letra != '\0' ){
        printf("%c", *letra);
        letra++;
    }
    printf("\n");
    fprintf(stderr,"letra: %p\n", letra);
    while (letra != palindromo){
        //letra--;
        printf("%c", *--letra);
    }
    printf("\n");
    fprintf(stderr,"letra: %p\n", letra);

    return EXIT_SUCCESS;
}
