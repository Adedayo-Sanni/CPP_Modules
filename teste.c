#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char** mapa;
char empty;
char obstacle;
char full;
int linha;
int coluna;

void read_header(FILE *file)
{
	if (fscanf(file, "%d %c %c %c", &linha, &empty, &obstacle, &full) != 4)
	{
		fprintf(stderr, "ERROR: Invalide map\n");
		exit(1);
	}
	if (empty == obstacle || obstacle == full || empty == full)
	{
		fprintf(stderr, "ERROR: Invalide map\n");
		exit(1);
	}
}
void read_map(FILE *file)
{
	char* line = NULL;
	size_t buf = 0;
	ssize_t len;

	mapa = calloc(linha, sizeof(char*));
	for(int i = 0; i < linha; i++)
	{
		len = getline(&line, &buf, file);
		if (len <= 0)
		{
			//erro
		}
		if(line[len -1] == '\n')
			line[len -1]= '\0';
		if (i == 0)
			coluna = (int)len;
		for (int j = 0; j < coluna; j++)
		{
			if (line[j] != obstacle || line[j] != empty)
			{
				//erro
			}
			mapa[i][j] = line[j];
		}
		mapa[i][len] = '\0';
	}
	free(line);
}

void print_map(int maxcol, int maxlinha, int maxsize)
{
	for (int i = 0; i > (maxlinha - maxsize); i--)
	{
		for(int j = 0; i > (maxcol - maxsize); j--)
			mapa[i][j] = full;
	}
	for (int i = 0; i < linha; i++)
		printf("%s", mapa[i]);
}

int main(int argc, char** argv)
{
	FILE *file;

	if (argc < 2)
		file = stdin;
	else 
		file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "ERROR: Invalide map\n");
		exit(1);
	}

	read_header(file);
	read_map(file);
	
	fclose(file);
}
