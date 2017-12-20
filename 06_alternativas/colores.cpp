#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ask(char const* color);

int main(){

    int color=0;
    char rcolor[10];

    //printf("ves el color rojo?[s/n]> ");
    //scanf(" ")

    color += ask("rojo");
    color<<=1;
    color += ask("verde");
    color<<=1;
    color += ask("azul");


    //printf("color: %i", color);

    switch(color){
        case 0:
            stpcpy(rcolor, "negro");
            break;
        case 1:
            stpcpy(rcolor, "azul");
            break;
        case 2:
            stpcpy(rcolor, "verde");
            break;
        case 3:
            stpcpy(rcolor, "cyan");
            break;
        case 4:
            stpcpy(rcolor, "rojo");
            break;
        case 5:
            stpcpy(rcolor, "magenta");
            break;
        case 6:
            stpcpy(rcolor, "amarillo");
            break;
        case 7:
            stpcpy(rcolor, "blanco");
            break;
        default:
            stpcpy(rcolor, "error");
            break;
    }

    printf("Tu color es el %s\n", rcolor);

    return EXIT_SUCCESS;
}

int ask(char const* color){
    int correct_ans = 1;
    char ans;
    do{
    printf("ves el color %s ? [S/N]", color );
    scanf(" %c", &ans);
    if ( ans == 'S' || ans == 's' || ans == 'N' || ans == 'n' ){
        correct_ans=0;
    }else
        printf("\tResponda con 'S', 's', 'N' o 'n'\n");
    }while(correct_ans);

    if (ans=='S' || ans=='s')
        correct_ans=1;
    else
        correct_ans=0;

    return correct_ans;
}
