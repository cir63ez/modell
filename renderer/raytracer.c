#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "raytracer.h"

/*Missing : paramètres d'entrée du main
*          RESX / RESY : resolution x et y de l'image
*          Ellipse ellipse : l'ellipse
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


*rgb rayTracer(  ){
    BMPFile *finalImage;
    Rgb *image;
    Point contactPoint;
    Rgb white;
    Rgb black;

    firstRay = calculateFirstRay(imagePlane, originPoint)
    Line tmpLine = firstRay;
    image = (Rgb*)malloc(sizeof(Rgb) * RESY * RESX);
    finalImage = newBMP(200,200);
    white.red = 255;
    white.green = 255;
    white.blue = 255;

    black.red = 0;
    black.green = 0;
    black.blue = 0;

    for (int i = 0; i < RESX * RESY; i++){
        x = i % (RESX - 1);
        y = i - (i % (RESX - 1)) / (RESX - 1);
        tmpLine.pt.x += x * vectorA.x;
        tmpLine.pt.y += x * vectorA.y;
        tmpLine.pt.z += x * vectorA.z;

        tmpLine.pt.x += y * vectorA.x;
        tmpLine.pt.y += y * vectorA.y;
        tmpLine.pt.z += y * vectorA.z;

        contactPoint = contactEllipseWithLine(ellipse, tmpLine);

        if(isnan(contactPoint.x) || isnan(contactPoint.y) || isnan(contactPoint.z)){
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
