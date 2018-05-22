#include "raytracer.h"


int main(){
    /*
    Ellipse E;
    E.a = E.b = E.c = 5;

    E.x = E.y = 0;
    E.z = -10;

    Plane object;
    object.a = object.b = 0;
    object.c = 1;
    object.x = object.y = 0;
    object.z = -10;

    Brick object;
    object.a = setPoint(0, 0, 0);
    object.b = setPoint(100, 0, 0);
    object.c = setPoint(100, 0, 100);
    object.d = setPoint(0, 0, 100);
    object.e = setPoint(0, 100, 0);
    object.f = setPoint(100, 100, 0);
    object.g = setPoint(100, 100, 100);
    object.h = setPoint(0, 100, 100);
    */
    Tetrahedron object;
    object.a = setPoint(-100,0,0);
    object.b = setPoint(100,0,0);
    object.c = setPoint(0,0,-100);
    object.d = setPoint(0,50,50);

    Plane observer;
    observer.a = observer.b = 0;
    observer.c = 1;
    observer.x = observer.y = 0;
    observer.z = -10;

    Point imageOrigin;
    imageOrigin.x = -500;
    imageOrigin.y =  500;
    imageOrigin.z =    0;

    int resolution = 1000;

    rayTracer(object, observer, imageOrigin, resolution);

    return 0;
}
