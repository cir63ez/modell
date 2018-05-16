#include "lib.h"
#include "ellipse.h"
#include "bmp.h"

Line calculateFirstRay (Plane image, Point origin);
void rayTracer(Ellipse E, /*Light *list,*/ Plane observer, Point imageOrigin, int resolution);
