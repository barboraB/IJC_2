// htab_lookup_add.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Vymaže všetky položky tabuľky, nechá tabuľku prázdnu.
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

void htab_clear(struct htab_t* t){
	struct htab_listitem* pom = NULL;
	struct htab_listitem* temp = NULL;

	for(size_t i = 0; i < htab_bucket_count(t); i++){
		pom = t->array[i];
		while(pom != NULL){
			temp = pom->next;
			htab_remove(t, pom->key);
			pom = temp;
		}
	}
	t->n = 0;
}