#include<stdio.h>
#include<stdlib.h>


int main(){

    FILE *tubico=NULL;
    char letra, file_name[30];
    int contador=0;

    printf("nombre del fichero en el que buscar: ");
    scanf(" %s", file_name);

    printf("que letra qieres buscar: ");
    scanf(" %c", &letra_buscada);

    tubico = fopen(file_name,"r");

    while(! feof(tubico))
        if(letra_buscada == fgetc(tubico))
            contador++;

    fclose(tubico);

    printf("La letra %c aparece en el fichero %s %i veces\n",
            letra_buscada,file_name, contador );
    return EXIT_SUCCESS;
}
