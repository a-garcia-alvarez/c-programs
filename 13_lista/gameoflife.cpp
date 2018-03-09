#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define __DEBUG 0
#define eprintf(...) if( __DEBUG ) fprintf (stderr, __VA_ARGS__)

/**/
#include <sys/ioctl.h>
#include <stdio.h>

struct winsize w;

void get__terminal_dimmesions(int *width, int *height)
{
    ioctl(0, TIOCGWINSZ, &w);
    //printf("lines %d\n", w.ws_row);
    //printf("columns %d\n", w.ws_col);
}
/**/

/*
class tablero
{
    int test;
    public:
    tablero() {test=w.ws_row;}
    tablero(int x) {test=x;}
    int egral;
    void set (int x) {test = x;}
    int say_hi() {
        printf("hello world\n");
        printf(" %i\n", test);
        return EXIT_SUCCESS;
    }
};
*/

int get_int(){
    int success;
    int erger;
    do{
        printf(" >");
        success = scanf(" %i", &erger);
        if(success == EOF){
            eprintf("stdin is closed or I/O error\n");
        }else if(success == 0){
            eprintf("Some input was available, but did not make sense for a int.\n"
                    "Purgin stdin\n");
            __fpurge(stdin);

        }else if(success == 1){
            //success
            eprintf("Success getting int\n");
        }
    }while(!success);
    return erger;
}

void get_dimmesions_from_player(int *X, int *Y)
{
    //
    int success;
    int row,col;

    printf("Dimmensions for X axis: ");
    row=get_int();

    printf("Dimmensions for Y axis: ");
    col=get_int();


}



int main(){

    int width,height;
    get__terminal_dimmesions(0,0);
    printf("lines %d\n", w.ws_row);
    printf("columns %d\n", w.ws_col);

    printf("\n\n\n suuuka: %i\n\n",get_int());

    /*
       tablero ttab;
       ttab.say_hi();
       ttab.set(1234);
       ttab.egral=7;
       ttab.say_hi();
       printf("egral: %i", ttab.egral);
       */


    return EXIT_SUCCESS;
}
