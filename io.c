// io.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Prečíta jedno slovo zo zadaného súboru.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * Function will read one word from a given file.
 * @param s String where the word will be stored.
 * @param max Maximum length of the word.
 * @param f File tobe read from.
 * @return Length of the word (without '/0').
 */

int get_word(char *s, int max, FILE *f){
	int c;
	int i = 0;
	static int error = 0;


	while(isspace(c = fgetc(f))){
	}

	int count = 1;
	int flag = 0;
	s[i] = c;

	while(!isspace(c = fgetc(f))){
		if(c == EOF){
			return EOF;
		}
		i++;
		s[i] = c;
		count++;
		if(count == max){
			error += 1;
			if(error == 1){
				fprintf(stderr, "Bolo skratene slovo.\n");
			}
			flag = 1;
			break;	
		}
	}

	if(flag){
		while(!isspace(c = fgetc(f))){
			continue;
		}
	}
	s[i+1] = '\0';

	ungetc(c, f);
	return count;
} 