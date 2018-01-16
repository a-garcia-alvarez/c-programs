#include<stdio.h>
#include<stdlib.h>

int main(){

    unsigned opcion;

    system("toilet --gay -fpagga AREAS");

    printf(
            "Elige la figura:\n"
            "\n"
            "\t1. Triangulo.\n"
            "\t2. Cuadrado.\n"
            "\t3. Paralelogramo.\n"
            "\t4. Pentagono.\n"
            "\t5. Circulo.\n"
            "\n"
            "\tOpcion: "
          );
    scanf(" %u", &opcion);

    switch(opcion){
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
