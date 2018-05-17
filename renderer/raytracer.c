#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "raytracer.h"

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

 /*Add parameter Light *list,*/

void rayTracer(Ellipse E, Plane observer, Point imageOrigin, int resolution){
    Point contactPoint;
    BMP *imageFile;
    imageFile = newBMP(resolution, resolution);
    Rgb white;
    white.red = 127;
    white.green = 127;
    white.blue = 127    ;
    white.red = 255;
    white.green = 255;
    white.blue = 255;

    Rgb black;
    black.red = 0;
    black.green = 0;
    black.blue = 0;

    Line firstRay;
    firstRay = calculateFirstRay(observer,imageOrigin);
    Line tmpLine = firstRay;

    char* imageFileName = "bitmapImage.bmp";


    int x, y;

    for (int i = 0; i < resolution * resolution; i++){
        /* tmpLine.pt.x += x * vectorA.x;
         tmpLine.pt.y += x * vectorA.y;
         tmpLine.pt.z += x * vectorA.z;
         tmpLine.pt.x += y * vectorB.x;
         tmpLine.pt.y += y * vectorB.y;
         tmpLine.pt.z += y * vectorB.z;
        */

        x = i % (resolution);
        y = (i - x)/resolution;

        tmpLine.pt.x += x * i;
        tmpLine.pt.y += y * i;


        contactPoint = contactEllipseWithLine(E, tmpLine);

        if(isnan(contactPoint.x)
            || isnan(contactPoint.y)
            || isnan(contactPoint.z)){

            BMPSetColor(imageFile , x, y, white);
        }
        else{
            BMPSetColor(imageFile, x, y, black);
        }

        tmpLine = firstRay;
    }
    exportBMPImageToFile(imageFile, imageFileName);
}
