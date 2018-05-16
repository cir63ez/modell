#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "list.h"
#include "ellipse.h"
#include "brick.h"



/**
* Create an ellipse element for the list
* @param E: Ellipse's name
*
* @return an element ellipse created
*/
Element * createElementEllipse(Ellipse E) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        return NULL; //TODO: exit ?;
    }
    else {
        element->type = ELLIPSE_TYPE;
        element->object = encodeEllipse(E);
        element->next = NULL;
        return element;
    }
}

/**
* Create an ellipse element for the list
* @param B: Brick's name
*
* @return an element ellipse created
*/
Element * createElementBrick(Brick B) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        return NULL; //TODO: exit ?;
    }
    else {
        element->type = BRICK_TYPE;
        element->object = encodeBrick(B);
        element->next = NULL;
    }
}


/**
* Delete the last element of the list
* @param B: tete's list
*
* @return void
*/
void deleteElementList(List * tete){
    List * curElement = tete;
    if (!isEmpty(tete)) {
      while (curElement != NULL) {
        curElement = curElement->tete->next;
      }
      free(curElement);
      tete->nbElement--;
    }
}