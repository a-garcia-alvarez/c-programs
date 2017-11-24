#include<stdio.h>
#include<stdlib.h>

int main(){
    char nombre[256];

    printf("dime tu nombre: ");
    // nombre = &nombre[0]
    scanf(" %s", nombre);
    printf("Tu nombre: %s.\n", nombre);
    return EXIT_SUCCESS;
}
