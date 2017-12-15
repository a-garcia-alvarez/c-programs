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
 *    Z
 *    |
 *    |
 *    |______ Y
 *    /
 *   /
 *  X
 *
 *  Using Screen Axis XY
 *    ______X
 *   |
 *   |
 *   |
 *   |
 *   Y
 */



int main(){
    double vertice0[D]={ 8, -6, 4 };
    printf("Vcoords: (%lf,%lf,%lf)\n", vertice0[X],vertice0[Y],vertice0[Z]);

    //printf("Scoords: (%lf,%lf)\n", vertice0[0]/vertice0[2],vertice0[1]/vertice0[2]);
    printf("Scoords: (%lf,%lf)\n",vertice0[Y]/vertice0[X] + XSoffset, -vertice0[Z]/vertice0[X] + YSoffset );
    return EXIT_SUCCESS;
}
