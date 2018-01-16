#include<stdio.h>
#include<stdlib.h>

void pasteriscos(int n) {
    for(int i=0;i<n;i++)
        printf("*");
    printf("\n");
    /*
    for(int i=0;i<n;printf("*"))
      i++;
    printf("\n");
    */
}

void make_cuadrado(int size) {
    pasteriscos(size);
    for(int i=0;i<(size-2)/2;i++){
        printf("*");
        for(int i=0;i<size-2;i++)
            printf(" ");
        printf("*\n");
    }
    pasteriscos(size);
  }

void make_cuadro(int size){
    //char type0[][10]={"═","║","╔","╗","╚","╝","╠","╣","╦","╩","╬"};
    //char type1[]="";
    //char *type = type0;
    //type = type0;
    //printf("%c",type0[1]);

    // print first line
    //printf("%s\n",type[0]);

    printf("╔");
    for(int i=0;i<size-2;i++)
        printf("═");
    printf("╗\n");

    // print columns
    for(int i=0;i<(size-2)/2;i++){
        printf("║");
        for(int i=0;i<size-2;i++)
             printf(" ");
        printf("║\n");
    }

    // print las line
    printf("╚");
    for(int i=0;i<size-2;i++)
        printf("═");
    printf("╝\n");
}

int main(){

    /*
    for(int i=0; i<5; i++)
        printf("*");
    printf("\n");
    */
    pasteriscos(5);
    printf("\n\n\n\n");
    make_cuadrado(10);
    printf("\n\n\n\n");
    make_cuadro(5);
    return EXIT_SUCCESS;
}
