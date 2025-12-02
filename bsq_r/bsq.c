#include "bsq.h"

char** mapa;
char empty;
char obstacle;
char full;
int linha;
int coluna;

int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}
int min3(int a, int b, int c)
{
	int m = a;
	if (b < m) b = m;
	if (c < m) c = m;

	return (m);
}

void read_header(FILE *file)
{
		fscanf(file, "%d %c %c %c\n", &linha, &empty, &obstacle, &full);
		if (!is_printable(empty)||!is_printable(obstacle)||!is_printable(full)||
		empty == obstacle || empty == full || obstacle == full)
    {
        fprintf(stderr, "map error\n");
        exit(1);
    }
}

void read_map(FILE *file)
{
	int read_char;
	int len = 0;
	mapa = calloc(linha + 1, sizeof(char*));
	for (int i = 0; i < linha; i++)
	{
		if(getline(&mapa[i],&len, file) == -1); 
		{
			fprintf(stderr, "map error\n");
			free_map();
			exit(1);
		}
		if(mapa[i][len] == '\n')
			mapa[i][len] = '\0';
	}
	coluna = strlen(mapa[0]);
	for (int i = 0; i < linha; i++)
	{
			for(int j = 0;j < coluna; j++ )
				if (mapa[i][j] != obstacle && mapa[i][j]!= empty)
				{
					fprintf(stderr, "map error\n");
					free_map();
					exit(1);
				}
	}
	for (int i = 0; i < linha; i++)
		if (strlen(mapa[i]) != coluna)
		{
			fprintf(stderr, "map error\n");
			free_map();
			exit(1);
		}
}

void free_map(void)
{
	for (int i = 0; i < linha; i++)
		free(mapa[i]);
	free(mapa);
}

void find_bsq()
{
	int maxsize = 0;
	int maxcol = 0;
	int maxlinha = 0; 

	for(int i = 0; i < linha; i++)
	{
		for(int j = 0; j < coluna; j++)
		{
			if(mapa[i][j] == obstacle)
				mapa[i][j] = 0;
			else if(i == 0 || j == 0)
				mapa[i][j] = 1;
			else 
			{
				int min = min3(mapa[i - 1][j],mapa[i - 1][j - 1], mapa[i][j - 1]);
				mapa[i][j] = min + 1;
			}
			if(mapa[i][j] > maxsize)
			{
				maxsize = mapa[i][j];
				maxlinha = i - mapa[i][j] + 1;
				maxcol = j - mapa[i][j] + 1;
			}
		}
	}
	print_map( maxsize, maxlinha, maxcol);
}

void print_map(int maxsize, int maxlinha, int maxcoluna)
{
	for (int i = maxlinha; i > (maxlinha - maxsize)+1; i--)
	{
		for (int j = maxcoluna; j > (maxlinha - maxsize)+1; j--)
		{
			if (i < linha && j < coluna)
			mapa[i][j];
		}
	}
	for (int i = 0; i < linha; i++)
		fprintf("%s", mapa[i]);
}



void bsq_file(FILE *file)
{
	FILE* file = fopen(file, "r");
	if(!file)
	{
		fprintf(stderr, "map error\n");
		exit (1);
	}
	read_header(file);
	read_map(file);
	find_bsq();
	fclose(file);
}

void bsq_stdin()
{
	read_header(stdin);
	read_map(stdin);
	find_bsq();
}

int main(int argc, char**argv)
{
	if (argc < 2)
		bsq_stdin();
	else
	{
		int i = 1;
		while( i < argc)
		{
			bsq_file(argv[i]);
			i++;
			if (i < argc -1)
			fprintf(stdout, "\n"); // colocar o \n no final entre arquivos
		}
	} 
}