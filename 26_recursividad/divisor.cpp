#include<stdio.h>
#include<stdlib.h>

bool no_primo(int n);
bool no_primo(int n, int d);

int perfecto(int n);
int perfecto(int n, int d);


bool tiene_un_divisor(int dividendo, int posible_divisor)
{

  if(posible_divisor==1)
      return false;

  if( dividendo % posible_divisor == 0 )
      return true;

  return tiene_un_divisor(8, posible_divisor-1);



  //return (posible_divisor==1)? false : (dividendo % posible_divisor) ||tiene_un_divisor(8, posible_divisor-1);
}


bool no_primo(int n)
{
    return no_primo(n,n-1);
}

bool no_primo(int n, int d)
{
    if ( (n%d) == 0)
        return false;
    if (d<=1)
        return true;
    return no_primo(n, d-1);
}


int perfecto(int n)
{
    return perfecto(n, n-1);
}
int perfecto(int n, int d)
{
    if (d<=1)
        return 1;

    if ( n%d == 0)
        return d + perfecto(n,d-1);
    else
        return perfecto(n,d-1);

}

int main(){

    //if (tiene_un_divisor(8, 7))
    int num=1003;

    if ( no_primo(num) )
        printf("El %i tiene al menos un divisor\n", num);
        
    printf("buscar perfecto: ");
    scanf(" %i", &num);
    printf(" %i", perfecto(num));
    
    for(int i = 0; i<600; i++)
        if( i == perfecto(i))
            printf("%i es perfecto\n", i);

    return EXIT_SUCCESS;
}
