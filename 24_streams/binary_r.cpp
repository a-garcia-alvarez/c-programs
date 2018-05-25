#include<stdio.h>
#include<stdlib.h>

#include"binary_dato0.h"

/*
typedef struct
{
  int    num[22];
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

void readData0(Data0 p_d)
{
    printf("num1: %i\n",    *p_d.num);
    printf("num2: %i\n",    p_d.num[1]);
    printf("nombre: %s\n",  p_d.nombre);
    printf("dob: %lf\n",    p_d.dob);

}
*/
int main(){

    Data0 dat0,dat1,dat2;
    char fileName[30];
    FILE *pf=NULL;

    printf("filename [max 30c]: ");
    scanf(" %s", fileName);

    pf = fopen(fileName, "r");

    fread(&dat0,sizeof(Data0),1,pf);
    fread(&dat1,sizeof(Data0),1,pf);
    fread(&dat2,sizeof(Data0),1,pf);

    fclose(pf);

    readData0(dat0);
    readData0(dat1);
    readData0(dat2);
    
    return EXIT_SUCCESS;
}
