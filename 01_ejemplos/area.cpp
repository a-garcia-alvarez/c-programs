#include<stdio.h>
#include<stdlib.h>

int main(){

    //int
    double lado,
           area,
           perimetro;

    system("toilet --gay -fpagga CUADRADO");

    /* entrada de datos */
    printf("Lado: ");
    scanf(" %lf", &lado);

    /* Calculo */
    area = lado * lado;
    perimetro = 4*lado;

    /* Salida de datos */
    //printf("El perimetro de un cuadrado de lado %i es: %i", lado, perimetro);
    //printf("El area de un cuadrado de lado %i es: %i", lado, area);

    printf( "Area; %lf\n"
            "Perimetro: %lf\n",
            area, perimetro);

    return EXIT_SUCCESS;
}
