// htab_size.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Vráti celkový počet všetkých položiek v tabuľke.
#include <stdio.h>
#include <stdlib.h>
#include "htab.h"


size_t htab_size(struct htab_t* t){
	return t->n;
}