#include "raytracer.h"


int main(){

    Ellipse body;
    body.a = body.b = body.c = 80;

    body.x = 0;
    body.y = 0;
    body.z = -20;

    body.color = setColor(255, 153,204);

    Ellipse armA;
    armA.a = 13;
    armA.b = 10;
    armA.c = 10;

    armA.x = 27;
    armA.y = 0;
    armA.z = +1.5 ;

    armA.color = setColor(250, 153, 204);

    Ellipse armB;
    armB.a = 13;
    armB.b = 10;
    armB.c = 10;

    armB.x = -27;
    armB.y = 0;
    armB.z = +1.5;

    armB.color = setColor(250, 153, 204);


    Ellipse legA;
    legA.a = 9;
    legA.b = 10;
    legA.c = 12;

    legA.x = 17;
    legA.y = 0;
    legA.z = +23 ;

    legA.color = setColor(153,0,0);

    Ellipse legB;
    legB.a = 9;
    legB.b = 10;
    legB.c = 12;

    legB.x = -17;
    legB.y = 0;
    legB.z = +23;

    legB.color = setColor(153,0,0);

    Ellipse eyeA;
    eyeA.a = 5;
    eyeA.b = 6;
    eyeA.c = 10;

    eyeA.x = 6;
    eyeA.y = +22;
    eyeA.z = -10 ;

    eyeA.color = setColor(0,0,0);

    Ellipse eyeB;
    eyeB.a = 5;
    eyeB.b = 6;
    eyeB.c = 10;

    eyeB.x = -6;
    eyeB.y = +22;
    eyeB.z = -10 ;

    eyeB.color = setColor(0,0,0);

    Ellipse blancA;
    blancA.a = 2;
    blancA.b = 2;
    blancA.c = 2;

    blancA.x = 6;
    blancA.y = +24;
    blancA.z = +16 ;

    blancA.color = setColor(255,255,255);

    Ellipse blancB;
    blancB.a = 2;
    blancB.b = 2;
    blancB.c = 2;

    blancB.x = -6;
    blancB.y = +24;
    blancB.z = +16 ;

    blancB.color = setColor(255,255,255);

    Ellipse bleuA;
    bleuA.a = 2;
    bleuA.b = 2;
    bleuA.c = 2;

    bleuA.x = 6;
    bleuA.y = +24;
    bleuA.z = -8 ;

    bleuA.color = setColor(0,102,255);

    Ellipse bleuB;
    bleuB.a = 2;
    bleuB.b = 2;
    bleuB.c = 2;

    bleuB.x = -6;
    bleuB.y = +24;
    bleuB.z = -8 ;

    bleuB.color = setColor(0,102,255);

    Ellipse mouth;
    mouth.a = 8;
    mouth.b = 6;
    mouth.c = 4;

    mouth.x = 0;
    mouth.y = +24;
    mouth.z = +5 ;

    mouth.color = setColor(153,0,0);

    Ellipse cheekA;
    cheekA.a = 6;
    cheekA.b = 2;
    cheekA.c = 4;

    cheekA.x = +16;
    cheekA.y = +26;
    cheekA.z = -4 ;

    cheekA.color = setColor(255,77,166);

    Ellipse cheekB;
    cheekB.a = 6;
    cheekB.b = 2;
    cheekB.c = 4;

    cheekB.x = -16;
    cheekB.y = +26;
    cheekB.z = -4 ;

    cheekB.color = setColor(255,77,166);
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
    addElementList(createElementEllipse(encodeEllipse(body)), list);
    addElementList(createElementEllipse(encodeEllipse(armA)), list);
    addElementList(createElementEllipse(encodeEllipse(armB)), list);
    addElementList(createElementEllipse(encodeEllipse(legA)), list);
    addElementList(createElementEllipse(encodeEllipse(legB)), list);
    addElementList(createElementEllipse(encodeEllipse(eyeA)), list);
    addElementList(createElementEllipse(encodeEllipse(eyeB)), list);
    addElementList(createElementEllipse(encodeEllipse(blancA)), list);
    addElementList(createElementEllipse(encodeEllipse(blancB)), list);
    addElementList(createElementEllipse(encodeEllipse(bleuA)), list);
    addElementList(createElementEllipse(encodeEllipse(bleuB)), list);
    addElementList(createElementEllipse(encodeEllipse(mouth)), list);
    addElementList(createElementEllipse(encodeEllipse(cheekA)), list);
    addElementList(createElementEllipse(encodeEllipse(cheekB)), list);

    // addElementList(createElementBrick(encodeBrick(B)), list);


    Light lA;//, lB;// lC, lD;
    // lA.lightSource = setPoint(200000, -200000, 999900000);
    lA.lightSource = setPoint(0, 0, -9999999999999999);
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
