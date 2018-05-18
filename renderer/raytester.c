#include "raytracer.h"


int main(){
    Ellipse E;
    E.a = E.b = E.c = 5;

    E.x = E.y = 0;
    E.z = -10;

    Plane observer;
    observer.a = observer.b = 0;
    observer.c = 1;
    observer.x = observer.y = 0;
    observer.z = 10;

    Point imageOrigin;
    imageOrigin.x = -100;
    imageOrigin.y =  100;
    imageOrigin.z =    0;

    int resolution = 200;

    rayTracer(E, observer, imageOrigin, resolution);

    return 0;
}
