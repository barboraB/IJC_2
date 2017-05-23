// htab_init.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Inicializuje novú tabuľku.
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

struct htab_t* htab_init(size_t size){
	struct htab_t* t = (struct htab_t*)malloc(sizeof(struct htab_t) + size*sizeof(struct htab_listitem*));
	if(t == NULL){
		return NULL;
	}
	// Initialize array.
	for(size_t i = 0; i < size; i++){
		t->array[i]=NULL;
	}
	t->arr_size = size;
	t->n = 0;
	return t;
}