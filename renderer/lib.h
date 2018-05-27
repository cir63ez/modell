#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Defines

#define TRUE 1
#define FALSE 0
#define NaN 0./0.
#define _PI 3.14159265358979

#define FEQUAL_LIMIT 0.0000000001
#define FEQUAL_LIMIT 0.00001
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

//creates a vector from two points
Vector pointsToVector(Point A, Point B);

//sums of two vectors
Vector sumVectors(Vector A, Vector B);

//Substracts two vectors
Vector substractVectors(Vector A, Vector B);

//Calculates the scalar product between two vectors
double scalarProduct(Vector A, Vector B);

//Calculates the norm of a vector
double norm(Vector A);

//calculates the angle between two vectors
double angle(Vector AB, Vector AC);

//checks if three points are aligned
char arePointsAligned(Point A, Point B, Point C);

//calculates the normal vector from a plane created by 3 points
Vector normalVector(Point A, Point B, Point C);

//creates a plane from three points
Plane planeEquationFromPoints(Point A, Point B, Point C);

//Point imagePointOnPlane(Point O, Point B, Plane Q);

//Calculates the intersection point between a line and a plane
Point pointIntersectionLineAndPlane(Line L, Plane P);

//returns the first plane seen by a line
Plane firstPlaneSeen(Line L, Plane P, Plane Q);

//calculates the reflected ray
Line reflectedRay(Point I, Vector normal, Vector ray, double refractiveIndexA, double refractiveIndexB);

//calculates the refracted ray
Line refractedRay(Point I, Vector normal, Vector ray, double refractiveIndexA, double refractiveIndexB);

//Checks if the point is on the plane
int isPointOnPlane(Point I, Plane P);

//creates a NaN point
Point initPointNaN();

//creates a NaN vector
Vector initVectorNaN();

//checks if point is NaN
int isPointNaN(Point P);

//Sets the three coordinates of a pointsToVector
Point setPoint(double x, double y, double z);

// Sets an RGB color
Rgb setColor(unsigned char r, unsigned char g, unsigned char b);

// Changes a caractere to an integer
int charToInt(char caractere);

// rotates a vector around the three axes
Vector matriceRotation(Vector V, double tetaX, double tetaY, double tetaZ);
