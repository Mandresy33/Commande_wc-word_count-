#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000
int  cont_line(FILE* file, char* argv,char* chaine)
{
	int line_number = 0;
	file = fopen(argv, "r"); 
	if(file == NULL)
	{
		perror("fopen"); 
		exit(EXIT_FAILURE);
	}
	else
	{
		while(fgets(chaine, MAX_SIZE, file) != NULL)
		{
			line_number++;
		}
		fclose(file);
	}
	return line_number;
}
int cont_char(FILE* file, char* argv, int act_char)
{
	int cont=0;
	file = fopen(argv, "r");
	rewind(file);
	if(file == NULL)
	{
		perror("fopen"); 
		exit(EXIT_FAILURE);
	}
	else
	{
		while((act_char = fgetc(file)) != EOF)
		{
			cont++;
		}
		fclose(file);
	}
	return cont; 
}

int cont_word(FILE* file, char* argv, char *chaine)
{
	int i = 0;
	file = fopen(argv, "r");
	if(file == NULL)
	{
		perror("fopen"); 
		exit(EXIT_FAILURE);
	}
	else
	{
		while(feof(file) != 1)
		{
			fscanf(file, "%s", chaine);
			i++;
		}
		i--;
		fclose(file);
	}
	return i;
}
//Prise en compte des options de la commande wc
void option_wc(char** argv,FILE* file,char* chaine, int *line_number, int *word_number, int *char_number, int argc)
{
	*line_number = 0;
	*word_number = 0;
	*char_number = 0;
	int a = 0;
	if(argc<2)
	{
		printf("Usage: %s <option> <fichier>", argv[0]);
		exit(EXIT_FAILURE);
	}
	//Si l'option est -l
	if(strcmp(argv[1],"-l") == 0)
	{
		//Prise en compte des doubles options
		if(strcmp(argv[2],"-l") == 0)
		{
			*line_number = cont_line(file,argv[3] , chaine);
			printf("%d %s\n", *line_number, argv[3]);
		}
		else if(strcmp(argv[2],"-w") == 0)
		{
			*line_number = cont_line(file,argv[3] , chaine);
			*word_number = cont_word(file,argv[3],chaine);
			printf("%d %d %s\n",*line_number, *word_number, argv[3]);
		}
		else if(strcmp(argv[2], "-m") == 0)
		{
			*line_number = cont_line(file,argv[3] , chaine);
			*char_number = cont_char(file, argv[3], a);
			printf("%d %d %s\n",*line_number, *char_number, argv[3]);
		}
		else
		{
			*line_number = cont_line(file,argv[2] , chaine);
			printf("%d %s\n", *line_number, argv[2]);
		}
	}
	//Si l'option est -w
	else if(strcmp(argv[1],"-w") == 0)
	{
		//Prise en compte des doubles options
		if(strcmp(argv[2],"-l") == 0)
		{
			*line_number = cont_line(file,argv[3] , chaine);
			*word_number = cont_word(file,argv[3],chaine);
			printf("%d %d %s\n", *line_number,*word_number, argv[3]);
		}
		else if(strcmp(argv[2],"-w") == 0)
		{
			*word_number = cont_word(file,argv[3],chaine);
			printf("%d %s\n",*word_number, argv[3]);
		}
		else if(strcmp(argv[2], "-m") == 0)
		{
			*word_number = cont_word(file,argv[3],chaine);
			*char_number = cont_char(file, argv[3], a);
			printf("%d %d %s\n",*word_number, *char_number, argv[3]);
		}
		else
		{
			*word_number = cont_word(file,argv[2],chaine);
			printf("%d %s\n", *word_number, argv[2]);
		}
	}
	//Si l'option est -m ou -c
	else if(strcmp(argv[1], "-m") == 0 || strcmp(argv[1],"-c" ) == 0)
	{
		//Prise en compte des doubles options
		if(strcmp(argv[2],"-l") == 0)
		{
			*line_number = cont_line(file,argv[3] , chaine);
			*char_number = cont_char(file,argv[3],a);
			printf("%d %d %s\n", *line_number,*char_number, argv[3]);
		}
		else if(strcmp(argv[2],"-w") == 0)
		{
			*char_number = cont_char(file,argv[3],a);
			*word_number = cont_word(file,argv[3],chaine);
			printf("%d %d %s\n",*word_number,*char_number, argv[3]);
		}
		else if(strcmp(argv[2], "-m") == 0)
		{
			*char_number = cont_char(file, argv[3], a);
			printf("%d %s\n",*char_number, argv[3]);
		}
		else
		{
			*char_number = cont_char(file, argv[2], a);
			printf("%d %s\n", *char_number, argv[2]);
		}
	}
	// Si l'option est --total
	else if (strcmp(argv[1], "--total") == 0)
	{
		if(strcmp(argv[2], "auto") == 0)
		{
			*line_number = cont_line(file, argv[3], chaine);
			*word_number = cont_word(file, argv[3], chaine);
			*char_number = cont_char(file, argv[3], a);
			printf("%d %d %d %s\n", *line_number, *word_number, *char_number, argv[3]);
		}
		else if(strcmp(argv[2] ,"always") == 0)
		{
			*line_number = cont_line(file,argv[3] ,chaine);
			*word_number = cont_word(file, argv[3], chaine);
			*char_number = cont_char(file,argv[3] ,a );
			printf("%d %d %d %s\n", *line_number, *word_number, *char_number, argv[3]);
			printf("\n%d %d %d %s\n", *line_number, *word_number, *char_number, argv[3]);
		}
		else if(strcmp(argv[2], "only") == 0)
		{
			*line_number = cont_line(file,argv[3] ,chaine);
			*word_number = cont_word(file, argv[3], chaine);
			*char_number = cont_char(file,argv[3] ,a );
			printf("%d %d %d\n", *line_number, *word_number, *char_number);
		}
		else if(strcmp(argv[2], "never") == 0)
		{
			*line_number = cont_line(file,argv[3] ,chaine);
			*word_number = cont_word(file, argv[3], chaine);
			*char_number = cont_char(file,argv[3] ,a );
			printf("%d %d %d %s\n", *line_number, *word_number, *char_number, argv[3]);
		}
		else
		{
			printf("%s: invalid argument '%s' for --total\nValid argument are: \n", argv[0], argv[2]);
			printf("- 'auto'\n- 'always'\n- 'only'\n- 'never'\n");
			exit(EXIT_FAILURE);
		}
	}
	//Option -L
	else if(strcmp(argv[1], "-L") == 0)
	{
		int act_char;
		int max = 0;
		int count = 0;
		file = fopen(argv[2], "r");
		if(file == NULL)
		{
			perror("fopen"); 
			exit(EXIT_FAILURE);
		}
		else
		{
			while((act_char = fgetc(file)) != EOF)
			{
				count++;
				if(act_char == '\n')
				{
					count--;
					if(count>max)
					{
						max = count;
					}
					count = 0;
				}
			}
			fclose(file);
		}
		printf("%d %s\n", max, argv[2]);
		
	}
	//Si on veut afficher l'aide du commande
	else if(strcmp(argv[1], "--help") == 0)
	{
		//Ouverture du fichier help
		file = fopen("help", "r");
		if(file == NULL)
		{
			printf("Placer le fihier help dans le repertoire actuel\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			while(fgets(chaine, sizeof(chaine), file))
			{
				printf("%s", chaine);
			}
			fclose (file);
		}
		
	}
	//Si on veut afficher la version du commande
	else if(strcmp(argv[1], "--version") == 0)
	{
		//Ouverture du fichier version
		file = fopen("version", "r");
		if(file == NULL)
		{
			printf("Placer le fihier version dans le repertoire actuel\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			while(fgets(chaine, sizeof(chaine), file))
			{
				printf("%s", chaine);
			}
			fclose (file);
		}
	}
	//Si il n'y a pas d'option 
	else
	{
		*line_number = cont_line(file, argv[1], chaine);
		*word_number = cont_word(file, argv[1], chaine);
		*char_number = cont_char(file, argv[1], a);
		printf("%d %d %d %s\n", *line_number, *word_number, *char_number, argv[1]);
	}
}
