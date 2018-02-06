#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define N 3
#define M N+1

#define __DEBUG 0

int ask_YN(){
	int success=0;
	char ans;
	do{
	success=scanf(" %c", &ans);

	if(success == EOF){
            if( __DEBUG   ) fprintf(stderr,"stdin is closed or I/O error\n");
        }else if(success == 0){
            if( __DEBUG   ){
                 fprintf(stderr,"Some input was available, but did not make sense f    or a double.\n");
                 fprintf(stderr,"Purgin stdin\n");
            }
            __fpurge(stdin);
        }else if(success == 1){
            //success
            if( __DEBUG   ) fprintf(stderr,"Success getting int\n");
        }

	if ( ans == 'S' || ans == 's' || ans == 'N' || ans == 'n' || ans == 'y' || ans == 'Y' ){
        success=1;
   	}else{
     	printf("\tResponda con 'S', 's', 'N' o 'n'\n");
     	success=0;
     	}
  	}while(!success);

  	if (ans=='S' || ans=='s' || ans == 'y' || ans == 'Y' )
	  	return true;
	else
	  	return false;


}

void print_matrix(double (*matrix)[10],int x, int y ){

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%10.4lf", matrix[i][j]);
        }
        printf("\n");
    }
}

void ask_matrix(double (*matrix)[10],int x, int y ){
    int success=0;
    printf("Introduce una mariz de %i x %i :\n", x, y);
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            do{
                if( __DEBUG  ) fprintf(stderr,"Getting matrix [%i][%i]\n",i ,j);
                printf("Introduce el valor [%i][%i]:\n >",i ,j);
                success = scanf(" %lf", &matrix[i][j]);
                if(success == EOF){
                    if( __DEBUG  ) fprintf(stderr,"stdin is closed or I/O error\n");
                }else if(success == 0){
                    if( __DEBUG  ){
                        fprintf(stderr,"Some input was available, but did not make sense for a double.\n");
                        fprintf(stderr,"Purgin stdin\n");
                    }
                    __fpurge(stdin);
                }else if(success == 1){
                    //success
                    if( __DEBUG  ) fprintf(stderr,"Success getting matrix [%i][%i]\n",i ,j);
                }
            }while(!success);
        }
    }
}

int ask_int(char const *text, int *num){
    int success;
    do{
        printf("%s", text);
        success = scanf(" %i", num);

	if(success == EOF){
            if( __DEBUG   ) fprintf(stderr,"stdin is closed or I/O error\n");
        }else if(success == 0){
            if( __DEBUG   ){
                 fprintf(stderr,"Some input was available, but did not make sense f    or a double.\n");
                 fprintf(stderr,"Purgin stdin\n");
            }
            __fpurge(stdin);
        }else if(success == 1){
            //success
            if( __DEBUG   ) fprintf(stderr,"Success getting int\n");
        }
    }while(!success);
}

int main(){

    double matrix0[10][10];
    double matrix1[10][10];
    int matrix0_X,matrix0_Y,matrix1_X,matrix1_Y;

    int success=0, sure=0;

  do{
    do{
        printf("Enter rows and columns for first matrix:\n");

        ask_int("  First matrix rows:", &matrix0_Y);
        //printf("First matrix rows: %i\n", matrix0_Y);
        ask_int("  First matrix columns:", &matrix0_X);
        //printf("First matrix columns: %i\n", matrix0_X);

        if(matrix0_Y >0 && matrix0_X >0)
        	success=1;
        else{
        printf("dimension must be greater than 0");
        	continue;
        }

        printf("Are the dimmensions correct? [y/n] ");
        if (!ask_YN())
        	success=0;

    }while(!success);

    do{
        printf("Enter rows and columns for second matrix:\n");

        ask_int("  Second matrix rows:", &matrix1_Y);
        //printf("Second matrix rows: %i\n", matrix1_Y);
        ask_int("  Second matrix columns:", &matrix1_X);
        //printf("Second matrix columns: %i\n", matrix1_X);

        if(matrix1_Y >1 && matrix1_X >1)
        	success=1;

        printf("Are the dimmensions correct? [y/n] ");
        if (!ask_YN())
        	success=0;

    }while(!success);

    if(matrix0_X != matrix1_Y){
	printf("Error! column of first matrix not equal to row of second.\n");
        	success=0;
    }

  }while(!success);



    //ask_matrix( matrix0  );

    return EXIT_SUCCESS;
}
