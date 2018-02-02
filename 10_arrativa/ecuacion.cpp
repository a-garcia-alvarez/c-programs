#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define N 3
#define M N+1

#define __DEBUG 0


void print_matrix(double (*matrix)[M] ){
    //
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%10.4lf", matrix[i][j]);
        }
        printf("\n");
    }
}
void print_matrix_debug(double (*matrix)[M] ){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
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

void ask_matrix(double (*matrix)[M] ){
    //
    int success=0;
    printf("Introduce una mariz de %i x %i :\n", N, M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            do{
                if( __DEBUG ) fprintf(stderr,"Getting matrix [%i][%i]\n",i ,j);
                printf("Introduce el valor [%i][%i]:\n >",i ,j);
                success = scanf(" %lf", &matrix[i][j]);
                if(success == EOF){
                    if( __DEBUG ) fprintf(stderr,"stdin is closed or I/O error\n");
                }else if(success == 0){
                    if( __DEBUG ){
                        fprintf(stderr,"Some input was available, but did not make sense for a double.\n");
                        fprintf(stderr,"Purgin stdin\n");
                    }
                    __fpurge(stdin);
                }else if(success == 1){
                    //success
                    if( __DEBUG ) fprintf(stderr,"Success getting matrix [%i][%i]\n",i ,j);
                }
            }while(!success);
        }
    }
    /**/
}

void row_m_swap(double (*matrix)[M] , int f0, int f1){
    double aux;
    for(int i=0;i<M;i++){
        aux = matrix[f0][i];
        matrix[f0][i] = matrix[f1][i];
        matrix[f1][i] = aux;
    }
}


void short_matrix(double (*m)[M] ){
    if( m[0][0]>=m[1][0]){
        if( m[1][0]>=m[2][0] )
            if( __DEBUG )
                fprintf(stderr,"No shorting needed\n"); // filas ordenadas
            else{ // fila 2 > fila 1
                if( __DEBUG ) fprintf(stderr,"swap rows 1 and 2\n");
                row_m_swap(m, 1, 2);
                //call again
                short_matrix(m);
            }
    }else{ // fila 1 > fila 0
        if( __DEBUG ) fprintf(stderr,"swap rows 0 and 1\n");
        row_m_swap(m, 0, 1);
        //call again
        short_matrix(m);
    }
}

void triangulate_matrix(double (*matrix)[M] ){
    short_matrix(matrix); //short

    double (*m)[M]=matrix; // more pointers!!!, 'cause we want to reduce failling points

    double n0,n1,n2/*,n3,n4*/;

    n0=(m[1][0]/m[0][0]);
    if( __DEBUG ) fprintf(stderr,"n0:%lf\n", n0);
    for(int i=0;i<M;i++){
        m[1][i]-=(n0*m[0][i]);
    }

    n1=(m[2][0]/m[0][0]);
    if( __DEBUG ) fprintf(stderr,"n1:%lf\n", n1);
    for(int i=0;i<M;i++){
        m[2][i]-=(n1*m[0][i]);
    }

    n2=(m[2][1]/m[1][1]);
    if( __DEBUG ) fprintf(stderr,"n2:%lf\n", n2);
    for(int i=0;i<M;i++){
        m[2][i]-=(n2*m[1][i]);
    }
}

double normalizar_fila(double (*m)[M], int row ){
    double coef;
    coef=m[row][row];
    for(int i=0;i<M;i++){
        m[row][i]/=coef;
    }
    return coef;
}

int gaus_matrix(double (*matrix)[M] ){
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
    double (*m)[M]=matrix;
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
                    d*=(-1);
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
            for(int i=j;i<M;i++){
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
    return d;
}



int main(){

    double det, x[N];
    int cima=0;
    double matrix[N][M]
        /*={
          {0,0,0},{0,0,0},{0,0,0}
          }*/
        /*={
          {2,2,3},{4,5,6},{7,8,9}
          }*/
        /*={
            {1,1,3,-2},{2,-4,7,2},{3,-2,9,-1},{1,3,-1,-1}
        }*/
        /*={
            {1,2,3,4},{1,2,3,4},{8,9,10,11},{12,13,14,15}
        }*/
    ;

    ask_matrix( matrix );
    printf("Your matrix is:\n");
    print_matrix(matrix);
    /**/
    printf("\n");
    //normalizar_fila(matrix,0);
    det=gaus_matrix(matrix);


    /**/
    /*printf("\nTriangulating...\n\n");
      triangulate_matrix(matrix);
      printf("Your triangulated matrix is:\n");
      */

    if(det){
        /*
        //c0
        x[cima++]=matrix[N-1][M-1];
        printf("z: %.2lf\n", x[cima-1]);
        //c1
        x[cima++]=matrix[N-2][M-1] - matrix[N-2][M-2]*x[cima-1];

        //c2
        x[cima++]=matrix[N-3][M-1] - matrix[N-3][M-3]*x[cima-1]
                                   - matrix[N-3][M-2]*x[cima-2];


        //c3
        x[cima++]=matrix[N-4][M-1] - matrix[N-4][M-4]*x[cima-1]
                                   - matrix[N-4][M-3]*x[cima-2]
                                   - matrix[N-4][M-2]*x[cima-3];

        //c4
        x[cima++]=matrix[N-5][M-1] - matrix[N-5][M-5]*x[cima-4]
                                   - matrix[N-5][M-4]*x[cima-3]
                                   - matrix[N-5][M-3]*x[cima-2]
                                   - matrix[N-5][M-2]*x[cima-1];
        */
           /*
           for(int i=0;i<N;i++){
           x[cima]=matrix[(N-1)- i][M-1];
           for(int a=0;a<i;a++)
           x[cima]-=matrix[N-1][M-1];
           }
           */
        /**/
            for(int i=0; i<N; i++){
                x[i]=0;
                if( __DEBUG  ){
                    fprintf(stderr,"i: %i\n",i);
                    fprintf(stderr,"x[%i]=matrix[((N-1)-%i)][M-1];\n",i,i);
                }
                x[i]=matrix[((N-1)-i)][M-1];
                for(int j=i; j>0; j--){
                    if( __DEBUG   ){
                        fprintf(stderr,"\tj: %i\n",j);
                        //fprintf(stderr,"x[%i]-=  matrix[N-1-%i][M-1-%i]*x[%i-1];\n",i,i,j,j);
                    }
                    x[i]-=  matrix[N-1-i][M-1-j]*x[j-1];
                }
                if( __DEBUG   ) fprintf(stderr,"x[%i]= %lf\n",i, x[i]);
            }
	  /**/
    }else{
       printf("det: 0, system not solvable\n");
    }
    print_matrix(matrix);
    printf("\n matrix determinant is: %.4lf\n", det);
    /*
    printf("z: %.2lf \t y: %.2lf \t x: %.2lf\n",x[0],x[1],x[2]);
    printf("a: %.2lf \t b: %.2lf\n",x[3],x[4]);
    */
    for(int i=0;i<N;i++){
        printf("incognita [%i]: %.4lf\n",i, x[i]);
    }



    /**/

    /**/

    return EXIT_SUCCESS;
}
