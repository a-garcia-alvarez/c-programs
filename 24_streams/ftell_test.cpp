#include<stdio.h>
#include<stdlib.h>


int main(){

    FILE *tubico=NULL;
    char letra, file_name[30];
    int contador=0;

    printf("nombre del fichero en el que buscar: ");
    scanf(" %s", file_name);

    tubico = fopen(file_name,"wr");

    printf("En el principio: %li", )
    fseek(tubico, 100, SEEK_SET);
    fprintf(tubico,"im here");

    fclose(tubico);

    return EXIT_SUCCESS;
}
