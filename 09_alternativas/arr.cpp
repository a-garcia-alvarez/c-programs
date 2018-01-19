#include<stdio.h>
#include<stdlib.h>

#define N 20

void print_arr(int (*arr),int size){
    printf("print_arr.size=%i", size);
    for(int i=0;i<size;i++)
        printf("arr[%i]: \t%i\n",i,arr[i]);
}
int main(){

    int arr[N];
    int arrs=(int)(sizeof(arr)/sizeof(arr[0]));
    //printf("%lu");
    printf( "array size: %lu bytes\n"
            "cell  size: %lu bytes\n"
            "cols : %lu \n",
            sizeof(arr),
            sizeof(arr[0]),
            sizeof(arr)/sizeof(arr[0])
          );
    //print_arr(arr,arrs);
    arr[0]=1;
    arr[1]=arr[0];

    for(int i=2;i<arrs;i++){
        //printf("%i",i);
        arr[i]=arr[i-1]+arr[i-2];
    }
    print_arr(arr,arrs);
    return EXIT_SUCCESS;
}
