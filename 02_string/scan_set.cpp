#include<stdio.h>
#include<stdlib.h>

int main(){
    char nombre[16];
    char hexadecimal[16];
    int num;

    printf("Entero: ");
    scanf(" %i", &num);
    scanf(" %s", nombre);
    printf("[%i] => %s.\n", num, nombre);

    printf("Entero: ");
    scanf(" %i", &num);
    scanf(" %s", nombre);
    printf("[%i] => %s.\n", num, nombre);


    printf("Hexadecimal: ");
    scanf(" %[0-9a-fA-F]", hexadecimal);
    printf("Hex: 0x%sh\n", hexadecimal);

    scanf(" %[^a-f]", hexadecimal); //conjunto de seleccion inverso
    /* Todo menos a-f se lee */

    scanf(" %[^\n] ", nombre);
    printf("[%i] => %s.\n", num, nombre);
    fgets(nombre, 16, stdin);

    scanf(" %i/%i/%*i ", &dia, &mes);
    // %*i; * caracter de supresion, se lee pero no se asigna

    return EXIT_SUCCESS;
}
