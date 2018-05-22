#include "file.h"
#include "objects.h"

/* PHP interface
*  Calls raytracer.c
*/

int main(int argc, char **argv){
  FILE * f;

 /* Point P;
  int height;
  int width;
  int numberObject;
  int numberLight;
  Vector V;
  List * L;*/

  printf("yo\n");

  f = fopen("../data.txt", "r");
  if(f == NULL){
    printf("File not found \n");
  }
  //printf("yo\n");
  /*double non = (double)caractereToNumber(f);
  printf("%lf", non);
  
  else {
    P = pointPlaneFile(f);
    printf("point %lf %lf %lf \n", P.x, P.y, P.z);
    height = caractereToNumber(f);
    width = caractereToNumber(f);
    V = normalVectorPlaneFile(f);
    printf("vector %lf %lf %lf \n", V.x, V.y, V.z);
    printf("dimensions %d x %d \n", height, width);
    numberObject = caractereToNumber(f);
    numberLight = caractereToNumber(f);
    printf("numberO %d numberL %d \n", numberObject, numberLight);
    L = objectFromFile(f);
  }
  fclose(f);
  free(L);*/
  return 0;
}
