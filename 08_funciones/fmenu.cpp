#include<stdio.h>
#include<stdlib.h>

int menu(int *opcion){
    printf("> ");
    scanf("%i", opcion);
}

int main(){

    int opcion=-1;
    printf("opcion 1: a\n");
    printf("opcion 2: al\n");
    printf("opcion 3: alg\n");
    printf("opcion 4: algo\n");
    menu(&opcion);

    printf("has elegido:\n");
    switch(opcion){
        case 1:
            printf("a\n");
            break;
        case 2:
            printf("al\n");
            break;
        case 3:
            printf("alg\n");
            break;
        case 4:
            printf("algo\n");
            break;
        case -1:
            printf("no has elegido opcion\n");
            break;
        default:
            printf("out of range\n");
    }



    return EXIT_SUCCESS;
}
