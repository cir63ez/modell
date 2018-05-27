#pragma once
#include "lib.h"
#include "raytracer.h"

// Changes caracteres into a number from a file
int caractereToNumber(FILE * f);

// Changes caracteres into an object name from a file
char * caractereToName(FILE * f);

// Gives point in the image plane from a file
Point pointPlaneFile (FILE * f);

// Gives the normal vector of the image plane from a file
Vector normalVectorPlaneFile (FILE * f);

// Gives the number of caractere of a number or a word between two ','
int numberCaractere(FILE * f);

// Gives the type of an object
int whichType(char * name);

// Treats the object to have a string of an object
double * objectTreatement(int type, FILE * f);

// Gets the list of objects from a file
List * objectFromFile(FILE * f);

// Gives a brick from a file
Brick getBrick(FILE * f);

// Gives a tetrahedron from a file
Tetrahedron getTetrahedron(FILE * f);

// Gives an ellipse from a file
Ellipse fileToEllipse(FILE * f);

// Gives the position of a light from a file
Light fileToLight(FILE * f);
