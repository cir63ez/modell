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
  List * L;

  f = fopen("arguments.txt", 'r');
  P = pointPlaneFile(f);
  height = caractereToNumber(f);
  width = caractereToNumber(f);
  V = normalVectorPlaneFile(f);
  numberObject = caractereToNumber(f);
  numberLight = caractereToNumber(f);
  L = objectFromFile(f);
  fclose(f);
}
