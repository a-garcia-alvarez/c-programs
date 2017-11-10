#include<stdio.h>
#include<stdlib.h>

int main(){

    int entero = 34;
    float realillo = 35.7;
    double real = 35.7;

    unsigned char byte = 255;

    long int entero_largo = 93;
    unsigned positivo = 5;

    printf("entero %i \t(%lu bytes)\n", entero , sizeof(int));
    printf("entero_largo %li \t(%lu bytes)\n", entero_largo , sizeof(long int));
    printf("%u \t(%lu bytes)\n", positivo , sizeof(unsigned));

    printf("%i \t(%lu bytes)\n", byte , sizeof(char));
    printf("%c \t(%lu bytes)\n", byte , sizeof(char));

    printf("%f \t(%lu bytes)\n", realillo , sizeof(float));
    printf("%lf \t(%lu bytes)\n", real , sizeof(double));
    printf("%8.2f \t(%lu bytes)\n", real , sizeof(float));
    return EXIT_SUCCESS;
}
