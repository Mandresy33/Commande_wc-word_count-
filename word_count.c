#include "wc.h"
#include <stdio.h>
int main(int argc, char* argv[])
{
	FILE* file; 
	int line_number;
	int char_number;
	int word_number;
	char chaine[1000];
	option_wc(argv,file ,chaine, &line_number, &word_number, &char_number, argc);
	return 0;
}
