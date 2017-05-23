// htab_foreach.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Pre každý item zoznamu zavolá funkciu.
#include <stdlib.h>
#include <stdio.h>
#include "htab.h"

void htab_foreach(struct htab_t* t, int (*func)(const char* key, struct htab_listitem*)){
	struct htab_listitem* pom = NULL;
	for(size_t i = 0; i < htab_bucket_count(t); i++){
		pom = t->array[i];
		while(pom != NULL){
			func(pom->key, pom);
			pom = pom->next;
		}
	}
}