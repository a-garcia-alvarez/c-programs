#include<stdio.h>
#include<stdlib.h>

bool /*int*/ es_par(int op){
    /*
    op = (op%2==0) ? 1 : 0;
    return op;
    */
    //return (op%2==0) ? 1 : 0;
    //return (op%2==0) ? true : false;
    //return (op%2) ? 0 : 1;
    //return (op%2) ? false : true;
    //return (op%2==0);
    return !(op%2);
}

int main(){

    if (es_par(2))
        printf("Es par. \n");
    return EXIT_SUCCESS;
}
