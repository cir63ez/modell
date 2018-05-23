#include "raytracer.h"

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


void rayTracer(List *objectList, /* Light *list,*/ Plane observer, Point imageOrigin, int resolution){
    Point *contactPoint;
    Point nearestPoint;
    Point rayOrigin;
    BMP *imageFile;
    int x, y;

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

    contactPoint = (Point*)malloc(objectList->nbElement * sizeof(Point));

    for (int i = 0; i < resolution * resolution; i++){
        x = i % (resolution);
        y = (i - x)/resolution;

        rayOrigin.x += x;
        rayOrigin.y -= y;
        tmpLine.pt = rayOrigin;

        for(int j = 0; j < objectList->nbElement; j++){
            switch (objectList->head->type){
                case ELLIPSE_TYPE :
                    contactPoint[j] = contactEllipseWithLine(decodeEllipse(objectList->head->object), tmpLine);
                    break;
                case BRICK_TYPE :
                    contactPoint[j] = contactBrickWithLine(decodeBrick(objectList->head->object), tmpLine);
                    break;
                case TETRAHEDRON_TYPE :
                    contactPoint[j] = contactTetrahedronWithLine(decodeTetrahedron(objectList->head->object), tmpLine);
                    break;
            }
            nearestPoint = contactPoint[0];
            for(int k = 0; k < objectList->nbElement; k++){
                if( !isPointNaN(contactPoint[k]) ){
                    if ( norm( pointsToVector(contactPoint[k], rayOrigin) ) < norm( pointsToVector(nearestPoint, rayOrigin))){
                        nearestPoint = contactPoint[k];
                    }
                }
            }
            if(isPointNaN(nearestPoint)){
                BMPSetColor(imageFile , x, y, black);
            }
            else{
                BMPSetColor(imageFile, x, y, white);
            }

            tmpLine = firstRay;
        }
    }
    free(contactPoint);
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

int testIfLightCutsObject(Light li, List *objectList, Point c){
    while(objectList->head->next != NULL) {
        if(objectList->head->type == ELLIPSE_TYPE){
            if(testIfLightCutsEllipse(objectList->head->object, li, c) != TRUE){
                return TRUE;
            }
        }
        else if(objectList->head->type == BRICK_TYPE){
            if(testIfLightCutsBrick(objectList->head->object, li, c) != TRUE){
                return TRUE;
            }
        }
        else if(objectList->head->type == TETRAHEDRON_TYPE){
            if(testIfLightCutsTetrahedron(objectList->head->object, li, c) != TRUE){
                return TRUE;
            }
        }
        *(objectList)->head = *(objectList)->head->next;
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

int isLit(Point c, List *objectList, Light *listOfLights, int numberofLights){
	for (int i = 0; i < numberofLights; i++) {
        if(testIfLightCutsObject(*(listOfLights + i), objectList, c) == TRUE){
            return TRUE;
        }
    }
    return FALSE;
}
