#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "bmp.h"
#include "objects.h"

//Calculates the ray corresponding to the (0,0) pixel
Line calculateFirstRay (Plane image, Point origin);

//(test version) calculate pixel's color
void rayTracer(Tetrahedron object, /*Light *list,*/ Plane observer, Point imageOrigin, int resolution);

int testIfLightCutsObject(Light li, List *listOfObject, Point c);

int isLit(Point c, List *listOfObject, Light *listOfLight, int numberOfLight);
