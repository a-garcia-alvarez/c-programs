#include<stdio.h>
#include<stdlib.h>

void imprime(char * letra)
{

    if(*letra != '\0' )
    {
        printf("%c", *letra);
        imprime(letra+1);
    }
}
void imprimev2(char * letra)
{
    if (*letra != '\0')
    {
        printf("%c", *letra);
        imprimev2(letra+1);
    }else
        printf("\n");
    printf("%c", *letra);
}

int imprime_plus(char * letra)
{
    return (*letra != '\0') && printf("%c", *letra) && imprime_plus(letra+1);
}

void imprimev3(char * letra)
{
  printf("%c",*letra);
   if (*(letra+1) != '\0')
       imprimev3(letra+1);
}

int main(){

    char frase[]="dabale arroz a la zorra el abad";
    char *letra=frase;

    imprime(letra);

    printf("\n\n\n");

    imprimev2(letra);
    printf("\n\n\n");
    imprime_plus(letra);
    printf("\n");
    return EXIT_SUCCESS;
}
