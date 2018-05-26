#include "raytracer.h"


void affichePoint(Point I) {
  printf("%lf %lf %lf\n", I.x, I.y, I.z);
}

void afficheVector(Vector I) {
  printf("%lf %lf %lf\n", I.x, I.y, I.z);
}

void affichePlan(Plane Q) {
  printf("Plan : vectorNormal %lf %lf %lf point %lf %lf %lf\n", Q.x, Q.y, Q.z, Q.a, Q.b, Q.c);
}

void afficheObject(double * object, int size) {
  for(int i = 0; i < size; i++) {
    if(i != 0 && i % 3 == 0) {printf("\n");}
    printf("%lf ", object[i]);
  }
}

void afficheElement(Element * E) {
  int size;
  char * name;

  if(E->type == TETRAHEDRON_TYPE) {name = "Tetrahedron"; size = 4*3;}
  if(E->type == BRICK_TYPE) {name = "Brick"; size = 8*3;}
  if(E->type == LIGHT_TYPE) {name = "Light"; size = 3;}
  if(E->type == ELLIPSE_TYPE) {name = "Ellipsoid"; size = 6;}
  printf("%s:\n", name);
  afficheObject(E->object, size);
  printf("\n\n");  
}

void afficheList(List * L) {
  Element * current = L->head;

  while(current != NULL) {
    afficheElement(current);
    current = current->next;
  }

}

int main(){
    /*Tetrahedron T;
    T.a = setPoint(0,0,0);
    T.b = setPoint(3,0,0);
    T.c = setPoint(1.5,0,3);
    T.d = setPoint(1.5,2,1.5);*/

    /*Line L;
    L.pt = setPoint(100,100,-10);
    L.directionVector.x = 0;
    L.directionVector.y = 0;
    L.directionVector.z = 1;*/

    //affichePoint(contactTetrahedronWithLine(T, L));
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

    for(int i = 0; i < 100; i++) {
 
        L.pt = setPoint(100 + 10 * i,100 + 10 * i,-10 + 10 * i);
        L.directionVector.x = i;
        L.directionVector.y = i;
        L.directionVector.z = 10*i;

        printf("%lf %lf %lf \n", contactBrickWithLine(B, L).x,  contactBrickWithLine(B, L).y,  contactBrickWithLine(B, L).z);
   
    }
    L.pt = setPoint(100,100,-10);
    L.directionVector.x = 0;
    L.directionVector.y = 0;
    L.directionVector.z = 1;

    printf("%lf %lf %lf \n", contactBrickWithLine(B, L).x,  contactBrickWithLine(B, L).y,  contactBrickWithLine(B, L).z);

    return 0;
}