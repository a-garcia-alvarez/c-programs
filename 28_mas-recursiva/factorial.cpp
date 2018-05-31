#include<stdio.h>
#include<stdlib.h>

long long factorial(int n)
{
    if(n<1)
        return 1;
    return n * factorial(n-1);
}

int main(){

    int num;
    long long fact=1;
    printf("De que te hago el factorial, majo?\n");
    printf("[0-66) ");
    printf(">");
    scanf(" %i", &num);
    printf("El factorial de %i es %lli\n",num, factorial(num));

    /*
    while (fact)
        printf("num: %i, !num: %lli", num++, fact = factorial(num));
    */
    return EXIT_SUCCESS;
}
