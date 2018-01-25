#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define N 3

#define __DEBUG 0

void print_matrix(double (*matrix)[N] ){
    //
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%10.4lf", matrix[i][j]);
        }
        printf("\n");
    }
}

void ask_matrix(double (*matrix)[3] ){
    //
    int success=0;
    printf("Introduce una mariz cuadrada de %i x %i :", N, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            do{
                if( __DEBUG )
                    fprintf(stderr,"Getting matrix [%i][%i]\n",i ,j);
                printf("Introduce el valor [%i][%i]:\n >",i ,j);
                success = scanf(" %lf", &matrix[i][j]);
                if(success == EOF){
                    if( __DEBUG )
                        fprintf(stderr,"stdin is closed or I/O error\n");
                }else if(success == 0){
                    if( __DEBUG ){
                        fprintf(stderr,"Some input was available, but did not make sense for a double.\n");
                        fprintf(stderr,"Purgin stdin\n");
                    }
                    __fpurge(stdin);
                }else if(success == 1){
                    //success
                    if( __DEBUG )
                        fprintf(stderr,"Success getting matrix [%i][%i]\n",i ,j);
                }
            }while(!success);
        }
    }
    /**/
}

void row_m_swap(double (*matrix)[N] , int f0, int f1){
    double aux;
    for(int i=0;i<N;i++){
        aux = matrix[f0][i];
        matrix[f0][i] = matrix[f1][i];
        matrix[f1][i] = aux;
    }
}


void short_matrix(double (*m)[N] ){
    if( m[0][0]>=m[1][0]){
        if( m[1][0]>=m[2][0] )
            if( __DEBUG )
                fprintf(stderr,"No shorting needed\n"); // filas ordenadas
        else{ // fila 2 > fila 1
            if( __DEBUG )
                fprintf(stderr,"swap rows 1 and 2\n");
            row_m_swap(m, 1, 2);
            //call again
            short_matrix(m);
            }
    }else{ // fila 1 > fila 0
        if( __DEBUG )
            fprintf(stderr,"swap rows 0 and 1\n");
        row_m_swap(m, 0, 1);
        //call again
        short_matrix(m);
    }
}

void triangulate_matrix(double (*matrix)[N] ){
    short_matrix(matrix); //short

    double (*m)[N]=matrix; // more pointers!!!, 'cause we want to reduce failling points
     
    double n0,n1,n2/*,n3,n4*/;

    n0=(m[1][0]/m[0][0]);
    if( __DEBUG )
        fprintf(stderr,"n0:%lf\n", n0);
    for(int i=0;i<N;i++){
        m[1][i]-=(n0*m[0][i]);
    }

    n1=(m[2][0]/m[0][0]);
    if( __DEBUG )
        fprintf(stderr,"n1:%lf\n", n1);
    for(int i=0;i<N;i++){
        m[2][i]-=(n1*m[0][i]);
    }

    n2=(m[2][1]/m[1][1]);
    if( __DEBUG )
        fprintf(stderr,"n2:%lf\n", n2);
    for(int i=0;i<N;i++){
        m[2][i]-=(n2*m[1][i]);
    }
}

int main(){

    double matrix[3][3]
    /*={
        {0,0,0},{0,0,0},{0,0,0}
    }*/
    /*={
        {1,2,3},{4,5,6},{7,8,9}
    }*/
    ;

/*
    //ask_matrix( matrix );
    print_matrix(matrix);
    printf("\n");
    row_m_swap(matrix, 1, 2);
    print_matrix(matrix);
    printf("\n");
    short_matrix(matrix);
    print_matrix(matrix);
    printf("\n");
    triangulate_matrix(matrix);
    print_matrix(matrix);

*/
    ask_matrix( matrix );
    printf("Your matrix is:\n");
    print_matrix(matrix);
    printf("\nTriangulating...\n\n");
    triangulate_matrix(matrix);
    printf("Your triangulated matrix is:\n");
    print_matrix(matrix);



/**/

/**/

    return EXIT_SUCCESS;
}
