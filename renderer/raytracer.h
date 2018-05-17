#include "lib.h"
#include "ellipse.h"
#include "bmp.h"

//Calculates the ray corresponding to the (0,0) pixel
Line calculateFirstRay (Plane image, Point origin);

//(test version) calculate pixel's color
void rayTracer(Ellipse E, /*Light *list,*/ Plane observer, Point imageOrigin, int resolution);
