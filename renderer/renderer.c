#include "file.h"
#include "objects.h"

/* PHP interface
*  Calls raytracer.c
*/

// a suppr

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

//----fin----//

int main(int argc, char **argv){
    FILE * f;

    Point P;
    int height;
    int width;
    int numberObject;
    int numberLight;
    double angleX;
    double angleY;
    double angleZ;
    List * L = NULL; // Avoiding warnings

    f = fopen("./data.txt", "r");
    if(f == NULL){
        printf("File not found \n");
    }
    else {
        P = pointPlaneFile(f);
        printf("point %lf %lf %lf \n", P.x, P.y, P.z);
        height = caractereToNumber(f);
        width = caractereToNumber(f);
        //V = normalVectorPlaneFile(f);
        angleX = caractereToNumber(f);
        angleY = caractereToNumber(f);
        angleZ = caractereToNumber(f);
        printf("dimensions %d x %d \n", height, width);
        printf("angles X %lf Y %lf Z %lf \n", angleX, angleY, angleZ);

        numberObject = caractereToNumber(f);
        numberLight = caractereToNumber(f);
        printf("numberO %d numberL %d \n", numberObject, numberLight);
        
        /*char * name = caractereToName(f);
        printf("name %s\n",name);
        Ellipse E = getEllipse(f);
        printf("ellipse %lf %lf %lf %lf %lf %lf \n",E.a,E.b,E.c,E.x,E.y,E.z);
        char * nameB = caractereToName(f);
        printf("name %s\n",nameB);
        Brick B = getBrick(f);
        printf("brick %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf, %lf %lf %lf\n",B.a.x,B.a.y,B.a.z,B.b.x,B.b.y,B.b.z,B.c.x,B.c.y,B.c.z,B.d.x,B.d.y,B.d.z,B.e.x,B.e.y,B.e.z,B.f.x,B.f.y,B.f.z,B.g.x,B.g.y,B.g.z,B.h.x,B.h.y,B.h.z);
        char * nameL = caractereToName(f);
        Light L = getLight(f);
        printf("light %s %lf %lf %lf \n", nameL, L.lightSource.x, L.lightSource.y, L.lightSource.z);*/
        
        L = objectFromFile(f); 

        afficheList(L);
          //char * name = caractereToName(f);

          /*int type = whichType(name);
          Brick B = getBrick(f);
          free(name);
          printf("free");
          name = caractereToName(f);
          type = whichType(name);
          printf("type1 %d", type);*/

       // afficheList(L);
        //rayTracer(L,)
        //-------test-------//
       /* Brick B;
        B.a.x = 0;
        B.a.y = 3;
        B.a.z = 0;

        B.b.x = 2;
        B.b.y = 3;
        B.b.z = 0;

        B.c.x = 2;
        B.c.y = 1;
        B.c.z = 0;

        B.d.x = 0;
        B.d.y = 1;
        B.d.z = 0;

        B.e.x = 0;
        B.e.y = 3;
        B.e.z = 2;

        B.f.x = 2;
        B.f.y = 3;
        B.f.z = 2;

        B.g.x = 2;
        B.g.y = 1;
        B.g.z = 2;

        B.h.x = 0;
        B.h.y = 1;
        B.h.z = 2;
        printf("%d\n", DoesBrickExist(B));

        Line M;
        M.directionVector.x = 1;
        M.directionVector.y = 1;
        M.directionVector.z = 1;

        M.pt.x = 0;
        M.pt.y = 0;
        M.pt.z = 0;


        Plane Plan = planeEquationFromPoints(B.g,B.e,B.f);
        affichePlan(Plan);

        printf("\n");

        Point I = pointIntersectionLineAndPlane(M,Plan);
        affichePoint(I);
        Point li[4];
        li[0] = B.g;
        li[1] = B.e;
        li[2] = B.f;
        li[3] = B.h;
        int yo = isOnPolygon(li, 4, I);
        printf("dans le polygone ? %d \n", yo);

        I = contactBrickWithLine(B,M);
        affichePoint(I);

        //------goat-------//

        printf("\n");
        printf("\n");
        printf("\n");

        Point gA = setPoint(0,0,1);
        Point gB = setPoint(4,2,3);
        Point gC = setPoint(-3,1,1);
        Point gD = setPoint(0,0,0);

        affichePoint(gA);printf("\n");
        affichePoint(gB);printf("\n");
        affichePoint(gC);printf("\n");

        Vector gV = normalVector(gA, gB, gC);

        printf("%lf, %lf, %lf\n", gV.x, gV.y, gV.z);

        Plane gP = planeEquationFromPoints(gA, gB, gC);

        affichePlan(gP);printf("\n");

        printf("Oui: %d | Non: %d\n", isPointOnPlane(gA, gP), isPointOnPlane(gD, gP));

        Line gLA;
        gLA.pt.x = 10;
        gLA.pt.y = 10;
        gLA.pt.z = 10;
        gLA.directionVector.x = -1;
        gLA.directionVector.y = -3;
        gLA.directionVector.z = -5;

        Line gLB;
        gLB.pt.x = 20;
        gLB.pt.y = 20;
        gLB.pt.z = 20;
        gLB.directionVector.x = 1;
        gLB.directionVector.y = 2;
        gLB.directionVector.z = 3;

        affichePoint(pointIntersectionLineAndPlane(gLA, gP)); printf("\n");
        affichePoint(pointIntersectionLineAndPlane(gLB, gP));
        afficheVector(V);
        afficheVector(matriceRotation(V,_PI,0,0));
        printf("produit scalaire %lf", scalarProduct(V, matriceRotation(V,_PI,0,0)));
        Vector V;
        V.x = 1; V.y = 1; V.z = 1;
        printf("\n");

        afficheVector(matriceRotation(V,_PI,0,_PI));*/
        //-------fin-------//

        //-----------------//
 
        return 0;
  
    }

    fclose(f);
    free(L);
    return 0;
}
