#include<stdio.h>
#include<stdlib.h>

void leer(char const *ask, int *num);
void leer2(char const *ask,  int *num, int iterations);
int binar2int(int *arr, int it);

int main(){

   int bit0, bit1, num=0;
   int bit[80];

    /*
    leer("Introduce el valor del primer bit0: ", &bit0);
    leer("Introduce el valor del primer bit1: ", &bit1);
    */

    leer2("Arr Introduce el valor del bit%i: ", bit, 20);

    //printf("arr: %i, %i\n", bit[0], bit[1]);
    printf("arr num: %i\n", binar2int(bit, 20));
    //scanf();
    //
    //printf("b0: %i\n", bit0);
    //

    /*
    if (bit0 == 1 )
        num+=1;
    if (bit1 == 1)
        num+=2;

    printf("Su numero numerico es %i\n", num);
    */

    return EXIT_SUCCESS;
}

void leer(char const *ask, int *num){
  int correct=1;

  do {
    printf("%s", ask);
    scanf(" %i", num);
    if ( *num == 0 || *num == 1 )
      correct=0;
    else{
      printf("\tquerido %i no es un valor valido para un bit\n", *num);
      printf("\tvenga, vuelve a intentarli, que tu puedes\n");
    }
  }while ( correct == 1 );
}

void leer2(char const *ask,  int *num, int iterations){
    for (int i=0; i <= iterations; i++){
      printf(ask, i);
      leer("", &num[i]);
    }
}

int binar2int(int *arr, int it){
    int num=0;

    for (int i=it ; i>= 0; i--){
      printf("bit[%02d]: %i\n", i, arr[i] );
      if (arr[i] == 1)
        num+=1;
      num<<=1;
    }
    num>>=1;

    return num;
}
