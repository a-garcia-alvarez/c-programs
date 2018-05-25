#include<stdio.h>
#include<stdlib.h>
#include"bmp_structs_v2.h"
#include<unistd.h>
#include<string.h>
#include"../some_useful_functions.h"



int main(){

    char file_name[100];
    char * p_char=NULL;
    //
    //fopen()
    p_char = ask_file("");
    strcpy(file_name, p_char);
    free(p_char);


    return EXIT_SUCCESS;
}
