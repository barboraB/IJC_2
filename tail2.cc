// tail2.cc
// Řešení IJC-DU2, příklad a), 25.4.2017
// Autor: Barbora Blašková, FIT
// Přeloženo: gcc 6.3.1
// Vypíše posledných n riadkov zo vstupného súboru.
#include <iostream>
#include <string>
#include <fstream>
#include <queue>

#define DEF_TAIL 10
using namespace std;

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int last_lines = 10;
	int std_flag = 0;
	int position = 3;
	string arg ("-n");
	string line;

	if (argc == 1){
		std_flag = 1;
		last_lines = DEF_TAIL;
	} else if (argc == 2){
		position = 1;
		last_lines = DEF_TAIL;
	} else if (argc == 3){
		std_flag = 1;
		if(arg.compare(argv[1]) != 0){
			fprintf(stderr,"Zadany zly format argumentov.\n");
			return EXIT_FAILURE;
		}
		last_lines = strtol(argv[2], NULL, 10);
	} else if (argc == 4){
		if(arg.compare(argv[1]) != 0){
			fprintf(stderr,"Zadany zly format argumentov.\n");
			return EXIT_FAILURE;
		}
		last_lines = strtol(argv[2], NULL, 10);
	}
	if(last_lines <= 0){
		fprintf(stderr,"Pocet riadkov na vypisanie musi byt vacsi ako 0.\n");
		return EXIT_FAILURE;
	}


	queue <string> lines;
	int count = 0;

	if(!std_flag){
		ifstream file (argv[position], ios::in);
		if (file.is_open()) {
	    	while ( getline (file,line) ){
	    		lines.push(line);
	    		count++;
	    		if(count > last_lines){
	    			lines.pop();
	    		}
			}
		} else {
			fprintf(stderr, "Nepodarilo sa otvorit subor.\n");
			return EXIT_FAILURE;
		}
		file.close();
	} else {
		while ( getline (cin,line) ){
	    	lines.push(line);
	    	count++;
	    	if(count > last_lines){
	    		lines.pop();
	    	}
		}
	}

	if(count < last_lines) last_lines = count;

	for(int i = 0; i < last_lines; i++){
		cout << lines.front() << "\n";
		lines.pop();
	}

	return 0;
}