#include<stdio.h>
#include<stdlib.h>

double suma(double op1, double op2){
    return op1+op2;
}
void pedir_ops(double *op1, double *op2){
    printf("Primer numero:\n > ");
    scanf(" %lf", op1);
    printf("Segundo numero:\n > ");
    scanf(" %lf", op2);
}
double ask_double(char const * ask_s){
    double op;
    printf("%s",ask_s);
    scanf(" %lf", &op);
    return op;
}

int main(){

    /*
    double o1,o2;

    //pedir datos
    pedir_ops(&o1, &o2);

    //operar y sacar por pantalla
    printf("Resultado de la suma: %.2lf\n", suma(o1,o2));
    printf("\n\n******\n");
    printf("%.2lf", ask_double("test ask_double 1:\n"));
    printf("\n\n******\n");

    */
    printf("Resultado de la suma: %.2lf\n",
            suma(
                ask_double("Segundo numero:\n > "),
                ask_double("Primer numero:\n > ")
                )
            );

    return EXIT_SUCCESS;
}
