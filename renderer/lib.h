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
    int red;
    int green;
    int blue;
} Rgb;

typedef struct Plane_ {
    double a;
    double b;
    double c;
    double d;
} Plane;

typedef struct Pixel_ {
    int x;
    int y;
    Rgb color;
} Pixel;

// Functions

Vector pointsToVector(Point A, Point B);
Vector sumVectors(Vector A, Vector B);
Vector differenceVectors(Vector A, Vector B);
double scalarProduct(Vector A, Vector B);
double norm(Vector A);
double angle(Vector AB, Vector AC);
char arePointsAligned(Point A, Point B, Point C);
Vector normalVector(Point A, Point B, Point C);
Plane planEquationWithPoints(Point A, Point B, Point C);
Point imagePointOnPlane(Point O, Point B, Plane Q);
Point pointIntersectionLineAndPlane(Line L, Plane P);
Plane firstPlaneSeen(Point O, Vector direction, Plane P, Plane Q);