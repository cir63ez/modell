#include "lib.h"

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

	Vector vC = differenceVectors(v, vB);

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

	//firstPlaneSeen




	return 0;
}
