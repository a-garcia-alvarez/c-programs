#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
#include<strings.h>

#define BUFFER_SIZE 5
#define __DEBUG 1

int ask_numpal(){
    int success=0,num=0;
    if( __DEBUG  ) fprintf(stderr,"Entering ask_numpal()");
    printf("\n\n");
    do{
        printf("¿Cuantos palabros vos va a querer escribir?\n  > ");
        success = scanf(" %i",&num );
        if(success == EOF){
            if( __DEBUG ) fprintf(stderr,"stdin is closed or I/O error\n");
        }else if(success == 0){
            if( __DEBUG ){
                fprintf(stderr,"Some input was available, but did not make sense for a double.\n");
                fprintf(stderr,"Purgin stdin\n");
            }
            __fpurge(stdin);
        }else if(success == 1){
            //success
            if( __DEBUG ) fprintf(stderr,"Success getting number\n");
        }
    }while(!success);
    if( __DEBUG   ) fprintf(stderr,"Exitting ask_numpal()\n");

    return num;
}

int new_item(){
    //
}

int main(){

    char **p_list=NULL;
    int list_n=1, list_c=1;
    char buffer[BUFFER_SIZE];

    // ask number of pointers
    list_n = ask_numpal();

    //create pointers
    p_list = (char**) malloc( sizeof(char*) * list_n );

    __fpurge(stdin);
    // Ask the data
    for(int i=0;i < list_n; i++ ){
        int size=0, terminated=0;
        printf("metame uté el palabro numer %i\n ",i+1);
        do{
          // get from stdin to buffer
          fgets(buffer,BUFFER_SIZE,stdin);
          if( __DEBUG   ) fprintf(stderr,"\n\t fgets readed: \"%s\"\n",buffer);


          if( __DEBUG  ) fprintf(stderr," \t\"size\" size  before: %i\n",size);
          // add buffer lenht to srting lenght
          size += strlen(buffer);
          if( __DEBUG   ) fprintf(stderr," \t\"size\" size  after: %i\n",size);

          // reallocating space
          // SPACE!!!!!!!!!
          *(p_list + i)= (char*) realloc(*(p_list + i), size);


          strcpy( (*(p_list + i)+strlen(*(p_list + i))), buffer);
          if( __DEBUG    ) fprintf(stderr,"\t allocated string state: \"%s\"\n",*(p_list + i));

          if( strstr(buffer,"\n") != NULL){
              // \n found, string reading is terminated
              terminated=1;
          }else{
              // \n not found
              //printf("raaaaaaaaaaro\n ");
          }
        }while(!terminated);
    }

    // This is a PoC
    /*
    for(int i = 0; i < list_n; i++ ) {
      *(p_list + i) = (char*) malloc( sizeof(char*) * 10 );
      **(p_list + i)='a'+i;
    }

    for(int i = 0; i < list_n; i++ ){
        printf("%i, %s\n", i, *(p_list + i));
    }
    */

    for(int i = 0; i < list_n; i++ ){
        free( *(p_list + i));
    }
    free(p_list);

    return EXIT_SUCCESS;
}
