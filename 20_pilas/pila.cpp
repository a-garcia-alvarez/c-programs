#include<stdio.h>
#include<stdlib.h>

#define N 0x100

#ifndef NDEBUG
#define DEBUG(...) fprintf(stderr, __VA_ARGS__ );
#else
#define DEBUG(...)
#endif


typedef struct {
    int data[N];
    int cima;
} Pila;

void push(int dato, Pila *cual_pila){
    DEBUG("->%i\tcima: %i\n",dato,cual_pila->cima)
    cual_pila->data[cual_pila->cima++] = dato;
}
int pop(Pila *cual_pila){
    DEBUG("<-%i\tcima: %i\n", cual_pila->data[(cual_pila->cima)-1], cual_pila->cima)
    return cual_pila->data[--(cual_pila->cima)];
}

int main(){

    //
    Pila numeros;
    numeros.cima=0;

    push(5  , &numeros);
    push(27 , &numeros);
    push(44 , &numeros);
    push(2  , &numeros );
    pop(&numeros);
    push(15 , &numeros );
    push(6  , &numeros );
    push(95 , &numeros );
    pop(&numeros);
    push(44 , &numeros );
    pop(&numeros);
    pop(&numeros);
    pop(&numeros);
    pop(&numeros);
    pop(&numeros);

    return EXIT_SUCCESS;
}
