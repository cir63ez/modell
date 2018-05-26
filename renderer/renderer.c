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
    Plane observer;
    int height;
    int width;
    double angleX;
    double angleY;
    double angleZ;
    int numberObject;
    int numberLight;

    observer.a = observer.b = 0;
    observer.c = 1;
    observer.x = 0;
    observer.y = 0;
    observer.z = 0;

    f = fopen("../data.txt", "r");
    // TODO: in server value: f = fopen("../data.txt", "r");
    
    if(f == NULL) {
        printf("Can't read file");
        exit(0);
    }

    P = pointPlaneFile(f);
    height = caractereToNumber(f);
    width = caractereToNumber(f);
    angleX = caractereToNumber(f);
    angleY = caractereToNumber(f);
    angleZ = caractereToNumber(f);
    numberObject = caractereToNumber(f);
    numberLight = caractereToNumber(f);
    

    List * L;
    List * listObjects = initList();
    Light listLights[numberLight];
    int i = 0;

    L = objectFromFile(f);
    fclose(f);
    

    Element * currentElement = L->head;
    while(currentElement != NULL) {
        if(currentElement->type != LIGHT_TYPE) {
            addElementList(currentElement, listObjects);
        } else {
            listLights[i] = decodeLight(currentElement->object);
            i++;
        }
        currentElement = currentElement->next;
    }

    free(L);

    rayTracer(listObjects, listLights, observer, P, height, width, angleX, angleY, angleZ);


    
    free(listObjects);

    return 0;
}
