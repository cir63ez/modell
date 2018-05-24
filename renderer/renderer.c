#include "file.h"
#include "objects.h"

/* PHP interface
*  Calls raytracer.c
*/

int main(int argc, char **argv) {
    FILE * f;

    Point P;
    int height;
    int width;
    int numberObject;
    int numberLight;
    Vector V;
    List * L;

    f = fopen("./data.txt", "r");

    if(f == NULL) {
        printf("File not found \n");
    } else {
        P = pointPlaneFile(f);
        printf("point %lf %lf %lf \n", P.x, P.y, P.z);
        height = caractereToNumber(f);
        width = caractereToNumber(f);
        V = normalVectorPlaneFile(f);

        numberObject = caractereToNumber(f);
        numberLight = caractereToNumber(f);
        
        L = objectFromFile(f);
    }

    fclose(f);
    free(L);

    return 0;
}
