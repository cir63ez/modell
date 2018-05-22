#pragma once
#include "lib.h"

// List.h


#define ELLIPSE_TYPE 0
#define BRICK_TYPE 1
#define TETRAHEDRON_TYPE 2
#define LIGHT_TYPE 3

typedef struct Element_
{
    char type;
    double *object;
    struct Element_ *next;
} Element;

typedef struct List_
{
    Element *head;
    double nbElement;
} List;

//Initialized the list
List * initList();

// Add an element in the list
void addElementList(Element * e, List * L);

// Delete the last element of the list
void deleteElementList(List * list);



// Brick.h

typedef struct Brick_ {
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
    Point f;
    Point g;
    Point h;
} Brick;

// Verify if the brick could exist
int DoesBrickExist(Brick B);

// Give the point of contact between a line and a brick
Point contactBrickWithLine(Brick B, Line L);

// Encode a brick as an array
double * encodeBrick(Brick B);

// Encode a brick's array as a brick structure
Brick decodeBrick(double * brick);

// Check if there is a direct path between the point and light
int testIfLightCutsBrick(double *object,Light Li,Point C);

// Creates a "brick" element to be added in a chained list
Element * createElementBrick(double * B);


// Ellipse.h

typedef struct Ellipse_ {
    //radii of the ellipsoid
    double a;
    double b;
    double c;
    // x y z coordinates of the center point
    double x;
    double y;
    double z;
} Ellipse;

//Give the point of contact between a line and an ellipse
Point contactEllipseWithLine(Ellipse E, Line L);

// Encode an array as an ellipse structure
Ellipse decodeEllipse(double * ellipse);

//Encode an ellipse as an array
double * encodeEllipse(Ellipse E);

//Test line of sight with light
int testIfLightCutsEllipse(double *object, Light Li, Point C);

// Give the tangente plane of a intersection point between a plane and an ellipse
Plane tangentPlaneEllipse(Ellipse E, Line L);

// Creates an "ellipse" element to be added in a chained list
Element * createElementEllipse(double * E);


// Tetrahedron.h


typedef struct Tetrahedron_ {
    Point a;
    Point b;
    Point c;
    Point d;
} Tetrahedron;

// Give the point of contact between a line and a tetrahedron
Point contactTetrahedronWithLine(Tetrahedron T, Line L);

//Encode a tetrahedron as an array
double * encodeTetrahedron(Tetrahedron T);

//Encode a tetrahedron's array as a tetrahedron structure
Tetrahedron decodeTetrahedron(double *tetrahedron);

// Check if there is a direct path between the point and light
int testIfLightCutsTetrahedron(double *object, Light Li, Point C);

// Creates a "tetrahedron" element to be added in a chained list
Element * createElementTetrahedron(double * T);

//Light
// Encode a light's array as a light structure
Light decodeLight(double * light);

// Encode a light as an array
double * encodeLight(Light L);

// Create a light element for the list
Element * createElementLight(double * L);