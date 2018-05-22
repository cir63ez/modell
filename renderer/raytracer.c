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
    //printf("%lf %lf %lf \n", directionVector.x, directionVector.y, directionVector.z);
    //printf("%lf %lf %lf \n", origin.x, origin.y, origin.z);
    return firstRay;
}

 /*Add parameter Light *list,*/

void rayTracer(Tetrahedron object, Plane observer, Point imageOrigin, int resolution){
    Point contactPoint;
    BMP *imageFile;
    imageFile = newBMP(resolution, resolution);
    Rgb white;
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

        tmpLine.pt.x += x;
        tmpLine.pt.y -= y;

        //printf("x %2d  y %2d \n", x, y);


        contactPoint = contactTetrahedronWithLine(object, tmpLine);


        //printf("%3lf %3lf %3lf \n", tmpLine.pt.x, tmpLine.pt.y, tmpLine.pt.z);
        //printf("%lf,%lf,%lf\n",contactPoint.x,contactPoint.y,contactPoint.z);
        if(isnan(contactPoint.x)
            || isnan(contactPoint.y)
            || isnan(contactPoint.z)){

            BMPSetColor(imageFile , x, y, black);
        }
        else{
            BMPSetColor(imageFile, x, y, white);
            printf("%3lf %3lf %3lf \n", tmpLine.pt.x, tmpLine.pt.y, tmpLine.pt.z);
            printf("blanc\n");
        }

        tmpLine = firstRay;
    }
    exportBMPImageToFile(imageFile, imageFileName);
}


/**
* Launch the check function depending of the object
*
* @param A: Light source
* @param B: list of object
* @param C: contact points
*
* @return TRUE if the light cuts an object before point c
* @return FALSE if the light doesnt cuts an object before point c
*/

int testIfLightCutsObject(Light li, List *listOfObject, Point c){
    while(listOfObject->head->next != NULL) {
        if(listOfObject->head->type == ELLIPSE_TYPE){
            if(testIfLightCutsEllipse(listOfObject->head->object, li, c) != TRUE){
                return TRUE;
            }
        }
        else if(listOfObject->head->type == BRICK_TYPE){
            if(testIfLightCutsBrick(listOfObject->head->object, li, c) != TRUE){
                return TRUE;
            }
        }
        else if(listOfObject->head->type == TETRAHEDRON_TYPE){
            if(testIfLightCutsTetrahedron(listOfObject->head->object, li, c) != TRUE){
                return TRUE;
            }
        }
        *(listOfObject)->head = *(listOfObject)->head->next;
    }
    return FALSE;
}

/**
* launch the check fonctions for each point of light
*
* @param A: contact point
* @param B: list of object
* @param C: list of light
* @param D: numberOfLight
*
* @return TRUE if the point c see the light
* @return FALSE if the point c desnt see the light
*/

int isLit(Point c, List *listOfObject, Light *listOfLights, int numberofLights){
	for (int i = 0; i < numberofLights; i++) {
        if(testIfLightCutsObject(*(listOfLights + i), listOfObject, c) == TRUE){
            return TRUE;
        }
    }
    return FALSE;
}
