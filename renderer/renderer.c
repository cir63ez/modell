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
  Vector V;

  f = fopen("arguments.txt", 'r');
  P = pointPlaneFile(f);
  height = caractereToNumber(f);
  width = caractereToNumber(f);
  V = normalVectorPlaneFile(f);
  
  fclose(f);
}
