#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define M 100

#define verbose 0

int ask_int(char const *text){
    unsigned int num;
    int success;
    do{
        printf("%s", text);
        success = scanf(" %u", &num);

        if(success == EOF){
            if( verbose ) fprintf(stderr,"stdin is closed or I/O error\n");
        }else if(success == 0){
            if( verbose ){
                fprintf(stderr,"Some input was available, but did not make sense f    or a double.\n");
                fprintf(stderr,"Purgin stdin\n");
            }
            __fpurge(stdin);
        }else if(success == 1){
            //success
            if( verbose ) fprintf(stderr,"Success getting int\n");
        }
    }while(!success);
    return num;
}

int main(){

    // declaration of initial size and array pointer
    unsigned int msize=M;
    unsigned int *arr = NULL;

    //int  arr[M];
    //int rem=M, remo=M;
    unsigned int rem=msize, remo=msize; //
    //int *p_next = &arr[3];
    unsigned int next;

    // Set new size, allocate memory, and set remaining size
    msize=ask_int("Introduce el numero maximo: ")+1;
    arr = (unsigned int*) malloc( msize*sizeof(unsigned int)  );
    rem=msize;
    remo=msize;

    for(unsigned int i=0; i<msize; i++)
        arr[i]=i;

    for(unsigned int i=2; i<rem; i++){
        if(verbose) printf("dividing by arr[%i] (%i) \n", i,arr[i]);
        next=i+1;
        for(unsigned int j=(i+1); j<rem; j++){
            if(  !(arr[j]%arr[i]) ){
                if(verbose) printf("\tarr[%i] (%i) confirmed not prime\n", j,arr[j]);
                remo--;
            }else{
                if(verbose) printf("\tarr[%i] (%i) may be prime\n", j,arr[j]);
                arr[next]=arr[j];
                next++;
                /*
                *p_next=arr[j];
                p_next++;
                */
            }
        }
        rem=remo;
        arr = (unsigned int*) realloc (arr, rem * sizeof(unsigned int));


    }

    for(unsigned int i=0; i<rem; i++)
        printf("%i, ", arr[i]);
    printf("\n");
    free(arr);
    return EXIT_SUCCESS;
}
