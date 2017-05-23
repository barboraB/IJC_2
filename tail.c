// tail.c
// Řešení IJC-DU2, příklad b), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Vypíše posledných n riadkov zo súboru.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEF_TAIL 10 /**< Default number of last lines.*/
#define LIN_LIMIT 1024 /**< Maximum length of a line. */


/**
 * Function will allocate array of pointers to the string.
 * @param num Size of array to be allocated.
 * @return Allocated array of pointers to the string.
 */
char** ptr_alloc(int num){
	char **ptrs = malloc(sizeof(char*)*num);
	if(ptrs == NULL){
		return NULL;
	}
	for(int i = 0; i < num; i++){
		ptrs[i] = NULL;
	}
	return ptrs;
}

/**
 * Function will deallocate an array of pointers to the string.
 * @param ptr Array to be deallocated.
 * @param Size size of the array.
 */
void ptr_dealloc(char** ptr, int size){
	for(int i = 0; i < size; i++){
		free(ptr[i]);
	}
	free(ptr);
}

/**
 * Function will add the string to the required position in array.
 * @param s String to be added.
 * @param ptr Array where the string shoul be added.
 * @param position Position in the array. 
 */
void ptr_add(char* s, char** ptr, int position){
	ptr[position] = s;
}

/**
 * Function will remove string on a required position from an array.
 * @param ptr Array where is string to be removed.
 * @param position Position of the string in array.
 */
void ptr_remove(char** ptr, int position){
	free(ptr[position]);
}

/**
 * Function will print the array of string.
 * @param ptrs Array to be printed.
 * @param size Size of the array.
 * @param head Position in the array to which the last line was copied.
 */
void print_lines(char **ptrs, int size, int head){
	for(int i = head; i < size; i++){
		if(ptrs[i] == NULL) break;
		printf("%s", ptrs[i]);
	}
	for(int i = 0; i < head; i++){
		printf("%s", ptrs[i]);
	}
}


int main(int argc, char const *argv[])
{
	int last_lines = DEF_TAIL; /**< Number of lines to be printed. Default when initialized. */
	int std_flag = 0; /**< Check if the read is from file or stdin. */
	int position = 3; /**< Position of the agument with a name of file to be opened. */

	// Argument parsing
	if (argc == 1){
		std_flag = 1;
		last_lines = DEF_TAIL;
	} else if (argc == 2){
		position = 1;
		last_lines = DEF_TAIL;
	} else if (argc == 3){
		std_flag = 1;
		if((strcmp(argv[1], "-n")) != 0){
			fprintf(stderr,"Zadany zly format argumentov.\n");
			return EXIT_FAILURE;
		}
		last_lines = strtol(argv[2], NULL, 10);
	} else if (argc == 4){
		last_lines = strtol(argv[2], NULL, 10);
	}
	if(last_lines <= 0){
		fprintf(stderr,"Pocet riadkov na vypisanie musi byt vacsi ako 0.\n");
		return EXIT_FAILURE;
	}

	// Opening either stdin of file, depends on arguments given when run.
	FILE *f;
	if(!std_flag){
		f = fopen(argv[position], "r");
		if(f == NULL) {
			fprintf(stderr, "Nepodarilo sa otvorit subor. \n");
			return EXIT_FAILURE;
		}
	} else {
		f = stdin;
	}
	
	char **ptrs = ptr_alloc(last_lines); /**< Array of pointers to strings.*/
	if(ptrs == NULL){
		fprintf(stderr, "Problem pri alokacii.\n");
	}
	char *string = malloc(sizeof(char)*LIN_LIMIT); /**< String to be stored in array.*/

	int c;
	int pos = 0; /**< Variable to determine where the last line was stored. */
	int i = 0; /**< Iteration*/

	// Reading from a file to the array.
	while((c = fgetc(f)) != EOF){
		string[i] = c;
		i++;
		if(i == LIN_LIMIT-2){
			fprintf(stderr, "Bol prekroceny limit jedneho riadku.\n");
			string[i] = '\n';
			i++;
			while((c = fgetc(f)) != '\n');
		}
		if(c == '\n'){
			string[i] = '\0';
			ptr_remove(ptrs, pos);
			ptr_add(string, ptrs, pos);
			pos++;
			i = 0;
			string = malloc(sizeof(char)*LIN_LIMIT);
			if(string == NULL){
				fprintf(stderr, "Problem pri alokacii.\n");
				return EXIT_FAILURE;
			}
		}
		if(pos == last_lines){
			pos = 0;
		}
	}

	// Printing and deallocating.
	print_lines(ptrs, last_lines, pos);

	if(!std_flag){
		fclose(f);
	}
	ptr_dealloc(ptrs, last_lines);
	free(string);

	return EXIT_SUCCESS;
}

