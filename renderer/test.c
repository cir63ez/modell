#include "raytracer.h"

int main(){
    Brick B;
    B.a = setPoint(0, 0, 0);
    B.b = setPoint(200, 0, 0);
    B.c = setPoint(200, 0, 200);
    B.d = setPoint(0, 0, 200);
    B.e = setPoint(0, 200, 0);
    B.f = setPoint(200, 200, 0);
    B.g = setPoint(200, 200, 200);
    B.h = setPoint(0, 200, 200);
    B.color = setColor(255,0,255);

    Line L;
    L.pt = setPoint(100,100,-10);
    L.directionVector.x = 0;
    L.directionVector.y = 0;
    L.directionVector.z = 1;

    printf("%lf %lf %lf \n", contactBrickWithLine(B, L).x,  contactBrickWithLine(B, L).y,  contactBrickWithLine(B, L).z);
    return 0;
}
