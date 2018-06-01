#include<stdio.h>
#include<stdlib.h>
#include"../some_useful_functions.h"

long long factorial(int n)
{
    if(n<1)
        return 1;
    return n * factorial(n-1);
}


double cont_frac(int *p, int index, int index_len)
{
    if(index == index_len-1)
        return p[index];
    if( index<index_len)
        return p[index] + 1/cont_frac(p, index+1, index_len);
    else
        return 1;
}

int * añadir_elem( int *p,int *i, int *il)
{
    int num;
    int *rp = p;
    ask_int("Introduce un numero: ", &num);
    rp = realloc(rp, (*i +1)*sizeof(int));
    return rp;
}




int main(){

    int num;
    double res;
    
    int *p_lista = NULL;
    int arr[]={1,2,3};
    printf(" %lf\n", cont_frac(arr,0,3));
    
    
    
    
    return EXIT_SUCCESS;
}
