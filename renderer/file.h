#pragma once
#include "lib.h"
#include "raytracer.h"

// Change caracteres into a number from a file
int caractereToNumber(FILE * f);

// Change caracteres into an object name from a file
char * caractereToName(FILE * f);

// Give point in the image plane from a file
Point pointPlaneFile (FILE * f);

// Give the normal vector of the image plane from a file
Vector normalVectorPlaneFile (FILE * f);

// Give the number of caractere of a number or a word between two ','
int numberCaractere(FILE * f);

// Give the type of an object
int whichType(char * name);

// Treat the object to have a string of an object
double * objectTreatement(int type, FILE * f);

// Get the list of objects from a file
List * objectFromFile(FILE * f);

// Give a brick from a file
Brick getBrick(FILE * f);

// Give a tetrahedron from a file
Tetrahedron getTetrahedron(FILE * f);

// Give an ellipse from a file
Ellipse fileToEllipse(FILE * f);

// Give the position of a light from a file
Light fileToLight(FILE * f);