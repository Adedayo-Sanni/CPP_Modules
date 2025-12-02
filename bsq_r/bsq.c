#include "bsq.h"

char** mapa;
char empty;
char obstacle;
char full;
int linha;
int coluna;
int g_error = 0; // 0 = ok, 1 = houve erro em alguma etapa

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
//original
// void read_header(FILE* file)
// {
// 		fscanf(file, "%d %c %c %c\n", &linha, &empty, &obstacle, &full);
// 	if (!is_printable(empty)||!is_printable(obstacle)||!is_printable(full)||
//     empty == obstacle || empty == full || obstacle == full)
// {
//     fprintf(stderr, "map error1\n");
//     return;
// }

// }


void read_header(FILE* file)
{
    g_error = 0; // sempre zeramos o erro antes de ler um novo header

    // Se não ler exatamente 4 itens, o header já está errado
    if (fscanf(file, "%d %c %c %c\n", &linha, &empty, &obstacle, &full) != 4)
    {
        fprintf(stderr, "map error1\n");
        g_error = 1;
        return;
    }

    // valida caracteres
    if (!is_printable(empty) || !is_printable(obstacle) || !is_printable(full) ||
        empty == obstacle || empty == full || obstacle == full || linha <= 0)
    {
        fprintf(stderr, "map error1\n");
        g_error = 1;
        return;
    }
}
//
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



//original
// void read_map(FILE* file)
// {
//     int check;
//     mapa = calloc(linha + 1, sizeof(char*));
//     for (int i = 0; i < linha; i++)
//     {
//         size_t len = 0;
//         check = getline(&mapa[i], &len, file);
//         if (check == -1)
//         {
//             fprintf(stderr, "map error2\n");
//             return;
//         }
//         if (mapa[i][check -1] == '\n')
//             mapa[i][check -1] = '\0';
//     }
//     coluna = ft_strlen(mapa[0]);

//     for (int i = 0; i < linha; i++)
//         for (int j = 0; j < coluna; j++)
//             if (mapa[i][j] != obstacle && mapa[i][j] != empty)
//             {
//                 fprintf(stderr, "map error3\n");
//                 return;
//             }

//     for (int i = 0; i < linha; i++)
//         if (ft_strlen(mapa[i]) != coluna)
//         {
//             fprintf(stderr, "map error4\n");
//             return;
//         }
// }

void read_map(FILE* file)
{
    int check;

    if (g_error) // se o header já falhou, nem tenta ler mapa
        return;

    mapa = calloc(linha + 1, sizeof(char*));
    if (!mapa)
    {
        fprintf(stderr, "map error2\n");
        g_error = 1;
        return;
    }

    for (int i = 0; i < linha; i++)
    {
        size_t len = 0;
        mapa[i] = NULL; // importante: getline vai alocar

        check = getline(&mapa[i], &len, file);
        if (check == -1)
        {
            fprintf(stderr, "map error2\n");
            g_error = 1;
            return;
        }
        if (check > 0 && mapa[i][check - 1] == '\n')
            mapa[i][check - 1] = '\0';
    }

    // se a primeira linha for vazia ou NULL, já é erro de formato
    if (!mapa[0] || mapa[0][0] == '\0')
    {
        fprintf(stderr, "map error4\n");
        g_error = 1;
        return;
    }

    coluna = ft_strlen(mapa[0]);

    // 1º: garante que TODAS as linhas têm o MESMO tamanho
    for (int i = 0; i < linha; i++)
    {
        if (ft_strlen(mapa[i]) != coluna)
        {
            fprintf(stderr, "map error4\n");
            g_error = 1;
            return;
        }
    }

    // 2º: valida caracteres (só empty ou obstacle)
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (mapa[i][j] != obstacle && mapa[i][j] != empty)
            {
                fprintf(stderr, "map error3\n");
                g_error = 1;
                return;
            }
        }
    }
}
//original
// void free_map(void)
// {
// 	for (int i = 0; i < linha; i++)
// 		free(mapa[i]);
// 	free(mapa);
// }

void free_map(void)
{
    if (!mapa) // se nunca alocou, não faz nada
        return;

    for (int i = 0; i < linha; i++)
        free(mapa[i]);
    free(mapa);
    mapa = NULL;
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

//original
// void bsq_file(char* filename)
// {
// 	FILE* file = fopen(filename, "r");
// 	if(!file)
// 	{
// 		fprintf(stderr, "map error5\n");
// 		exit (1);
// 	}
// 	read_header(file);
// 	read_map(file);
// 	find_bsq();
// 	//free_map();
// 	fclose(file);
// }

void bsq_file(char* filename)
{
    FILE* file = fopen(filename, "r");
    if(!file)
    {
        fprintf(stderr, "map error5\n");
        return; // não precisa dar exit, só não processa esse arquivo
    }

    mapa = NULL; // garante estado conhecido

    read_header(file);
    read_map(file);

    if (!g_error)
        find_bsq();   // só roda o algoritmo se tudo deu certo

    free_map();
    fclose(file);
}
//original
// void bsq_stdin()
// {
// 	read_header(stdin);
// 	read_map(stdin);
// 	find_bsq();
// 	//free_map();
// }

void bsq_stdin()
{
    mapa = NULL;
    read_header(stdin);
    read_map(stdin);

    if (!g_error)
        find_bsq();

    free_map();
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
