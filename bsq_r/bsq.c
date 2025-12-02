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
int ft_strlen(char* str)
{
	int i =0;
	while(str[i] != '\0')
		i++;
	return(i);
}
int min3(int a, int b, int c)
{
	int m = a;
	if (b < m) m = b;
	if (c < m) m = c;

	return (m);
}

void read_header(FILE* file)
{
		fscanf(file, "%d %c %c %c\n", &linha, &empty, &obstacle, &full);
	if (!is_printable(empty)||!is_printable(obstacle)||!is_printable(full)||
    empty == obstacle || empty == full || obstacle == full)
{
    fprintf(stderr, "map error1\n");
    return;
}

}

// void read_map(FILE* file)
// {
// 	int read_char;
// 	int check;
// 	mapa = calloc(linha + 1, sizeof(char*));
// 	for (int i = 0; i < linha; i++)
// 	{
// 		size_t len = 0;
// 		check = getline(&mapa[i],&len, file);
// 		if(check == -1)
// 		{
// 			fprintf(stderr, "map error2\n");
// 			//free_map();
// 			return;
// 		}
// 		if(mapa[i][check -1] == '\n')
// 			mapa[i][check -1] = '\0';
// 	}
// 	coluna = ft_strlen(mapa[0]);
// 	for (int i = 0; i < linha; i++)
// 	{
// 			for(int j = 0;j < coluna; j++ )
// 				if (mapa[i][j] != obstacle && mapa[i][j]!= empty)
// 				{
// 					fprintf(stderr, "map error3\n");
// 					//free_map();
// 					return;
// 	;
// 				}
// 	}
// 	for (int i = 0; i < linha; i++)
// 		if (ft_strlen(mapa[i]) != coluna)
// 		{
// 			fprintf(stderr, "map error4\n");
// 			//free_map();;
// 		}
// }

void read_map(FILE* file)
{
    int check;
    mapa = calloc(linha + 1, sizeof(char*));
    for (int i = 0; i < linha; i++)
    {
        size_t len = 0;
        check = getline(&mapa[i], &len, file);
        if (check == -1)
        {
            fprintf(stderr, "map error2\n");
            return;
        }
        if (mapa[i][check -1] == '\n')
            mapa[i][check -1] = '\0';
    }
    coluna = ft_strlen(mapa[0]);

    for (int i = 0; i < linha; i++)
        for (int j = 0; j < coluna; j++)
            if (mapa[i][j] != obstacle && mapa[i][j] != empty)
            {
                fprintf(stderr, "map error3\n");
                return;
            }

    for (int i = 0; i < linha; i++)
        if (ft_strlen(mapa[i]) != coluna)
        {
            fprintf(stderr, "map error4\n");
            return;
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
	int **dp = malloc(sizeof(int*) * linha);
    for (int i = 0; i < linha; i++)
        dp[i] = calloc(coluna, sizeof(int));

    int max = 0, mr = 0, mc = 0;

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (mapa[i][j] == obstacle)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = min3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;

            if (dp[i][j] > max)
            {
                max = dp[i][j];
                mr = i;
                mc = j;
            }
        }
    }

    print_map(max, mr, mc);

    for (int i = 0; i < linha; i++)
        free(dp[i]);
    free(dp);
}

void print_map(int maxsize, int maxlinha, int maxcoluna)
{
	/* Preenche o bsq */
	for (int i = maxlinha - (maxsize -1); i < maxlinha + 1; i++)
	{
		for (int j = maxcoluna - (maxsize -1); j < maxcoluna + 1; j++)
		{
			if (i >= 0 && i < linha && j >= 0 && j < coluna)
				mapa[i][j] = full;
		}
	}
	/* imprime o mapa inteiro */
	for (int i = 0; i < linha; i++)
		fprintf(stdout, "%s\n", mapa[i]);
}


void bsq_file(char* filename)
{
	FILE* file = fopen(filename, "r");
	if(!file)
	{
		fprintf(stderr, "map error5\n");
		exit (1);
	}
	read_header(file);
	read_map(file);
	find_bsq();
	//free_map();
	fclose(file);
}

void bsq_stdin()
{
	read_header(stdin);
	read_map(stdin);
	find_bsq();
	//free_map();
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
