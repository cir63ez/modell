#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "bmp.h"
#include "objects.h"

// Calculates the ray corresponding to the (0,0) pixel
Line calculateFirstRay(Plane image, Point origin);

// (test version) calculate pixel's color
void rayTracer(List *objectList, /*Light *Lightlist,*/ Plane observer, Point imageOrigin, int resolution);

// Launch the check function depending of the object
int testIfLightCutsObject(Light li, List *objectList, Point c);

// Launch the check fonctions for each point of light
int isLit(Point c, List *objectList, Light *listOfLight, int numberOfLight);
