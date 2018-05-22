#pragma once
#include "lib.h"
#include "objects.h"
#include "raytracer.h"

int main() {
	// pointsToVector
	Point A;
	Point B;

	A.x = 0;
	A.y = 0;
	A.z = 0;

	B.x = 2;
	B.y = 3;
	B.z = 4;

	Vector v = pointsToVector(A, B);

	printf("(%lf, %lf, %lf)\n", v.x, v.y, v.z);

	// sumVectors & differenceVectors
	Vector vB;

	vB.x = 1;
	vB.y = 2;
	vB.z = 3;

	Vector vC = substractVectors(v, vB);

	printf("(%lf, %lf, %lf)\n", vC.x, vC.y, vC.z);

	// scalarProduct

	double scalar = scalarProduct(v, vC);

	printf("%lf\n", scalar);

	// norm

	double dist = norm(v);

	printf("%lf\n", dist);

	// angle

	double ang = angle(v, vC);

	printf("%lf\n", ang);

	// arePointsAligned

	Point PA;

	PA.x = 0;
	PA.y = 0;
	PA.z = 0;

	Point PB;

	PB.x = 1;
	PB.y = 1;
	PB.z = 1;

	Point PC;

	PC.x = 2;
	PC.y = 2;
	PC.z = 2;

	Point PD;

	PD.x = 2;
	PD.y = 2;
	PD.z = 3;

	printf("%d\n", arePointsAligned(PA, PB, PC));
	printf("%d\n", arePointsAligned(PA, PB, PD));

	// normalVector

	Vector nV;
	nV=normalVector(PA,PB,PD);
	printf("%lf,%lf,%lf vecteur normal\n",nV.x,nV.y,nV.z);

	nV=normalVector(PA,PB,PC);
	printf("%lf,%lf,%lf\n",nV.x,nV.y,nV.z);

	//planeEquationFromPoints

	Plane P;
	P=planeEquationFromPoints(PA,PB,PC);
	printf("a=%lf,b=%lf,c=%lf,x=%lf,y=%lf,z=%lf, goes wrong\n",P.a,P.b,P.c,P.x,P.y,P.z);
	P=planeEquationFromPoints(PA,PB,PD);
	printf("a=%lf,b=%lf,c=%lf,x=%lf,y=%lf,z=%lf, goes well\n",P.a,P.b,P.c,P.x,P.y,P.z);

// pointIntersectionLineAndPlane

	Line l;
	l.pt.x=0;
	l.pt.y=0;
	l.pt.z=0;
	l.directionVector.x=1;
	l.directionVector.y=0;
	l.directionVector.z=0;
	Plane W;
	W.a=9;
	W.b=0;
	W.c=-2;
	Point U;
	U=pointIntersectionLineAndPlane(l,W);
	printf("%lf,%lf,%lf\n",U.x,U.y,U.z);
	W.a=0;
	U=pointIntersectionLineAndPlane(l,W);
	printf("%lf,%lf,%lf\n",U.x,U.y,U.z);

	//reflectedRay
	Line Li;
	Vector R;
	Li=reflectedRay(PA,pointsToVector(A,B),pointsToVector(PA,PB),1.5,1.2);
	printf("%lf,%lf,%lf",Li.pt.x,Li.pt.y,Li.pt.z);
	printf("%lf,%lf,%lf\n",Li.directionVector.x,Li.directionVector.y,Li.directionVector.z);
	Li=refractedRay(PA,pointsToVector(A,B),pointsToVector(PA,PB),1.5,1.2);
	printf("%lf,%lf,%lf",Li.pt.x,Li.pt.y,Li.pt.z);
	printf("%lf,%lf,%lf\n",Li.directionVector.x,Li.directionVector.y,Li.directionVector.z);

	//isOnPolygon
	double numberOfPoint = 4;
	Point* lp;
	lp=malloc(sizeof(Point)*numberOfPoint);
	Point ppa;
	ppa.x=1;
	ppa.y=1;
	ppa.z=1;
	Point ppb;
	ppb.x=6;
	ppb.y=6;
	ppb.z=6;
	Point ppc;
	ppc.x=-2;
	ppc.y=-2;
	ppc.z=-2;
	Point ppd;
	ppd.x=1;
	ppd.y=6;
	ppd.z=4;
	Point ppt;
	ppt.x=2;
	ppt.y=1;
	ppt.z=2;

	lp[0]=ppa;
	lp[1]=ppb;
	lp[2]=ppc;
	lp[3]=ppd;
	printf("%d\n",isOnPolygon(lp,numberOfPoint,ppt));

	ppt.x=99;
	ppt.y=99;
	ppt.z=99;
	printf("%d\n",isOnPolygon(lp,numberOfPoint,ppt));

	// contactEllipseWithLine(Ellipse E, Line L);

	Line remi;
	remi.pt.x = 0;
	remi.pt.y = 0;
	remi.pt.z = 0;
	remi.directionVector.x = 0;
	remi.directionVector.y = 0;
	remi.directionVector.z = 1;
	Ellipse chocolat;
	chocolat.x = 0;
	chocolat.y = 0;
	chocolat.z = 5;
	chocolat.a = 0.5;
	chocolat.b = 0.5;
	chocolat.c = 0.5;
	Point JM;
	JM=contactEllipseWithLine(chocolat,remi);
	printf("%lf,%lf,%lf\n", JM.x,JM.y,JM.z);
	return 0;
}
