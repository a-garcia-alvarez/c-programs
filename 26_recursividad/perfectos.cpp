#include<stdio.h>
#include<stdlib.h>

long long perfecto(long long n);
long long perfecto(long long n, long long d);


long long perfecto(long long n)
{
    return perfecto(n, n-1);
}
long long perfecto(long long n, long long d)
{
    if (d<=1)
        return 1;

    if ( n%d == 0 )
        return d + perfecto(n,d-1);
    else
        return perfecto(n,d-1);

}

int main(){

    //if (tiene_un_divisor(8, 7))
    long long num,min,max;
    long long a;
    int mayores = 0, menores = 0;

    printf("Empezar a buscar a partir de: ");
        scanf(" %lli", &min);
    printf("Terminar de buscar a partir de: ");
        scanf(" %lli", &max);


    for(long long i = min; i<=max; i++)
        if( i == (a = perfecto(i)))
            printf("%lli es perfecto\n", i);
        else
            if( a>i )
                mayores++;
            else
                menores++;

    printf("divisores mas grande: %i\n", mayores);
    printf("divisores mas pequeños: %i\n", menores);
    return EXIT_SUCCESS;
}
