#include "objects.h"

int main() {
    Tetrahedron T;
    Line L;

    Point result;

    T.a.x = 0.94;
    T.a.y = 0;
    T.a.z = 1;

    T.b.x = -0.47;
    T.b.y = -0.82;
    T.b.z = 1;

    T.c.x = -0.47;
    T.c.y = 0.82;
    T.c.z = 1;

    T.d.x = 0;
    T.d.y = 0;
    T.d.z = 2;

    L.pt.x = 0;
    L.pt.y = 0;
    L.pt.z = -1;

    L.directionVector.x = 0;
    L.directionVector.y = 0;
    L.directionVector.z = 1;

    result = contactTetrahedronWithLine(T, L);

    printf("|%lf|%lf|%lf|", result.x, result.y, result.z);

    return 0;
}