#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

#define M 100

#define verbose 0

int ask_int(char const *text){
    int num;
    int success;
    do{
        printf("%s", text);
        success = scanf(" %i", &num);

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
void print_arr(int *arr,int a){
    for (int i=0; i<a; i++)
        printf("%4i, ",i);
    printf("\n");

    for(int i=0; i<a; i++)
        printf("%4i, ", arr[i]);
    printf("\n");
}

int main(){

    // declaration of initial size and array pointer
    int msize=M;
    int *arr = NULL;

    //int  arr[M];
    //int rem=M, remo=M;
    int rem=msize, remo=msize; //
    //int *p_next = &arr[3];
    int next;

    // Set new size, allocate memory, and set remaining size
    msize=ask_int("Introduce el numero maximo: ")+1;
    arr = (int*) malloc( msize*sizeof(int)  );
    rem=msize;
    remo=msize;

    for(int i=0; i<msize; i++)
        arr[i]=i;

    for(int i=2; i<rem; i++){
        if(true /*verbose*/) printf("dividing by arr[%i] (%i) \n", i,arr[i]);
        next=i+1;
        printf("actual:\n");
        print_arr(arr,rem);
        for(int j=(i+1); j<rem; j++){
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
        arr = (int*) realloc (arr, rem * sizeof(int));
        printf("cribada:\n");
        print_arr(arr,rem);
        printf("\n");


    }
    
    printf("\n\nFinal:\n");
    print_arr(arr,rem);

/*
    for(int i=0; i<rem; i++)
        printf("%i, ", arr[i]);
    printf("\n");
*/
    free(arr);
    return EXIT_SUCCESS;
}
