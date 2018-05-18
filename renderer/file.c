#include "file.h"


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
    char curCaractere = '\0';
     while(curCaractere != ',' && curCaractere != ';' && curCaractere != EOF) {
        curCaractere = fgetc(f);
        if(curCaractere == '-') {
            test = 1;
        }
        number = number * 10 + atoi(curCaractere);
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
    name = (char *)malloc(sizeof(char));
    int nbletter = 0;
    int test = 0;
    char curCaractere = '\0';
     while(curCaractere != ',' && curCaractere != ';' && curCaractere != EOF) {
        nbletter++;
        curCaractere = fgetc(f);
        name = (char *)realloc(name, sizeof(char) * nbletter);
        *(name + nbletter) = curCaractere;
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
*  Give an ellipse from a file
* 
* @param f: file
*
* @return an ellipse 
*/
Ellipse fileToEllipse(FILE * f) {
    Ellipse E;
    E.x = caractereToNumber(f);
    E.y = caractereToNumber(f);
    E.z = caractereToNumber(f);
    E.a = caractereToNumber(f);
    E.b = caractereToNumber(f);
    E.c = caractereToNumber(f);
}

/**
*  Give the position of a light from a file
* 
* @param f: file
*
* @return an ellipse 
*/
Light fileToLight(FILE * f) {
    Light L;
    L.lightSource.x = caractereToNumber(f);
    L.lightSource.y = caractereToNumber(f);
    L.lightSource.z = caractereToNumber(f);
    return L;
}
