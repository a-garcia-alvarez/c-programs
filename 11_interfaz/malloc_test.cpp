#include<stdio.h>
#include<stdlib.h>

#define N 4
#define M N

int main(){

	char** c;
	if (( c = (char**) malloc( N*sizeof( char* ))) == NULL )
	 { /* error */ }
	 
	 for ( int i = 0; i < N; i++ )
	{

		if (( c[i] = (char*) malloc( N*sizeof( char ) )) == NULL )
		 { /* error */ }
	}
	
	/* 
	 * access matrix elements: c[i] give you a pointer
	 * to the row array, c[i][j] indexes an element
	 */
	
	for( int i=0;i<N;i++)
	  for( int j=0;j<M;j++)
		c[i][j] = 'a'+i+j;
	
	for( int i=0;i<N;i++)
	  for( int j=0;j<M;j++)	
	  	printf("c[%i][%i]: %c\n",i,j,c[i][j]);
	  	
	for ( int i = 0; i < N; i++ )
		free(c[i]);
	free(c);
	
	/*
	char b[N][M] = (char) malloc( N*M*sizeof( char ) );
	//b[0][0]=15;
	//printf("%c\n",b[0][0]);
	for( int i=0;i<N;i++)
	  for( int j=0;j<M;j++)
		b[i][j] = 'a'+i+j;
	
	
	for( int i=0;i<N;i++)
	  for( int j=0;j<M;j++)	
	  	printf("b[%i][%i]: %c\n",i,j,b[i][j]);
	  	
	  free(b);
	  */
	


   	 return EXIT_SUCCESS;
}


