#include <stdio.h>
int cont_line(FILE* file, char* argv,char* chaine);
int cont_char(FILE* file, char* argv, int act_char);
int cont_word(FILE* file, char* argvi, char *chaine );
void option_wc(char** argv,FILE* file,char* chaine, int *line_number, int *word_number, int *char_number, int argc);
