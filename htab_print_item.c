// htab_print_item.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Vypíše zadanú položku zoznamu.
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

int htab_print_item(const char* key, struct htab_listitem* item){
	if(printf("%s\t%lu\n", key, item->data) < 0){
		return 1;
	}
	return 0;
}