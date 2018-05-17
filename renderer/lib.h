#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defines

#define TRUE 1
#define FALSE 0
#define NaN 0./0.

#define FEQUAL_LIMIT 0.0000000001
#define FEQUAL(A, B) (fabs(A - B) < FEQUAL_LIMIT) ? TRUE : FALSE

// Structures


typedef struct Point_ {
    double x;
    double y;
    double z;
} Point;

typedef struct Vector_ {
    double x;
    double y;
    double z;
} Vector;

typedef struct Line_ {
    Point pt;
    Vector directionVector;
} Line;

typedef struct Rgb_ {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Rgb;

typedef struct Plane_ {
    double a;
    double b;
    double c;
    double x;
    double y;
    double z;
} Plane;

typedef struct Light_ {
    Point lightSource;
} Light;

typedef struct Ray_ {
    Line rayLine;
} Ray;

typedef struct Pixel_ {
    int x;
    int y;
    Rgb color;
} Pixel;

// Functions

//create a vector from points
Vector pointsToVector(Point A, Point B);

//sum of two vectors
Vector sumVectors(Vector A, Vector B);

//difference of two vectors
Vector differenceVectors(Vector A, Vector B);

//Calculate the scalar product
double scalarProduct(Vector A, Vector B);

//Calculate the norm
double norm(Vector A);

//calculate the angle between two vectors
double angle(Vector AB, Vector AC);

//check if the three points are aligned
char arePointsAligned(Point A, Point B, Point C);

//calculate the normal vector from a point created by 3 points
Vector normalVector(Point A, Point B, Point C);

//create a plane from three points
Plane planeEquationFromPoints(Point A, Point B, Point C);

//Point imagePointOnPlane(Point O, Point B, Plane Q);

//Calculate the intersection point between a line and a plane
Point pointIntersectionLineAndPlane(Line L, Plane P);

//return the first plane seen by a line
Plane firstPlaneSeen(Line L, Plane P, Plane Q);

//calculate the reflected ray
Line reflectedRay(Point I, Vector normal, Vector ray, double refractiveIndexA, double refractiveIndexB);

//calculate the refracted ray
Line refractedRay(Point I, Vector normal, Vector ray, double refractiveIndexA, double refractiveIndexB);

//check if a point is in a polygon
int isOnPolygon(Point *li,double numberOfPoint,Point t);
Point initPointNaN();
Vector initVectorNaN();
int isPointNaN(Point P);