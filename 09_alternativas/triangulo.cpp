#include<stdio.h>
#include<stdlib.h>

void make_t1(int size){
    for(int f=0;f<size;f++){
        for(int c=0;c<=f;c++)
            printf("*");
        printf("\n");
    }
}
void make_t2(int size){
    for(int f=size;f>=0;f--){
        for(int c=0;c<f;c++)
            printf("*");
        printf("\n");
    }
}

void make_t3(int size){
    for(int f=0;f<size;f++){
        for(int c=0;c<(size-f);c++)
            printf("*");
        printf("\n");
    }
}

void make_raro(int size){
    // Pintar fila
    for(int f=0;f<size;f++){
        //pintar triangulo
        for(int t=0;t<size;t++)
            //printar columna
            for(int c= t ? 1:0;c<size;c++){
                if(f==c)
                    printf("*");
                else
                    printf(" ");
            }
        printf("\n");
    }


    /*
       for(int i=0; i<size;i++){
       for(int t=0;t<size;t++)
       for(int a=0;a<size;a++){
       if(i==t)
       printf("*");
       else
       printf(" ");
       }

       printf("\n");
       }*/
}

int main(){
    int size;
    printf(" numero > ");
    scanf(" %i", &size);

    make_t1(size);
    //printf("\n\n");
    printf("\n");
    make_t2(size);
    make_t3(size);
    printf("\n");
    make_raro(size);



    return EXIT_SUCCESS;
}
