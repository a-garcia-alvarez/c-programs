#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>

#define N 5

typedef struct {
  double x;
  double y;
} Vect;

typedef struct {
  Vect pos;
  Vect vel;
  Vect acc;
} Movil;

typedef struct {
  Vect pos;
  Vect vel;
  Vect acc;
  int(*fun)(...);
} Movil_complex;

int fun_1(...){
    printf("funcion 1\n");
}
int fun_2(...){
    printf("funcion 2\n");
}
int fun_3(...){
    printf("funcion 3\n");
}

int main(){

    Movil_complex Moviles[N];
    Moviles[0].fun = &fun_1;
    Moviles[1].fun = &fun_2;
    Moviles[2].fun = &fun_3;

    for(int i; i<=2; i++){
        Moviles[i].fun();
    }
    return EXIT_SUCCESS;
}
