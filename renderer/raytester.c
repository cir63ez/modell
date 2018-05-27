#include "raytracer.h"


int main(){
    /*
    Ellipse earth;
    earth.a = earth.b = earth.c = 500;

    earth.x = 0;
    earth.y = 0;
    earth.z = 0;
    earth.color = setColor(0,255,0);

    // earth.color = setColor(237, 189, 33); // saturn

    Ellipse moon;
    moon.a = moon.b = moon.c = 120;

    moon.x = 0;
    moon.y = 0;
    moon.z = -400;

    moon.color = setColor(255,255,255);
    // moon.color = setColor(209, 142, 0); // saturn's ring


    // Brick B;
    // B.a = setPoint(0, 0, 0);
    // B.b = setPoint(20, 0, 0);
    // B.c = setPoint(20, 0, 20);
    // B.d = setPoint(0, 0, 20);
    // B.e = setPoint(0, 20, 0);
    // B.f = setPoint(20, 20, 0);
    // B.g = setPoint(20, 20, 20);
    // B.h = setPoint(0, 20, 20);
    // B.color = setColor(255,0,255);

    List *list;
    list = initList();
    addElementList(createElementEllipse(encodeEllipse(earth)), list);
    addElementList(createElementEllipse(encodeEllipse(moon)), list);
    // addElementList(createElementBrick(encodeBrick(B)), list);


    */

    Ellipse body;
    body.a = body.b = body.c = 280;
    body.x = body.y = body.z = 0;
    body.color = setColor(255, 153, 204);

    Ellipse armL;
    armL.a = 100;
    armL.b = 130;
    armL.c = 100;
    armL.x = -270;
    armL.y = 0;
    armL.z = 0;
    armL.color = setColor(255,153,204);

    Ellipse armR;
    armR.a = 100;
    armR.b = 130;
    armR.c = 100;
    armR.x = 270;
    armR.y = 0;
    armR.z = 0;
    armR.color = setColor(255,153,204);

    List *list;
    list = initList();

    addElementList(createElementEllipse(encodeEllipse(body)), list);
    addElementList(createElementEllipse(encodeEllipse(armL)), list);
    addElementList(createElementEllipse(encodeEllipse(armR)), list);
    // addElementList(createElementEllipse(encodeEllipse(eyeA)), list);
    // addElementList(createElementEllipse(encodeEllipse(cheekA)), list);
    // addElementList(createElementEllipse(encodeEllipse(cheekB)), list);
    // addElementList(createElementEllipse(encodeEllipse(mouth)), list);
    // addElementList(createElementEllipse(encodeEllipse(bleuA)), list);
    // addElementList(createElementEllipse(encodeEllipse(bleuB)), list);
    // addElementList(createElementEllipse(encodeEllipse(blancA)), list);
    // addElementList(createElementEllipse(encodeEllipse(blancB)), list);
    // addElementList(createElementEllipse(encodeEllipse(eyeA)), list);
    // addElementList(createElementEllipse(encodeEllipse(eyeB)), list);
    // addElementList(createElementEllipse(encodeEllipse(legA)), list);
    // addElementList(createElementEllipse(encodeEllipse(legB)), list);


    Light lA;//, lB;// lC, lD;
    // lA.lightSource = setPoint(200000, -200000, 999900000);
    lA.lightSource = setPoint(0,  999999999999999, -9999999999999999);
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
    observer.z = -1000000000;

    Point imageOrigin;
    imageOrigin.x = -1000;
    imageOrigin.y =  1000;
    imageOrigin.z = -1000000000;

    int width = 2000;
    int height = 2000;

    double tetaX =  0;
    double tetaY = 0;
    double tetaZ =  0;

    rayTracer(list, lightList, observer, imageOrigin, height, width, tetaX, tetaY, tetaZ);

    return 0;
}
