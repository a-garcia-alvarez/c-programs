#include<stdio.h>
#include<stdlib.h>

#define N 0x100
int main(){

    const char *p = "the world is "; // Constante tipo cadena.
    /* Pequeña leccion sobre puntero
    char const *p;  // Puntero a una constante. Forma coherente de decir que el char es const.
    char * const p; // Puntero constante (fijo)
    char const * const p; // Puntero constante (fijo) a una constante
    */


    // Puntero:  variable que contiene una direccion de memoria

    char frase[N] = "a vampire\n";
    char *d = &frase[0];
    d= frase;
    d= &frase[2];

    frase[2] == 'v';  // Notacion de matrices.
    *d == 'v';        // Notacion de punteros.
    *(d+2) == 'm';    // El 2 está en aritmética de punteros
    *d + 2 == 'x';



    printf("%s%s", p, frase );
    printf("p: %lu\n&p: %lu\n", sizeof(p), sizeof(&p));
    printf("d: %lu\n&d: %lu\n", sizeof(d), sizeof(&d));
    printf("frase: %lu\n&frase: %lu\n", sizeof(frase), sizeof(&frase));
    printf("%i", *d + 2);



    return EXIT_SUCCESS;
}
