#include <stdio.h>
#include <stdlib.h>

#define N 3

int main(){

    int a[N][N] = {
        {2,2,3},
        {4,5,6},
        {7,8,9}
    };
    int d, op0=0, op1=0;
    int aux[3];

    for (int desplaz=0; desplaz<N; desplaz++){
        d=1;
        for (int elem=0; elem<N; elem++){
            printf("%4i", a[elem%N][(desplaz+elem)%N]);
            //fflush(stdout);
            d*=a[elem%N][(desplaz+elem)%N];
        }
        op0+=d;
        printf("\t d: %i\t op0: %i\n",d,op0);
        //printf("\n");
    }

    printf("\n");

    for (int desplaz=0; desplaz<N; desplaz++){
    //for (int desplaz=N-1; desplaz>-1; desplaz--){
        d=1;
        for (int elem=0; elem<N; elem++){
            aux[1] = elem%N ;
            aux[2] = (N-1)-((desplaz+elem)%N)  ;
            //aux[2] = (desplaz+elem)%N  ;

            aux[0] = a[aux[1]][aux[2]];

            printf("%4i", aux[0]);
            //printf("d:%i e:%i a[%i][%i]   ",desplaz, elem, aux[1],aux[2]);
            //fflush(stdout);
            d*=aux[0];

        }
        op1+=d;
        printf("\t d: %i\t op1: %i\n",d,op1);
    }

    /*
    //for (int desplaz=0; desplaz<N; desplaz++){
    for (int desplaz=(N-1); desplaz>-1; desplaz--){
        d=1;
        for (int elem=0; elem<N; elem++){
            //printf("%4i", a[elem%N][(desplaz-elem)%N]);
            printf("%4i", a[(desplaz+elem)%N][elem%N]);
            //fflush(stdout);
            //printf("a[%i][%i]\t", elem%3, (desplaz+elem)%N);
            printf("a[%i][%i]\t", (desplaz-elem)%N,elem%N);
            //d*=a[elem%N][(desplaz-elem)%N];
        }
        //op1+=d;
        printf("\n");
        //printf("\t d: %i\t op1: %i\n",d,op1);
    }
    */
    printf("El determinante de la matriz:\n");
    for(int i=0;i<N;i++){
        for(int b=0;b<N;b++)
            printf("%4i ", a[i][b]);
        printf("\n");
    }
    printf("es: %i\n", op0-op1);


    return EXIT_SUCCESS;
}

