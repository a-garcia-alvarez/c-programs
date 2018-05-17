#include<stdio.h>
#include<stdlib.h>

int main(){

    FILE *mi_tubo=NULL;

    mi_tubo = fopen("a.txt","w");

    fprintf(mi_tubo,"Hola, chache.\n");

    fclose(mi_tubo);
    return EXIT_SUCCESS;
}
