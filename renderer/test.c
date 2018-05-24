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

int main() {
	/*// pointsToVector
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
	remi.pt.x = 1;
	remi.pt.y = 1;
	remi.pt.z = 2;
	remi.directionVector.x = 1;
	remi.directionVector.y = 1;
	remi.directionVector.z = 0;
	Ellipse chocolat;
	chocolat.x = 1;
	chocolat.y = 1;
	chocolat.z = 2;
	chocolat.a = 1;
	chocolat.b = 1.5;
	chocolat.c = 1;
	double Az = (pow(remi.directionVector.x / chocolat.a, 2) + pow(remi.directionVector.y / chocolat.b, 2) + pow(remi.directionVector.z / chocolat.c, 2));
	double Bz = (remi.directionVector.z * (remi.pt.z - chocolat.z)) / pow(chocolat.c, 2);
    Bz = (remi.directionVector.x * (remi.pt.x - chocolat.x)) / pow(chocolat.a, 2) + (remi.directionVector.y * (remi.pt.y - chocolat.y))/pow(chocolat.b, 2) + Bz;
	double Cz = pow( (remi.pt.x - chocolat.x) / chocolat.a, 2) + pow((remi.pt.y - chocolat.y) / chocolat.b, 2) + pow((remi.pt.z - chocolat.z) / chocolat.c, 2) - 1;
	double delta = 4 * (pow(Bz,2) - Az * Cz);
	printf("A = %lf B = %lf C = %lf delta : %lf", Az, Bz, Cz, delta);

	Point JM;
	JM = contactEllipseWithLine(chocolat,remi);
	printf("ellipse : %lf,%lf,%lf\n", JM.x,JM.y,JM.z);*/

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

	Point I;

	Plane P = planeEquationFromPoints(PA,PB,PD);

	Vector V = vectorInPlane(PA, P);
	int test = isPointOnPlane(PC, P);

	printf("%d\n",test);

	P.a = 0;
	P.c = 0;
	P.x = 1;
	I.x = 2;
    I.y = 3;
    I.z = (P.a * (I.x - P.x) + P.b * (I.y - P.y) - P.c * P.z) / P.c;
	
	V = vectorInPlane(PA, P);
	test = isPointOnPlane(PC, P);
	printf("%d\n",test);

	Line l;
	l.pt.x = 1;
	l.pt.y = 3;
	l.pt.z = -1;
	l.directionVector.x = 2;
	l.directionVector.y = -1;
	l.directionVector.z = 1;
	
	Line p;
	p.pt.x = 19;
	p.pt.y = -4;
	p.pt.z = 10;
	p.directionVector.x = 3;
	p.directionVector.y = -1;
	p.directionVector.z = 2;

	Point BL;
	BL.x = 13;
	BL.y = -3;
	BL.z = 5;

	Point CL;
	CL.x = 3;
	CL.y = 2;
	CL.z = 0;

	Point M = pointIntersectionLineAndLine(l,p);
	affichePoint(M);

	Point Q = pointIntersectionLineAndSegment(l.pt, BL, p);
	Point G = pointIntersectionLineAndSegment(l.pt, CL, p);

	affichePoint(Q);
	affichePoint(G);
/*
	Line L;
	L.pt.x = -3;
	L.pt.y = -1;
	L.pt.z = 6;
	L.directionVector.x = 2;
	L.directionVector.y = 1;
	L.directionVector.z = -1;

	Line LB;
	LB.pt.x = 1;
	LB.pt.y = -2;
	LB.pt.z = 8;
	LB.directionVector.x = 1;
	LB.directionVector.y = 1;
	LB.directionVector.z = -1;

	Point A,B,C,D,E;
	A = setPoint(2,1,3);
	B = setPoint(3,1,4);
	C = setPoint(3,2,5);
	D = setPoint(1,3,4);
	E = setPoint(0,3,3);

	Point ListeDePoints[5];
	ListeDePoints[0] = A;
	ListeDePoints[1] = B;
	ListeDePoints[2] = C;
	ListeDePoints[3] = D;
	ListeDePoints[4] = E;

	Plane P = planeEquationFromPoints(A,B,C);
	Point Test = pointIntersectionLineAndPlane(L, P);

	affichePoint(Test);
	printf("%d\n", isOnPolygon(ListeDePoints, 5, Test));


	Point TestB = pointIntersectionLineAndPlane(LB, P);

	affichePoint(TestB);
	printf("---****---\n");
	printf("on polygone ? %d\n", isOnPolygon(ListeDePoints, 5, setPoint(4,1,3)));*/
	return 0;
}
