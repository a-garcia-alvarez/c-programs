#include<stdio.h>
#include<stdlib.h>

int main(){

    printf("parte1");

    goto etiqueta;

    printf("parte2");

etiqueta:
    printf("parte3");

    return EXIT_SUCCESS;
}
