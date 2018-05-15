#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

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
    double red;
    double green;
    double blue;
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
