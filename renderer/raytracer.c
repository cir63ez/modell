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

int testIfLightCutsObject(Light li, List *objectList, Point c){
    while(objectList->head != NULL) {
        switch (objectList->head->type) {
            case ELLIPSE_TYPE:
                if(testIfLightCutsEllipse(objectList->head->object, li, c)){
                    return TRUE;
                }
            // case BRICK_TYPE :
            //     if(testIfLightCutsBrick(objectList->head->object, li, c)){
            //         return TRUE;
            //     }
            // case TETRAHEDRON_TYPE :
            //     if(testIfLightCutsTetrahedron(objectList->head->object, li, c)){
            //         return TRUE;
            //     }
        }
        objectList->head = objectList->head->next;
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
* @return TRUE if the point c sees the light
* @return FALSE if the point c doesn't see the light
*/

int isLit(Point c, List *objectList, Light *listOfLights, int numberofLights){
	for (int i = 0; i < numberofLights; i++) {
        if(testIfLightCutsObject(*(listOfLights + i), objectList, c) == TRUE){
            return FALSE;
        }
    }
    return TRUE;
}


 /*Add parameter Light *list,*/

void rayTracer(List *objectList, Light *lightList, Plane observer, Point imageOrigin, int height, int width, double tetaX, double tetaY, double tetaZ){


    BMP *imageFile;
    imageFile = newBMP(height, width);
    char* imageFileName = "bitmapImage.bmp";

    Rgb backgroundColor;
    // Deep Blue
    backgroundColor.red   = 0;
    backgroundColor.green = 0;
    backgroundColor.blue  = 255;

    Line firstRay;
    firstRay = calculateFirstRay(observer,imageOrigin);
    Line tmpLine = firstRay;
    Line rotatedLine;

    double x, y;

    Point rayOrigin;
    Point nearestPoint;
    Point *contactPoint;
    contactPoint = (Point*)malloc(objectList->nbElement * sizeof(Point));

    Rgb nearestPointColor;
    Rgb *pointColor;
    pointColor = (Rgb*)malloc(objectList->nbElement * sizeof(Rgb));

    Element *listHeadCopy;
    listHeadCopy = objectList->head;

    for (int i = 0; i < width * height; i++){
        /* tmpLine.pt.x += x * vectorA.x;
         tmpLine.pt.y += x * vectorA.y;
         tmpLine.pt.z += x * vectorA.z;
         tmpLine.pt.x += y * vectorB.x;
         tmpLine.pt.y += y * vectorB.y;
         tmpLine.pt.z += y * vectorB.z;
        */


        x = i % (height);
        y = (i - x)/width;

        tmpLine.pt.x += x;
        tmpLine.pt.y -= y;

        Vector V;
        V.x = tmpLine.pt.x;
        V.y = tmpLine.pt.y;
        V.z = tmpLine.pt.z;

        Vector rotatedV = matriceRotation(V, tetaX, tetaY, tetaZ);

        rotatedLine = tmpLine;
        rotatedLine.pt.x = rotatedV.x;
        rotatedLine.pt.y = rotatedV.y;
        rotatedLine.pt.z = rotatedV.z;

        rotatedLine.directionVector = matriceRotation(tmpLine.directionVector, tetaX, tetaY, tetaZ);

        objectList->head  = listHeadCopy;
        for(int j = 0; j < objectList->nbElement; j++){
            switch (objectList->head->type) {
                case BRICK_TYPE :
                    contactPoint[j] = contactBrickWithLine(decodeBrick(objectList->head->object), rotatedLine);
                    pointColor[j] = setColor((int)objectList->head->object[24], (int)objectList->head->object[25], (int)objectList->head->object[26]);
                    break;
                case ELLIPSE_TYPE :
                    contactPoint[j] = contactEllipseWithLine(decodeEllipse(objectList->head->object), rotatedLine);
                    pointColor[j] = setColor((int)objectList->head->object[6], (int)objectList->head->object[7],(int) objectList->head->object[8]);
                    break;
                case TETRAHEDRON_TYPE :
                    contactPoint[j] = contactTetrahedronWithLine(decodeTetrahedron(objectList->head->object), rotatedLine);
                    pointColor[j] = setColor((int)objectList->head->object[12], (int)objectList->head->object[13], (int)objectList->head->object[14]);
                    break;
                }


            if(objectList->head->next != NULL){
                objectList->head = objectList->head->next;
            }
            else{
                // printf("end list :%d \n", j);
            }
        }
        tmpLine = firstRay;

        objectList->head = listHeadCopy;
        nearestPoint = contactPoint[0];
        nearestPointColor = pointColor[0];
        for(int k = 0;  k < objectList->nbElement; k++){
            if (!isPointNaN(contactPoint[k])){
                if ( norm(pointsToVector(tmpLine.pt, contactPoint[k])) < norm(pointsToVector(tmpLine.pt, nearestPoint)) ){
                    nearestPoint = contactPoint[k];
                    nearestPointColor = pointColor[k];
                }
                if (isPointNaN(nearestPoint)){
                    nearestPoint = contactPoint[k];
                    nearestPointColor = pointColor[k];
                }
            }
            if(objectList->head->next != NULL){
                objectList->head = objectList->head->next;
            }
        }
        //printf("%d %d %d \n", nearestPointColor.red, nearestPointColor.green, nearestPointColor.blue);
        objectList->head = listHeadCopy;
        if (isPointNaN(nearestPoint)){
            BMPSetColor(imageFile , x, y, backgroundColor);
        }
        else{
            if(isLit(nearestPoint, objectList, lightList, 1)/* && !isPointNaN(nearestPoint)*/) {
                BMPSetColor(imageFile , x, y, nearestPointColor);
                // printf("%d\n", nearestPointColor.blue);
            }
            else{
                if(!isLit(nearestPoint, objectList, lightList, 1)){
                    BMPSetColor(imageFile, x, y, setColor(0,0,0));
                }
            }
            // else{
            //     if(isPointNaN(nearestPoint)){
            //         BMPSetColor(imageFile, x, y, nearestPointColor);
            //     }
            // }
        }

    }
    //blurBmpImage(imageFile, 1.8);
    exportBMPImageToFile(imageFile, imageFileName);
}
