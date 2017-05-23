#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"


struct htab_t * htab_move(size_t newsize, struct htab_t* t2){
	struct htab_t* new = htab_init(newsize);
	struct htab_listitem * pom = NULL; /**< Variable for iteration.*/
	struct htab_listitem * check = NULL; 
	//Iteration through the array and copying the items.
	for(size_t i = 0; i < htab_bucket_count(t2); i++){
		pom = t2->array[i];
		while(pom != NULL){
			char* new_string = malloc(sizeof(char)*(strlen(pom->key)+1));
			strcpy(new_string, pom->key);
			check = htab_lookup_add(new, new_string);
			check->data = pom->data;
			pom = pom->next;
		}
	}
	htab_clear(t2);
	return new;
}
