#include "list.h"

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
        exit(-1);
    }
    else {
        element->type = BRICK_TYPE;
        element->object = encodeBrick(B);
        element->next = NULL;
    }
}

/**
* Create an ellipse element for the list
* @param B: Brick's name
*
* @return an element ellipse created
*/
Element * createElementTetrahedron(Tetrahedron T) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        exit(-1);
    }
    else {
        element->type = TETRAHEDRON_TYPE;
        element->object = encodeTetrahedron(T);
        element->next = NULL;
    }
}


/**
* Delete the last element of the list
* @param B: tete's list
*
* @return void
*/
void deleteElementList(List * list) {
    if(list->tete != NULL) {
        Element *previous = NULL;
        Element *current = list->tete;

        while(current->next != NULL) {
            previous = current;
            current = current->next;
        }

        if(previous != NULL) {
            previous->next = NULL;
        }

        free(current);
    }
}
