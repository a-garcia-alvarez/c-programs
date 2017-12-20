#include<stdio.h>
#include<stdlib.h>

int main(){

    int r=1,
        y=0,
        b=1;

    if(r)
        if(y)
            if(b)
                printf("marron"); //RYB
            else
                printf("naranja"); //RYb
        else
            if(b)
                printf("morado"); //RyB
            else
                printf("rojo"); //Ryb
    else
        if(y)
            if(b)
                printf("verde"); //rYB
            else
                printf("amarillo"); //rYb
        else
            if(b)
                printf("azul"); //ryB
            else
                printf("blanco"); //ryb



    return EXIT_SUCCESS;
}
