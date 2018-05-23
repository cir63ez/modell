#include "file.h"



/////--------------A CHANGER DE PLACE--------------//////
/**
 * Give the vector of a rotation
 * 
 * @param V: vector to change
 * @param tetaX: angle of rotation on x axe
 * @param tetaY: angle of rotation on y axe
 * @param tetaZ: angle of rotation on z axe
 *  
 * @return vector changed
 */ 
Vector matriceRotation(Vector V, double tetaX, double tetaY, double tetaZ) {
    Vector vPrime;
    vPrime.x = V.x;
    vPrime.y = V.y * cos(tetaX) + V.z * sin(tetaX);
    vPrime.z = -V.y * sin(tetaX) + V.z * cos(tetaX);
    
    V = vPrime;

    vPrime.x = V.x * cos(tetaY) - V.z * sin(tetaY);
    vPrime.y = V.y;
    vPrime.z = V.x * sin(tetaY) + V.z * cos(tetaY);
    
    V = vPrime;

    vPrime.x = V.x * cos(tetaZ) + V.y * sin(tetaZ);
    vPrime.y = - V.x * sin(tetaZ) + V.y * cos(tetaZ);
    vPrime.z = V.y;

    return vPrime;
}

// Give the vector of a rotation
Vector matriceRotation(Vector V, double tetaX, double tetaY, double tetaZ);

/////---------------------FIN----------------------//////

/**
*  Change caracteres into a number from a file
* 
* @param f: file
*
* @return the number from the caracteres
*/
int caractereToNumber(FILE * f) {
    int number = 0;
    int test = 0;
    char curCaractere = fgetc(f);
     while(curCaractere != ',' && curCaractere != ';' && curCaractere != EOF) {
        if(curCaractere == '-') {
            test = 1;
        }
        number = number * 10 + charToInt(curCaractere);
        curCaractere = fgetc(f);
    }
    if(test) {
        number = number * (-1);
    }
    return number;
}

/**
 *  Change caracteres into an object name from a file
 * 
 * @param f: file  
 * 
 * @return a char array
 */
char * caractereToName(FILE * f) {
    char *name;
    char *endOfFile;
    name = (char *)malloc(sizeof(char));
    int nbletter = 0;
    int test = 0;
    char curCaractere = '\0';
    curCaractere = fgetc(f);
     while(curCaractere != ',' && curCaractere != ';' && curCaractere != EOF) {
        name = (char *)realloc(name, sizeof(char) * (nbletter + 1));
        *(name + nbletter) = curCaractere;
        nbletter++;
        curCaractere = fgetc(f);
    }
    if(curCaractere == EOF) { 
        return "endoffile";
    }
    return name;
}

/**
*  Give point in the image plane from a file
* 
* @param f: file
*
* @return a point in the image plane
*/
Point pointPlaneFile (FILE * f) {
    rewind(f);
    Point P;
    P.x = caractereToNumber(f);
    P.y = caractereToNumber(f);
    P.z = caractereToNumber(f);
    return P;
}

/**
*  Give the normal vector of the image plane from a file
* 
* @param f: file
*
* @return a point in the image plane
*/
Vector normalVectorPlaneFile (FILE * f) {
    Vector V;
    V.x = caractereToNumber(f);
    V.y = caractereToNumber(f);
    V.z = caractereToNumber(f);
    return V;
}

/**
*  Give the number of caractere of a number or a word between txo ','
* 
* @param f: file
*
* @return the number of caractere
*/
int numberCaractere(FILE * f) {
    int nbCaractere = 0;
    char curCaractere = '\0';

    while(curCaractere != ',' && curCaractere != ';' && curCaractere != EOF) {
        curCaractere = fgetc(f);
        nbCaractere++;
    }
    return nbCaractere;
}

/**
*  Give the type of an object
* 
* @param name: name to compare
*
* @return the type of the object
*/
int whichType(char * name) {
    char *ellipse = "ellipsoid";
    char *brick = "tetrahedron";
    char *tetrahedron = "brick";
    char *light = "light";
    
    if(strcmp(ellipse, name)) {
        return ELLIPSE_TYPE;
    }
    if(strcmp(tetrahedron, name)) {
        return TETRAHEDRON_TYPE;
    }
    if(strcmp(brick, name)) {
        return BRICK_TYPE;
    }
    if(strcmp(light, name)) {
        return LIGHT_TYPE;
    }
}

/**
 * Get the list of objects from a file
 * 
 * @param f: File 
 * 
 * @return liste of object
 */
List * objectFromFile(FILE * f) {
    int type;
    char *endOfFile = "endoffile";
    double *object;
    char *name;
    Element *e;
    List *L;
    L = initList();

    name = caractereToName(f);

    type = whichType(name);

    while(strcmp(name, endOfFile)) {
        object = objectTreatement(type, f);
        if(type == BRICK_TYPE) {
            e = createElementBrick(object);
        }
        if(type == ELLIPSE_TYPE) {
            e = createElementEllipse(object);
        }
        if(type == TETRAHEDRON_TYPE) {
            e = createElementTetrahedron(object);
        }
        if(type == LIGHT_TYPE) {
            e = createElementLight(object);
        }   
        addElementList(e, L);
        name = caractereToName(f);
        type = whichType(name);

    }
    return L;
}


/**
* Give a brick from a file
* 
* @param f: file
*
* @return a brick
*/
Brick getBrick(FILE * f) {
    Brick B;
    B.a.x = (double)caractereToNumber(f);
    B.a.y = (double)caractereToNumber(f);
    B.a.z = (double)caractereToNumber(f);
    B.b.x = (double)caractereToNumber(f);
    B.b.y = (double)caractereToNumber(f);
    B.b.z = (double)caractereToNumber(f);
    B.c.x = (double)caractereToNumber(f);
    B.c.y = (double)caractereToNumber(f);
    B.c.z = (double)caractereToNumber(f);
    B.d.x = (double)caractereToNumber(f);
    B.d.y = (double)caractereToNumber(f);
    B.d.z = (double)caractereToNumber(f);
    B.e.x = (double)caractereToNumber(f);
    B.e.y = (double)caractereToNumber(f);
    B.e.z = (double)caractereToNumber(f);
    B.f.x = (double)caractereToNumber(f);
    B.f.y = (double)caractereToNumber(f);
    B.f.z = (double)caractereToNumber(f);
    B.g.x = (double)caractereToNumber(f);
    B.g.y = (double)caractereToNumber(f);
    B.g.z = (double)caractereToNumber(f);
    B.h.x = (double)caractereToNumber(f);
    B.h.y = (double)caractereToNumber(f);
    B.h.z = (double)caractereToNumber(f);
    return B;
}

/**
*  Give a tetrahedron from a file
* 
* @param f: file
*
* @return a tetrahedron 
*/
Tetrahedron getTetrahedron(FILE * f) {
    Tetrahedron T;
    T.a.x = caractereToNumber(f);
    T.a.y = caractereToNumber(f);
    T.a.z = caractereToNumber(f);
    T.b.x = caractereToNumber(f);
    T.b.y = caractereToNumber(f);
    T.b.z = caractereToNumber(f);
    T.c.x = caractereToNumber(f);
    T.c.y = caractereToNumber(f);
    T.c.z = caractereToNumber(f);
    T.d.x = caractereToNumber(f);
    T.d.y = caractereToNumber(f);
    T.d.z = caractereToNumber(f);
    return T;
}

/**
*  Give an ellipse from a file
* 
* @param f: file
*
* @return an ellipse 
*/
Ellipse getEllipse(FILE * f) {
    Ellipse E;
    E.a = caractereToNumber(f);
    E.b = caractereToNumber(f);
    E.c = caractereToNumber(f);
    E.x = caractereToNumber(f);
    E.y = caractereToNumber(f);
    E.z = caractereToNumber(f);
    return E;
}

/**
* Give a light from a file
* 
* @param f: file
*
* @return a light
*/
Light getLight(FILE * f) {
    Light L;
    L.lightSource.x = caractereToNumber(f);
    L.lightSource.y = caractereToNumber(f);
    L.lightSource.z = caractereToNumber(f);
    return L;
}

/**
* Treat the object to have a string of an object
* 
* @param type: object's type
* @param f: file
*
* @return a the string of an object
*/
double * objectTreatement(int type, FILE * f) {
    Brick B;
    Tetrahedron T;
    Ellipse E;
    Light L;
    double * object;
    if(type == BRICK_TYPE) {
        B = getBrick(f);
        object = encodeBrick(B);
    }
    if(type == ELLIPSE_TYPE) {
        E = getEllipse(f);
        object = encodeEllipse(E);
    }
    if(type == TETRAHEDRON_TYPE) {
        T = getTetrahedron(f);
        object = encodeTetrahedron(T);
    }
    if(type == LIGHT_TYPE) {
        L = getLight(f);
        object = encodeLight(L);
    }
    return object;
}
