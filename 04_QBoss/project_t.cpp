#include<stdio.h>
#include<stdlib.h>

#define XSoffset 0
#define YSoffset 0

#define D 3
#define X 0
#define Y 1
#define Z 2

// USING XYZ Axis
/*
 *     Z    Y
 *     \   |
 *      \  |
 *       \ |
 *  X_____\|
 *
 *  Using Screen Axis XY
 *    
 *   Y
 *   |
 *   |
 *   |
 *   |______X
 */



int main(){
    double vertice0[D]={ 8, -6, 4 };
    // Entrada de datos
    printf("(x., y., z.):");
    scanf(" ( %lf , %lf , %lf ) ", &vertice0[X], &vertice0[Y], &vertice0[Z]);
    
    //printf("double is %lu bytes\n", sizeof(double));
    
    // Salida de datos
    printf("Vcoords: (%lf,%lf,%lf)\n", vertice0[X],vertice0[Y],vertice0[Z]);

    printf("Scoords: (%lf,%lf)\n", vertice0[X]/vertice0[Z],vertice0[Y]/vertice0[Z]);
    
    return EXIT_SUCCESS;
}
