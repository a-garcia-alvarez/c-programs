#include<stdio.h>
#include<stdlib.h>


int main(){

    FILE *tubico=NULL;
    char letra_buscada, letra_leida;
    char file_name[30];
    int contador=0;


    printf("nombre del fichero en el que buscar: ");
    scanf(" %s", file_name);

    printf("que letra qieres buscar: ");
    scanf(" %c", &letra_buscada);

    tubico = fopen(file_name,"r");

    while(! feof(tubico))
    {
        letra_leida = fgetc(tubico);
        if(letra_buscada == letra_leida)
            contador++;
    }
    fclose(tubico);

    printf("La letra %c aparece en el fichero %s %i veces\n",
            letra_buscada,file_name, contador );
    return EXIT_SUCCESS;
}
