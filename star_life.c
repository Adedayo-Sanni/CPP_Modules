#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

char **g_matriz;
char **g_temp;

void fill_spaces(int linha, int coluna)
{
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
			g_matriz[i][j] = ' ';
		g_matriz[i][coluna] = '\0';
	}

	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
			g_temp[i][j] = ' ';
		g_temp[i][coluna] = '\0';
	}
}

void create_matrix(int linha, int coluna)
{
	g_matriz = calloc(linha, sizeof(char *));
	for (int i = 0; i < linha; i++)
		g_matriz[i] = calloc(coluna + 1, sizeof(char));

	g_temp   = calloc(linha, sizeof(char *));
	for (int i = 0; i < linha; i++)
		g_temp[i] = calloc(coluna + 1, sizeof(char));

	fill_spaces(linha, coluna);
}

// char *read_cmds()
// {
// 	char *cmds = malloc(1);
// 	cmds[0] = '\0';

// 	char buf[50];
// 	long last_pos = 0;

// 	int r = read(0, buf, 50);
// 	while (r > 0)
// 	{
// 		cmds = realloc(cmds, last_pos + r + 1);
// 		for (int i = 0; i < r; i++)
// 			cmds[last_pos++] = buf[i];
// 		cmds[last_pos] = '\0';

// 		r = read(0, buf, 50);
// 	}

// 	if (last_pos > 0 && cmds[last_pos - 1] == '\n')
// 		cmds[last_pos - 1] = '\0';

// 	return cmds;
// }

char *read_cmds()
{
	char *cmds = malloc(1);
	int size = 1;
	int len = 0;

	cmds[0] = '\0';

	char c;
	int read_char = read(0, &c, 1);

	while (read_char > 0)
	{
		if (c == '\n')
			break;
		cmds = realloc(cmds, size + 1);
		cmds[len] = c;
		len++;
		size++;

		cmds[len] = '\0';

		read_char = read(0, &c, 1);
	}

	return cmds;
}


void draw_matrix(char *s, int h, int w)
{
	int line = 0;
	int col = 0;
	int draw = false;

	while (*s)
	{
		if (*s == 'w' && line > 0)
			line--;
		else if (*s == 'a' && col > 0)
			col--;
		else if (*s == 's' && line < h - 1)
			line++;
		else if (*s == 'd' && col < w - 1)
			col++;
		else if (*s == 'x') 
		{
			draw = !draw;
			if (draw)
				g_matriz[line][col] = '0'; // desenha imediatamente
		}

		// desenha após qualquer comando se draw ativo
		if (draw)
			g_matriz[line][col] = '0';

		s++;
	}
}


void print_matrix(int linha, int coluna)
{
	for (int i = 0; i < linha; i++)
	{
		for (int j = 0; j < coluna; j++)
			putchar(g_matriz[i][j]);
		putchar('\n');
	}
}

int count_neighbors(int linha, int coluna, int i, int j)
{
	int vizinho = 0;

	if (i - 1 >= 0 && g_matriz[i - 1][j] == '0')
		vizinho++;
	if (i + 1 < linha && g_matriz[i + 1][j] == '0')
		vizinho++;
	if (j - 1 >= 0 && g_matriz[i][j - 1] == '0')
		vizinho++;
	if (j + 1 < coluna && g_matriz[i][j + 1] == '0')
		vizinho++;
	if (i - 1 >= 0 && j - 1 >= 0 && g_matriz[i - 1][j - 1] == '0')
		vizinho++;
	if (i - 1 >= 0 && j + 1 < coluna && g_matriz[i - 1][j + 1] == '0')
		vizinho++;
	if (i + 1 < linha && j - 1 >= 0 && g_matriz[i + 1][j - 1] == '0')
		vizinho++;
	if (i + 1 < linha && j + 1 < coluna && g_matriz[i + 1][j + 1] == '0')
		vizinho++;

	return vizinho;
}


void start_game(int linha, int coluna, int it)
{
	while (it > 0)
	{
		for (int i = 0; i < linha; i++)
			for (int j = 0; j <coluna; j++)
				g_temp[i][j] = ' ';

		for (int i = 0; i < linha; i++)
		{
			for (int j = 0; j <coluna; j++)
			{
				int n = count_neighbors(linha,coluna, i, j);

				if (g_matriz[i][j] == '0')
				{
					if (n == 2 || n == 3)
						g_temp[i][j] = '0';
				}
				else
				{
					if (n == 3)
						g_temp[i][j] = '0';
				}
			}
		}
		char **aux = g_matriz;
		g_matriz = g_temp;
		g_temp = aux;

		it--;
	}
}

void free_matrix(int h)
{
	for (int i = 0; i < h; i++)
		free(g_matriz[i]);
	free(g_matriz);

	for (int i = 0; i < h; i++)
		free(g_temp[i]);
	free(g_temp);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return putchar('X');

	int linha = atoi(argv[2]);
	int coluna = atoi(argv[1]);
	int it = atoi(argv[3]);

	create_matrix(linha, coluna);

	char *cmds = read_cmds();
	draw_matrix(cmds, linha, coluna);
	free(cmds);

	start_game(linha, coluna, it);
	print_matrix(linha, coluna);

	free_matrix(linha);
	return 0;
}
