#include "list.h"

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
