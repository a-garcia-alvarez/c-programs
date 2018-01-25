#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define N 4

#define __DEBUG 1


void print_matrix(double (*matrix)[N] ){
    //
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%10.4lf", matrix[i][j]);
        }
        printf("\n");
    }
}
void print_matrix_debug(double (*matrix)[N] ){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            fprintf(stderr,"%10.4lf", matrix[i][j]);
        }
        fprintf(stderr,"\n");
    }

}

bool checkd_zero(double d){
    if( d<0.00000000001 && d>(-0.00000000001)){
        return true;
    }else
        return false;
}

void ask_matrix(double (*matrix)[N] ){
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

double normalizar_fila(double (*m)[N], int row ){
    double coef;
    coef=m[row][row];
    for(int i=0;i<N;i++){
        m[row][i]/=coef;
    }
    return coef;
}

int gaus_matrix(double (*matrix)[N] ){
    /*
     * Normalizar fila n
     *  (Div fn/fnn)
     *
     * Apuntar coeficiente
     *
     * Conseguir 0s en columna n de filas>n
     *
     *
     */
    double (*m)[N]=matrix;
    double coef, d, n;
    bool d0=false;
    d=1;
    for(int j=0; j<N;j++){ // se recorre todas las filas
    
        /* Check if matrix[j][j] is 0 */
        while( checkd_zero(m[j][j]) ){
            if( __DEBUG ) fprintf(stderr,"m[%i][%i] == 0\t (%lf) \n",j,j, m[j][j]);
            // last row
            if( checkd_zero(m[j][j]) && ( j==(N-1) ) ){
                d0=true;
                break;
            }
            for(int s=(j+1);s<N;s++){
                if( checkd_zero(m[s][j]) && ( s==(N-1) ) ){
                    d0=true;
                    break;
                }
                if( ! checkd_zero(m[s][j]) ){
                    if( __DEBUG ) fprintf(stderr,"swaping f[%i] and f[%i]\n",j,s);
                    row_m_swap(matrix ,j,s);
                    break;
                }
            }
            if (d0) break;
        }
        if( d0 ){
            if( __DEBUG ) fprintf(stderr,"everything 0\n");
            d=0;
            break;
        }
        /* end Check if matrix[j][j] is 0 */
        
        // normalizar fila, ajustar en base a coeficiente
        if( __DEBUG ) fprintf(stderr,"normalizar fila %i\n",j);
        d*=normalizar_fila(matrix,j);
        if( __DEBUG ) print_matrix_debug(m);
        //conseguir 0s
        if( __DEBUG ) fprintf(stderr,"fila %i\n",j);
        for(int a=j+1;a<N;a++){
            if( __DEBUG ){ fprintf(stderr,"0ando fila %i\n",a); }

            n=m[a][j]/m[j][j];
            for(int i=j;i<N;i++){
                //printf("j: %i\ta: %i\ti: %i\n", j,a,i);
                //n=m[a][j]/m[j][j];
                m[a][i]-=n*m[j][i];
            }
            if( __DEBUG  ){
                fprintf(stderr,"\n");
                print_matrix_debug(m);
                fprintf(stderr,"\n");
            }
        }
        if( __DEBUG  ){
            fprintf(stderr,"\n\td: %lf\n",d);
        }
    }
}



int main(){

    double matrix[N][N]
        /*={
          {0,0,0},{0,0,0},{0,0,0}
          }*/
        /*={
          {2,2,3},{4,5,6},{7,8,9}
          }*/
        /*={
            {1,1,3,-2},{2,-4,7,2},{3,-2,9,-1},{1,3,-1,-1}
        }*/
        ={
            {1,2,3,4},{1,2,3,4},{8,9,10,11},{12,13,14,15}
        }
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
    //ask_matrix( matrix );
    printf("Your matrix is:\n");
    print_matrix(matrix);
    /**/
    printf("\n");
    //normalizar_fila(matrix,0);
    gaus_matrix(matrix);
    /**/
    /*printf("\nTriangulating...\n\n");
      triangulate_matrix(matrix);
      printf("Your triangulated matrix is:\n");
      */
    print_matrix(matrix);



    /**/

    /**/

    return EXIT_SUCCESS;
}
