// htab_lookup_add.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Nájde a pridá novú položku na koniec zoznamu.
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

struct htab_listitem * htab_lookup_add(struct htab_t* t, const char* key){

	struct htab_listitem * pom = htab_find(t, key);
	struct htab_listitem * iter = NULL;

	// If the item with the key was not found.
	if(pom == NULL){
		unsigned int hash = hash_function(key);
		unsigned int index = hash % htab_bucket_count(t);
		iter = t->array[index];

		struct htab_listitem* new = (struct htab_listitem *) malloc(sizeof(struct htab_listitem));
		if(new == NULL){
			return NULL;
		}

		new->key = key;
		new->data = 1;

		// Add to the end of list
		if(t->array[index] == NULL){
			t->array[index] = new;
			t->array[index]->next = NULL;
		} else {
			while(iter->next != NULL){
				iter = iter->next;
			}
			iter->next = new;
			new->next = NULL;
		}
		// Increase the number of appearances.
		t->n += 1;
		return new;
	// If the item with the key was found.	
	} else {
		free((void*)pom->key);
		pom->key = key;
		pom->data += 1;
		return pom;
	}
}