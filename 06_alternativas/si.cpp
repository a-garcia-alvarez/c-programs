#include<stdio.h>
#include<stdlib.h>

int main(){

    int num;

    printf("Numero: ");
    scanf(" %i", &num);

    if ( num%2 == 0 ) {
      printf("%i es par\n", num);
      printf("Y los pares me gustan.\n");

    }else
      printf("%i es impar\n", num);


    printf("\n");

    return EXIT_SUCCESS;
}
