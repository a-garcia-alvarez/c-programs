#ifndef __B_DATO0_H__
#define __B_DATO0_H__


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

void readData0(Data0 p_d)
{
    printf("num1: %i\n",    *p_d.num);
    printf("num2: %i\n",    p_d.num[1]);
    printf("nombre: %s\n",  p_d.nombre);
    printf("dob: %lf\n",    p_d.dob);
}


#endif
