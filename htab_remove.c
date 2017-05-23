// htab_remove.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Odstráni položku zoznamu v tabuľke
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include <stdbool.h>
#include <string.h>

bool htab_remove(struct htab_t* t, const char* key){
	unsigned int hash = hash_function(key);
	unsigned int index = hash % htab_bucket_count(t);
	
	struct htab_listitem* to_erase = NULL;

	if((to_erase = htab_find(t, key)) == NULL) return false;

    //If the first item of the list is the one to be removed.
	if (strcmp(key, t->array[index]->key) == 0) {
        struct htab_listitem * temp = t->array[index];
        t->array[index] = t->array[index]->next;
        free((void *)temp->key);
        free(temp);
        return true;
    }
    //If it is something in the middle/at the end.
   	struct htab_listitem * pom = t->array[index]->next; /**< The one we are going to erase.*/
    struct htab_listitem * previous = t->array[index]; /**< Previous item for correct removing from the list. */
    while (pom != NULL && previous != NULL) {
        if (strcmp(key, pom->key) == 0) {
            struct htab_listitem * temp = pom;
            previous->next = pom->next;
            free((void*)temp->key);
            free(temp);
            return true;
        }
        previous = pom;
        pom = pom->next;
    }


    return true;

}