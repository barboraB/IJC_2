// htab_find.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Nájde položku zoznamu poďla kľúča.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htab.h"



struct htab_listitem * htab_find(struct htab_t *t, const char *key){
	unsigned int hash = hash_function(key);
	unsigned int index = hash % t->arr_size;

	struct htab_listitem* res = NULL;
	struct htab_listitem* pom = t->array[index];

	while(pom != NULL){
		if(strcmp(pom->key, key) == 0){
			res = pom;
		}
		pom = pom->next;
	}
	return res;

}