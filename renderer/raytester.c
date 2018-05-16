#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "raytracer.h"
#include "lib.h"


void main(){
    Ellipse E;
    E.a = E.b = E.c = 25;
    E.x = E.z = 0;
    E.y = 50;

    Plane observer;
    observer.a = observer.b = 0;
    observer.c = 1;
    observer.x = observer.y = observer.z = 0;

    Point imageOrigin;
    imageOrigin.x = -100;
    imageOrigin.y = 100;
    imageOrigin.z = 0;

    Rgb *image;
    image = rayTracer(E, observer, imageOrigin, 200);

    for (int i = 0; i < resolution * resolution; i++){
        printf("%3d ", image[i].red);
        if(i % resolution == 0){
            printf("\n");
        }
    }
}
