#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "file.h"

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
    fclose(f);


     fclose(f);
    
    Element * currentElement = L->head;
    while(currentElement != NULL) {
        if(currentElement->type != LIGHT_TYPE) {
            addElementList(currentElement, listObjects); // BUG HEREf
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