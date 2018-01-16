#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

int ask_int(int min, int max){
    int op = -1;
    int steep=0;
    int c;
    if(min > max){
        printf("valor minimo mayor que maximo\n");
        return -99;
    }
    do {
        __fpurge(stdin);
        if(steep>100)
            printf(".....................\n");
        else if(steep>50)
            printf("Tu cantidad de tiempo libre me abruma....\n");
        else if(steep>20)
            printf("No, en serio, pon el maldito numero\n");
        else if(steep>15)
            printf("Sos un poco borrico, no?\n");
        else if(steep>10)
            printf("mmmmm...................\n");
        else if(steep>7)
            printf("mmmmm... \n");
        else if(steep>5)
            printf("Has intentado acertar?, no es tan dificil...\n");
        printf("\n");

        printf("Introduce un numero entre %i y %i\n > ", min, max);
        scanf(" %i", &op);

        // flush de stdin que no entiendo todabía
        //while ((c = getchar()) != '\n' && c != EOF);

        steep++;
    } while(op < min || op > max);
}

int main(){
    ask_int(5,15);
    printf("\n");
    return EXIT_SUCCESS;
}
