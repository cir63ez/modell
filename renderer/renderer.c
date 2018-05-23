#include "file.h"
#include "objects.h"

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

    printf("yo\n");

    f = fopen("./data.txt", "r");
    if(f == NULL){
      printf("File not found \n");
    }
    else {
      P = pointPlaneFile(f);
      printf("point %lf %lf %lf \n", P.x, P.y, P.z);
      height = caractereToNumber(f);
      width = caractereToNumber(f);
      V = normalVectorPlaneFile(f);
      printf("dimensions %d x %d \n", height, width);
      printf("vector %lf %lf %lf \n", V.x, V.y, V.z);

      numberObject = caractereToNumber(f);
      numberLight = caractereToNumber(f);
      printf("numberO %d numberL %d \n", numberObject, numberLight);
      
      /*char * name = caractereToName(f);
      printf("name %s\n",name);
      Ellipse E = getEllipse(f);
      printf("ellipse %lf %lf %lf %lf %lf %lf \n",E.a,E.b,E.c,E.x,E.y,E.z);
      char * nameB = caractereToName(f);
      printf("name %s\n",nameB);
      Brick B = getBrick(f);
      printf("brick %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf\n",B.a.x,B.a.y,B.a.z,B.b.x,B.b.y,B.b.z,B.c.x,B.c.y,B.c.z,B.d.x,B.d.y,B.d.z,B.e.x,B.e.y,B.e.z,B.f.x,B.f.y,B.f.z,B.g.x,B.g.y,B.g.z,B.h.x,B.h.y,B.h.z);
      char * nameL = caractereToName(f);
      Light L = getLight(f);
      printf("light %s %lf %lf %lf \n", nameL, L.lightSource.x, L.lightSource.y, L.lightSource.z);*/

      L = objectFromFile(f); 
    }
    fclose(f);
    free(L);
    return 0;
}
