// wordcount.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Main programu, počíta počet výskytu slova zo stdin.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"

#define ARR_SIZE 8000 /**< Size of the array.*/
#define WORD_LIMIT 127 /**< Max length of a word.*/
int get_word(char *s, int max, FILE *f);

int main()
{
	char string[WORD_LIMIT];
	/*

	Testovanim utilitou time som zistila, ze cim je nainicializovane pole vacsie, tym rychlejsie
	je spracovanie slov, co vychadza z toho, ze je lepsie mat viac jednopolozkovych zoznamov a 
	pristupovat k nim nahodne, ako malo a hladat ich v dlhsich zoznamoch. Preto som zvolila velkost
	pola 8000, cim spracujem takmer 500 000 slov za asi 2,5 sekundy. 

	*/
	struct htab_t* table = htab_init(ARR_SIZE);

	if (table == NULL){
		return EXIT_FAILURE;
	}

	while(get_word(string, WORD_LIMIT, stdin) != EOF){
		char *str = malloc(sizeof(char)*(strlen(string)+1));
		strcpy(str, string);
		htab_lookup_add(table, str);
	}
	
	htab_foreach(table, htab_print_item);
	
	htab_clear(table);
	htab_free(table);

	return 0;
}