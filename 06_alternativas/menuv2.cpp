#include<stdio.h>
#include<stdlib.h>

const char *opcion[] = {
    "Triangulo",
    "Cuadrado",
    "Paralelogramo",
    "Pentagono",
    "Circulo",
    NULL
};


//enum TSemana = {sunday, monday, tuesday, wednesday, thursday, friday, saturday};



int main(){

    unsigned eleccion;

    system("toilet --gay -fpagga AREAS");
    printf( "Elige la figura:\n\n");
    for(nt i=0;i<=4;i++)
            printf("\t%i. %s.\n", i+1, opcion[i]);
    printf( "\n"
            "\tOpcion: "
          );
    scanf(" %u", &eleccion);

    switch(eleccion){
        case 1:
            printf("triangulo △");
            break;
        case 2:
            printf("cuadrado □");
            break;

        case 3:
            printf("paralelogramo ▱");
            break;

        case 4:
            printf("pentagono ⬠");
            break;

        case 5:
            printf("triangulo ○");
            break;
        default:
            printf("Del 1 al 5 borrico.\n");
            break;
    }
    printf("\n");

    return EXIT_SUCCESS;
}
