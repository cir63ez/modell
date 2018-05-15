#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "ellipse.h"

/*TODO : paramètres d'entrée du main
*        RESX / RESY : resolution x et y de l'image
*        Ellipse ellipse : l'ellipse
*        Line firstRay : the ray corresponding to the (0,0) pixel
*        Point originPoint : Origin of the image
*        Plane imagePlane : Image plane
*        image[] : pixel array
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
    Rgb *image;
    Point contactPoint;
    firstRay = calculateFirstRay(imagePlane, originPoint)
    Line tmpLine = firstRay;
    image = (Rgb*)malloc(sizeof(Rgb) * RESY * RESX);
    for (int i = 0; i < RESX * RESY; i++){
        tmpLine.pt.x += (i % (RESX - 1)) * vectorA.x;
        tmpLine.pt.y += (i % (RESX - 1)) * vectorA.y;
        tmpLine.pt.z += (i % (RESX - 1)) * vectorA.z;
        tmpLine.pt.x += (i - (i % (RESX - 1)) / (RESX - 1)) * vectorA.x;
        tmpLine.pt.y += (i - (i % (RESX - 1)) / (RESX - 1)) * vectorA.y;
        tmpLine.pt.z += (i - (i % (RESX - 1)) / (RESX - 1)) * vectorA.z;
        contactPoint = contactEllipseWithLine(ellipse, tmpLine);
        if(isnan(contactPoint.x) || isnan(contactPoint.y) || isnan(contactPoint.z)){
            image[i].red = 0;
            image[i].green = 0;
            image[i].blue = 0;
        }
        else{
            image[i].red = 255;
            image[i].green = 255;
            image[i].blue = 255;
        }
        tmpLine = firstRay
    }
    return image;
}
