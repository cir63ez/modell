#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "bmp.h"
#include "objects.h"

//Calculates the ray corresponding to the (0,0) pixel
Line calculateFirstRay (Plane image, Point origin);

// Creates the renedered image
void rayTracer(List *objectList, Light *lightList, Plane observer, Point imageOrigin,  int height, int width, double tetaX, double tetaY, double tetaZ);

// Launches the check function corresponding to each object
int testIfLightCutsObject(Light li, List *listOfObject, Point contactPoint);

// Checks if a given point has direct line of sight with a light source
int isLit(Point contactPoint, List *listOfObject, Light *listOfLight, int numberOfLight);
