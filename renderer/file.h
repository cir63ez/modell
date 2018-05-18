#pragma once
#include "lib.h"
#include "raytracer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



// Change caracteres into a number from a file
int caractereToNumber(FILE * f);

// Change caracteres into an object name from a file
char * caractereToName(FILE * f);

// Give point in the image plane from a file
Point pointPlaneFile (FILE * f) {
    rewind(f);
    Point P;
    P.x = caractereToNumber(f);
    P.y = caractereToNumber(f);
    P.z = caractereToNumber(f);
    return P;
}

// Give the normal vector of the image plane from a file
Vector normalVectorPlaneFile (FILE * f);

// Give the number of caractere of a number or a word between txo ','
int numberCaractere(FILE * f);

// Give an ellipse from a file
Ellipse fileToEllipse(FILE * f);

// Give the position of a light from a file
Light fileToLight(FILE * f);