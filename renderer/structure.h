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

typedef struct Ray_ {
    Point pt;
    Vector directionVector;
} Ray;

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
    Rgb color;
    Point coordinates;
} Pixel;

