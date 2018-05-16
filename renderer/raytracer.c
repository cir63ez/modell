#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "raytracer.h"
#include "lib.h"

/*Missing : paramètres d'entrée du main
*          Ellipse E : the ellipsoid
*          Line firstRay : the ray corresponding to the (0,0) pixel
*          Point originPoint : Origin of the image
*          Plane imagePlane : Image plane
*          image[] : pixel array
*/


/**
* Calculates the ray corresponding to the (0,0) pixel
*
* @param A: Image plane
* @param B: Origin point of the image
*
* @return the ray corresponding to the (0,0) pixel
*/
Line calculateFirstRay (Plane image, Point origin){
    Line firstRay;
    Vector directionVector;

    firstRay.pt = origin;

    directionVector.x = image.a;
    directionVector.y = image.b;
    directionVector.z = image.c;
    firstRay.directionVector = directionVector;

    return firstRay;
}


Rgb* rayTracer(Ellipse E, /*Light *list*/, Plane observer, Point imageOrigin, int resolution){
    BMPFile *finalImage;
    Rgb *image;
    Point contactPoint;

    E.a = E.b = E.c = 25;

    origin.x = -100;
    origin.y = 100;
    origin.z = -100;

    O.a = 1;
    O.b = 1;
    O.c = 0;

    Rgb white;
    white.red = 255;
    white.green = 255;
    white.blue = 255;

    Rgb black;
    black.red = 0;
    black.green = 0;
    black.blue = 0;

    firstRay = calculateFirstRay(O, origin);
    Line tmpLine = firstRay;
    image = (Rgb*)malloc(sizeof(Rgb) * resolution * resolution);
    finalImage = newBMP(resolution,resolution);

    int x, y;

    for (int i = 0; i < 200 * 200; i++){
        x = i % (200 - 1);
        y = i - (i % (200 - 1)) / (200 - 1);
        tmpLine.pt.x += x * vectorA.x;
        tmpLine.pt.y += x * vectorA.y;
        tmpLine.pt.z += x * vectorA.z;

        tmpLine.pt.x += y * vectorB.x;
        tmpLine.pt.y += y * vectorB.y;
        tmpLine.pt.z += y * vectorB.z;

        contactPoint = contactEllipseWithLine(E, tmpLine);

        if(isnan(contactPoint.x)
            || isnan(contactPoint.y)
            || isnan(contactPoint.z)){

            BMPSetColor(finalImage, x, y, white);
        }
        else{
            BMPSetColor(finalImage, x, y, black);
        }

        tmpLine = firstRay;
    }
    tempPrint(finalImage);
    return image;
}
