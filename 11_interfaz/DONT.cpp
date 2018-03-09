#include<stdio.h>
#include<stdlib.h>

#define N 4
#define M N

int main(){
	
	char *a=NULL;
	for(int i=1; i < //10000000000
			   21470000000;i++){
		//more_numbers = (int*) realloc (numbers, count * sizeof(int));
		a = (char*) realloc (a, i * sizeof(char));
		//printf("size: %8i\r", i);
		//a = (char*) realloc( a, i*sizeof(char));
		a[i-1]=1;
		}
	scanf("%*i");
	free(a);
	  
	


   	 return EXIT_SUCCESS;
}


