#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "file.h"

/* PHP interface
*  Calls raytracer.c
*/

int main(int argc, char **argv){
    FILE * f;

    Point P;
    int height;
    int width;
    int numberObject;
    int numberLight;
    Vector V;

    f = fopen("arguments.txt", 'r');
    P = pointPlaneFile(f);
    height = caractereToNumber(f);
    width = caractereToNumber(f);
    angleX = caractereToNumber(f);
    angleY = caractereToNumber(f);
    angleZ = caractereToNumber(f);
    numberObject = caractereToNumber(f);
    numberLight = caractereToNumber(f);

    L = objectFromFile(f);
    afficheList(L);
    rayTracer();
    fclose(f);
    free(L);
    return 0;
}
