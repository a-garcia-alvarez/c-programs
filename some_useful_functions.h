#ifndef __SOME_USEFUL_FUNCTIONS_H__
#define __SOME_USEFUL_FUNCTIONS_H__

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include <string.h>


#define NDEBUG
#ifndef NDEBUG
#define DEBUG(...) fprintf(stderr,__VA_ARGS__);
#else
#define DEBUG(...)
#endif

bool ask_YN(){
    int success=0;
    char ans;
    do{
        success=scanf(" %c", &ans);

        if(success == EOF){
            DEBUG(stderr,"stdin is closed or I/O error\n");
        }else if(success == 0){
            DEBUG("Some input was available, but did not make sense f    or a double.\n");
            DEBUG("Purgin stdin\n");
            __fpurge(stdin);
        }else if(success == 1){
            //success
            DEBUG("Success getting int\n");
        }

        if ( ans == 'S' || ans == 's' || ans == 'N' || ans == 'n' || ans == 'y' || ans == 'Y' ){
            success=1;
        }else{
            printf("\tResponda con 'S', 's', 'N' o 'n'\n");
            success=0;
        }
    }while(!success);

    if (ans=='S' || ans=='s' || ans == 'y' || ans == 'Y' )
        return true;
    else
        return false;
}

char * ask_file(char string[])
{
    /*
     * You MUST free this malloc later on your code
     */
    char file_name[100];
    char *p_name;
    do{
        printf("Introduzca el nombre o path del archivo\n >");
        scanf(" %s", file_name);
        // check if file exist
        if (access( file_name, F_OK ) != -1){
            // it does
            printf("El nombre del fichero es %s\n"
                    "is this ok? [y/n]", file_name );
            if (ask_YN()) break; else continue;
        }else{
            //it doesn't
            printf("The file %s doesn't exist\n", file_name);
        }
    }while(true);
    p_name = (char*) malloc( strlen(file_name)*sizeof(char) );
    memcpy(p_name, file_name, strlen(file_name)*sizeof(char));
    return p_name;
}

#endif
