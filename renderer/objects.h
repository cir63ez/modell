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

//Initialises the list
List * initList();

// Adds an element in the list
void addElementList(Element * e, List * L);

// Deletes the last element of the list
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
    Rgb color;
} Brick;

// checks if the brick could exist
int DoesBrickExist(Brick B);

// Gives the point of contact between a line and a brick
Point contactBrickWithLine(Brick B, Line L);

// Encodes a brick as an array
double * encodeBrick(Brick B);

// Encodes a brick's array as a brick structure
Brick decodeBrick(double * brick);

// Checks if there is a direct path between the point and light
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
    Rgb color;
} Ellipse;

//Gives the point of contact between a line and an ellipse
Point contactEllipseWithLine(Ellipse E, Line L);

// Encodes an array as an ellipse structure
Ellipse decodeEllipse(double * ellipse);

//Encodes an ellipse as an array
double * encodeEllipse(Ellipse E);

//Tests line of sight with light
int testIfLightCutsEllipse(double *object, Light Li, Point C);

// Gives the tangente plane of a intersection point between a plane and an ellipse
Plane tangentPlaneEllipse(Ellipse E, Line L);

// Creates an "ellipse" element to be added in a chained list
Element * createElementEllipse(double * E);


// Tetrahedron.h


typedef struct Tetrahedron_ {
    Point a;
    Point b;
    Point c;
    Point d;
    Rgb color;
} Tetrahedron;

// Gives the point of contact between a line and a tetrahedron
Point contactTetrahedronWithLine(Tetrahedron T, Line L);

//Encodes a tetrahedron as an array
double * encodeTetrahedron(Tetrahedron T);

//Encodes a tetrahedron's array as a tetrahedron structure
Tetrahedron decodeTetrahedron(double *tetrahedron);

// Checks if there is a direct path between the point and light
int testIfLightCutsTetrahedron(double *object, Light Li, Point C);

// Creates a "tetrahedron" element to be added in a chained list
Element * createElementTetrahedron(double * T);


// Light.h


// Encodes a light's array as a light structure
Light decodeLight(double * light);

// Encodes a light as an array
double * encodeLight(Light L);

// Creates a light element for the list
Element * createElementLight(double * L);

// Tests if two points are equals
int arePointsEqual(Point O, Point I);

// Gives a vector in a plane
Vector vectorInPlane(Point O, Plane P);

// Gets intersection point beteween two lines
Point pointIntersectionLineAndLine(Line L, Line D);

// Gets intersection point beteween a line and a segment
Point pointIntersectionLineAndSegment(Point A, Point B, Line L);

// Checks if a point is in a polyogon
int isOnPolygon(Point *list, double numberOfPoint, Point test);

// Checks if a point is in polygon
int isOnPolygonAngleMethod(Point *list, double numberOfPoint, Point I);

// Checks if a point is in polygon
// Comes from "L’hélicoptère aux 52 orteils de Moldavie" and adapted to our libs
int isOnPolygonLilianMethod(Point *list, double numberOfPoint, Point I);
