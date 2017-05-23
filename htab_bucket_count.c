// htab_bucket_count.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Vráti veľkosť alokovaného poľa.
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"


size_t htab_bucket_count(struct htab_t* t){
	return t->arr_size;
}