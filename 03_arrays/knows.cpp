#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include <string.h>

#define N 0x10

int main(){
    char nombre[N];
    int lista[N];

    char no_[N] = { 'p','e','p','e','\0' };
    char nom[N] = "pepe";

    nom[3]= 'a'; // Despues de la inicializacion hay que ir celda por celda por celda

    printf("Nombre ocupa %lu bytes.\n", sizeof(nombre));
    printf("Nombre ocupa %Xh bytes.\n", (int) sizeof(nombre));

    printf("Lista ocupa %lu bytes.\n", sizeof(lista));
    printf("Lista ocupa %lu bytes.\n", sizeof(lista));

    printf("%c", nombre[0]);
    printf("%c", nombre[1]);
    printf("%c", nombre[2]);
    printf("%c", nombre[3]);
    printf("%c", nombre[4]);
    printf("%c", nombre[5]);
    printf("%c", nombre[6]);
    printf("%c", nombre[7]);
    printf("%c", nombre[8]);
    printf("\n");
    printf("%s\n", nombre);

    bzero(lista, sizeof(lista));
    memset(lista + 2, 3, 2);
    // cuando hacemos un "puntero + n" desplazamos el puntero n
    // veces los bytes que ocupa el tipo de datos al que apunta
    // dicho puntero

    printf("%X.", lista[0]);
    printf("%X.", lista[1]);
    printf("%X.", lista[2]);
    printf("%X.", lista[3]);
    printf("%X.", lista[4]);
    printf("%X.", lista[5]);
    printf("%X.", lista[6]);
    printf("%X.", lista[7]);
    printf("%X.", lista[8]);
    printf("\n ");


    printf("Dime tu nombre: ");
    fgets(nombre, N-1, stdin);
    sprintf(nom, "Hola %s", nombre);
    printf("%s\n",nom);

    return EXIT_SUCCESS;
}
