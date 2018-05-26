#include "raytracer.h"


int main(){

    Ellipse earth;
    earth.a = earth.b = earth.c = 500;

    earth.x = 0;
    earth.y = 0;
    earth.z = 1000000000;

    earth.color = setColor(237, 189, 33);

    Ellipse moon;
    moon.a = 700;
    moon.b = 75;
    moon.c = 120;

    moon.x = 0;
    moon.y = 0;
    moon.z = 100000000 ;

    moon.color = setColor(209, 142, 0);


    // Brick B;
    // B.a = setPoint(0, 0, 0);
    // B.b = setPoint(20, 0, 0);
    // B.c = setPoint(20, 0, 20);
    // B.d = setPoint(0, 0, 20);
    // B.e = setPoint(0, 20, 0);
    // B.f = setPoint(20, 20, 0);
    // B.g = setPoint(20, 20, 20);
    // B.h = setPoint(0, 200, 20);
    // B.color = setColor(255,0,255);

    List *list;
    list = initList();
    addElementList(createElementEllipse(encodeEllipse(earth)), list);
    addElementList(createElementEllipse(encodeEllipse(moon)), list);
    // addElementList(createElementBrick(encodeBrick(B)), list);


    Light lA;//, lB;// lC, lD;
    // lA.lightSource = setPoint(200000, -200000, 999900000);
    lA.lightSource = setPoint(0, 0, -999999999999999);
    //
    // lB.lightSource = setPoint(0, 0, -1000000000);
    // lC.lightSource = setPoint(0, -0, 0);
    // lD.lightSource = setPoint(-500, 500, 100000);


    Light *lightList;
    lightList = (Light*)malloc(sizeof(Light));
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
    imageOrigin.z =    0;

    int width = 2000;
    int height = 2000;

    double tetaX =  0;
    double tetaY = 0;
    double tetaZ =  0;

    rayTracer(list, lightList, observer, imageOrigin, height, width, tetaX, tetaY, tetaZ);

    return 0;
}
