
#include<stdio.h>
#include<stdlib.h>

int main(){

    int op1 = 7;
    int op2;

    printf("Operando 2: ");
    scanf(" %i", &op2);
    /*
      El epacio indica que hay que descartar los whitespaces
      %i entero
      &op2 direccion de memoria
     */

    //printf("%i + 3 = %i\n", op1, op1 + 3 );
    printf("%i + %i = %i\n", op1, op2, op1 + op2 );

    return EXIT_SUCCESS;
}
