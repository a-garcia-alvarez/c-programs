#include<stdio.h>
#include<stdlib.h>

#include"binary_dato0.h"

/*
typedef struct
{
  int    num[2];
  char   nombre[20];
  double dob;
} Data0;

void writeData0(Data0 *p_d)
{
    printf("num 1: ");
    scanf(" %i", &(*p_d).num[0]);
    printf("num 2: ");
    scanf(" %i", (p_d->num +1) );
    printf("nombre: ");
    scanf(" %s", p_d->nombre);
    printf("dob: ");
    scanf(" %lf", &p_d->dob);
}
*/

int main(){

    Data0 dat0,dat1,dat2;
    char fileName[30];
    FILE *pf=NULL;

    writeData0(&dat0);
    writeData0(&dat1);
    writeData0(&dat2);

    printf("filename [max 30c]: ");
    scanf(" %s", fileName);

    pf = fopen(fileName, "w");

    fwrite(&dat0,sizeof(Data0),1,pf);
    fwrite(&dat1,sizeof(Data0),1,pf);
    fwrite(&dat2,sizeof(Data0),1,pf);

    fclose(pf);
    
    return EXIT_SUCCESS;
}
