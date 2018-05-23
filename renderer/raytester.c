#include "raytracer.h"


int main(){

    Ellipse E;
    E.a = E.b = E.c = 500000;

    E.x = E.y = 0;
    E.z = 1000;

    /*Plane P;
    P.a = P.b = 0;
    P.c = 1;
    P.x = P.y = 0;
    P.z = -10;

    Brick B;
    B.a = setPoint(0, 0, 0);
    B.b = setPoint(100, 0, 0);
    B.c = setPoint(100, 0, 100);
    B.d = setPoint(0, 0, 100);
    B.e = setPoint(0, 100, 0);
    B.f = setPoint(100, 100, 0);
    B.g = setPoint(100, 100, 100);
    B.h = setPoint(0, 100, 100);

    Tetrahedron T;
    T.a = setPoint(   0,  0,   0);
    T.b = setPoint(-200,  0,   0);
    T.c = setPoint(-100,  0, 100);
    T.d = setPoint(-100,-100, 50);
*/
    List *list;
    list = initList();
    Element *elmt;
    elmt = createElementEllipse(encodeEllipse(E));
    addElementList(elmt, list);

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

    rayTracer(list, observer, imageOrigin, resolution);

    return 0;
}
