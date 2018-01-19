#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

void pasteriscos(int n) {
    for(int i=0;i<n;i++)
        printf("*");
    printf("\n");
    /*
    for(int i=0;i<n;printf("*"))
      i++;
    printf("\n");
    */
}

void make_cuadrado(int size) {
    pasteriscos(size);
    for(int i=0;i<(size-2)/2;i++){
        printf("*");//⁑");
        for(int i=0;i<size-2;i++)
            printf(" ");
        printf("*\n");
    }
    pasteriscos(size);
}

void make_cuadro(int size){
    //char type0[][10]={"═","║","╔","╗","╚","╝","╠","╣","╦","╩","╬"};
    //char type1[]="";
    //char *type = type0;
    //type = type0;
    //printf("%c",type0[1]);

    // print first line
    //printf("%s\n",type[0]);

    printf("╔");
    for(int i=0;i<size-2;i++)
        printf("═");
    printf("╗\n");

    // print columns
    for(int i=0;i<(size-2)/2;i++){
        printf("║");
        for(int i=0;i<size-2;i++)
             printf(" ");
        printf("║\n");
    }

    // print las line
    printf("╚");
    for(int i=0;i<size-2;i++)
        printf("═");
    printf("╝\n");
}

void make_diagonal(int size, int dtype){
    int vsize=size;
    if(dtype>2)
        vsize=size/2-2;
    if(dtype%2){
        //printf("algo");
	    for(int i=0;i<size;i++){
		for(int d=0;d<size;d++)
		    if(d==i)
		        printf("*");
		    else
		        printf(" ");
		printf("\n");
	    }
    }else{
	    for(int i=0;i<size;i++){
		for(int d=0;d<size;d++)
		    if(d==size-i)
		        printf("*");
		    else
		        printf(" ");
		printf("\n");
	    }
    }
}

int dual_cuadrado(int size){
    if(size<1){
        fprintf(stderr,"[dual_cuadrado]:Wrong size, size: %i, expected size >=1\n",size);
        return EXIT_FAILURE;
    }

    // filas mayores
    for(int fm=0;fm<size;fm++)
        // filas menores
        for(int f=0;f<size;f++){
                // columnas mayores
                for(int cm=0;cm<size;cm++)
                    // columnas menores
                    for(int c=0;c<size;c++)
                        // si fila mayor es par Y columnas mayor es par
                        /*
                        if( (fm+cm)%2 )
                            printf("*");
                        else
                            printf("x");
                        */
                        printf("%c", ( (fm+cm)%2 ) ? '*' : 'x');
                printf("\n");
        }

    /*
    // filas mayores
    for(int fm=0;fm<size;fm++)
        // filas menores
        for(int f=0;f<size;f++){
                // columnas mayores
                for(int cm=0;cm<size;cm++)
                    // columnas menores
                    for(int c=0;c<size;c++)
                        // si fila mayor es par Y columnas mayor es par
                        if( (fm+cm)%2 )
                            printf("*");
                        else
                            printf("x");
                printf("\n");
        }
    */


    /*
    for(int a=0;a<size;a++)
        for(int b=0;b<size;b++){
                for(int c=0;c<size;c++)
                    for(int d=0;d<size;d++)
                        //if( ((a%2)==0) == (c%2==0) )
                        //if( !(a%2) == !(c%2) )
                        if((a+c)%2)
                            printf("*");
                        else
                            printf("x");
                printf("\n");
        }
    */
    /*
    for(int a=0;a<size;a++)
        for(int b=0;b<size;b++){
            if((a%2)==0){
                //
                for(int c=0;c<size;c++)
                    for(int d=0;d<size;d++)
                        if(c%2==0)
                            printf("*");
                        else
                            printf("x");
                printf("\n");

            }else{
                //
                for(int c=0;c<size;c++)
                    for(int d=0;d<size;d++)
                        if(c%2!=0)
                            printf("*");
                        else
                            printf("x");
                printf("\n");
            }
        }
    */


    /*

    //bucle vertical mayor
    for(int bvm=0;bvm<size;bvm++){
        //bucle horizontal mayor
        //printf("\nbvm: %i\n\t",bvm);
        for(int bhm=0;bhm<size;bhm++){
            //printf("bhm:%i ",bhm);
            // ambos pares o ambo impares
            if(   ( ((bvm%2)==0) && ((bhm%2)==0) ) //both even
               || ( ((bvm%2)!=0) && ((bhm%2)!=0) ) //both odd
              )
            {
                printf("s");
            }
            else
            {
                printf("n");
            }
        }
        printf("\n");

    }
    */


    /*
    for(int g=0;g<size;g++)
      if((size+11)%2){
          for(int f=0;f<size;f++){
            for(int c=0;c<size;c++){
                for(int a=0;a<size;a++)
                    printf("*");
               c++;
                if(size-c)for(int b=0;b<size;b++)
                    printf("-");
            }
           printf("\n");

        }
      }else
      {
          for(int f=0;f<size;f++){
               for(int c=0;c<size;c++){
                   for(int a=0;a<size;a++)
                       printf("*");
                   c++;
                   if(size-c)for(int b=0;b<size;b++)
                       printf("-");
               }
               printf("\n");
          }
      }
      */
    printf("\n");
}

int ask_n(){
    int ret=-1;
    do{
      printf("Introduce el numero:\n"
             " > ");
      __fpurge(stdin);
      scanf(" %i",&ret);
      //if()
      if(ret<1){
          fprintf(stderr,"error, no valid value\n");
          continue;
      }
      else{
         break;
      }
    }while(true);
    return ret;
}
int main(){

    /*
    for(int i=0; i<5; i++)
        printf("*");
    printf("\n");
    */
    pasteriscos(5);
    printf("\n\n\n\n");
    make_cuadrado(10);
    printf("\n\n\n\n");
    make_cuadro(5);
    printf("\n\n\n\n");
    make_diagonal(10,22);
    printf("\n\n\n\n");
    dual_cuadrado(2);
    dual_cuadrado(3);
    dual_cuadrado(4);
    printf("\n\n\n\n");
    dual_cuadrado(ask_n());
    //for(int i=0;i<11;i++) dual_cuadrado(i);
    dual_cuadrado(1);
    return EXIT_SUCCESS;
}
