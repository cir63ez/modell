#include "raytracer.h"


int main(){

    Ellipse moon;
    moon.a =  moon.b = moon.c = 500;

    moon.x = -0;
    moon.y = -0;
    moon.z = 1000000000;

    moon.color = setColor(255,0,0);

    // Ellipse earth;
    // earth.a =  earth.b = earth.c = 120;
    //
    // earth.x = earth.y = 0;
    // earth.z = 100000;
    //
    // earth.color = setColor(255,255,255);


    List *list;
    list = initList();
    addElementList(createElementEllipse(encodeEllipse(moon)), list);
    // addElementList(createElementEllipse(encodeEllipse(earth)), list);

    Light lA;// lB, lC, lD;
    lA.lightSource = setPoint(200000, -200000, 999999000);
    // lB.lightSource = setPoint(500, -500, 100000);
    // lC.lightSource = setPoint(0, -0, 0);
    // lD.lightSource = setPoint(-500, 500, 100000);


    Light *lightList;
    lightList = (Light*)malloc(sizeof(Light) * 4);
    lightList[0] = lA;
    // lightList[1] = lB;
    // lightList[2] = lC;
    // lightList[3] = lD;

    Plane observer;
    observer.a = observer.b = 0;
    observer.c = 1;
    observer.x = 0;
    observer.y = 0;
    observer.z = 0;

    Point imageOrigin;
    imageOrigin.x = -500;
    imageOrigin.y =  500;
    imageOrigin.z =   0;

    int width = 2000;
    int height = 2000;

    double tetaX =  0;
    double tetaY = 0;
    double tetaZ =  0;

    rayTracer(list, lightList, observer, imageOrigin, height, width, tetaX, tetaY, tetaZ);

    return 0;
}
