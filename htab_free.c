// htab_free.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Uvoľní tabuľku.
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"

void htab_free(struct htab_t* t){
	free(t);
}