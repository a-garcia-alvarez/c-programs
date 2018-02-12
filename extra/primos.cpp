#include<stdio.h>
#include<stdlib.h>

#define M 15000

#define verbose 0

int main(){

    int  arr[M];
    int rem=M, remo=M;
    //int *p_next = &arr[3];
    int next;

    for(int i=0; i<M; i++)
        arr[i]=i;

    for(int i=2; i<rem; i++){
        if(verbose) printf("dividing by arr[%i] (%i) \n", i,arr[i]);
        next=i+1;
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
    }

    for(int i=0; i<rem; i++)
        printf("%i, ", arr[i]);
    printf("\n");
    return EXIT_SUCCESS;
}
