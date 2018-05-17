#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "raytracer.h"


int main(){
    Ellipse E;
    E.a = E.b = E.c = 0.00000000000000000025;

    E.x = E.z = 0;
    E.y = 0;

    Plane observer;
    observer.a = observer.b = 0;
    observer.c = 1;
    observer.x = observer.y = observer.z = 0;

    Point imageOrigin;
    imageOrigin.x = -1000;
    imageOrigin.y = 1000;
    imageOrigin.z = 0;

    int resolution = 2000;

    rayTracer(E, observer, imageOrigin, resolution);

    /**
    for (int i = 0; i < resolution * resolution; i++){
        printf("%3d ", image[i].red);
        if(i % resolution == 0){
            printf("\n");
        }
    }
    */
return 0;
}
