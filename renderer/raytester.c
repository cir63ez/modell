#include "raytracer.h"


int main(){


    // Plane object;
    // object.a = object.b = 0;
    // object.c = 1;
    // object.x = object.y = 0;
    // object.z = -10;

    // Brick object;
    // object.a = setPoint(0, 0, 0);
    // object.b = setPoint(200, 0, 0);
    // object.c = setPoint(200, 0, 200);
    // object.d = setPoint(0, 0, 200);
    // object.e = setPoint(0, 200, 0);
    // object.f = setPoint(200, 200, 0);
    // object.g = setPoint(200, 200, 200);
    // object.h = setPoint(0, 200, 200);
/*
    Tetrahedron object;
    object.a = setPoint(   0,  0,   0);
    object.b = setPoint(-200,  0,   0);
    object.c = setPoint(-100,  0, 100);
    object.d = setPoint(-100,-100, 50);
    */

    Ellipse eA;
    eA.a =  eA.b = eA.c = 500;

    eA.x = eA.y = 0;
    eA.z = 0;

    // Ellipse eB;
    // eB.a =  eB.b = eB.c = 100;
    //
    // eB.x = eB.y = 0;
    // eB.z = 0;


    List *list;
    list = initList();
    addElementList(createElementEllipse(encodeEllipse(eA)), list);
    // addElementList(createElementEllipse(encodeEllipse(eB)), list);
    // addElementList(createElementBrick(encodeBrick(object)), list);

    Light hope;
    hope.lightSource = setPoint(50000, 0, 0);

    Light *lightList;
    lightList = (Light*)malloc(sizeof(Light));
    lightList[0] = hope;

    Plane observer;
    observer.a = observer.b = 0;
    observer.c = 1;
    observer.x = observer.y = 0;
    observer.z = -10000;

    Point imageOrigin;
    imageOrigin.x = -500;
    imageOrigin.y =  500;
    imageOrigin.z =-1000000;

    int resolution = 1000;

    rayTracer(list, lightList, observer, imageOrigin, resolution);

    return 0;
}
