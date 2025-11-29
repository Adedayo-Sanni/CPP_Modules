#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


char g_empty;
char g_obstacle;
char g_full;
char **g_map;
int g_rows;
int g_colum;

int min3(int a, int b, int c)
{
	int m = a;
	if (b < m) m = b;
	if (c < m) m = c;
	return m;
}

void read_header(FILE *file)
{
	if (fscanf(file, "%d %c %c %c\n", &g_rows, &g_empty, &g_obstacle, &g_full) != 4)
	{
		fprintf(stderr, "map error\n");
		exit(1);
	}
	if (g_empty == g_obstacle || g_empty == g_full || g_obstacle == g_full)
	{
		fprintf(stderr, "map error\n");
		exit(1);
	}
}

void read_map(FILE *file)
{
	char *line = NULL;
	size_t buf_size = 0;
	ssize_t len;

	g_map = calloc(g_rows, sizeof(char*));

	for (int i = 0; i < g_rows; i++)
	{
		len = getline(&line, &buf_size, file);
		if (len <= 0)
		{
			fprintf(stderr, "map error\n");
			exit(1);
		}

		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
			len--;
		}
		if (i == 0)
			g_colum = (int)len;
		else if (len != g_colum)
		{
			fprintf(stderr, "map error\n");
			exit(1);
		}
		g_map[i] = malloc(len + 1);

		for (int j = 0; j < len; j++)
		{
			if (line[j] != g_empty && line[j] != g_obstacle)
			{
				fprintf(stderr, "map error\n");
				exit(1);
			}
			g_map[i][j] = line[j];
		}
		g_map[i][len] = '\0';
	}

	free(line);
}

void print_map(int maxrow, int maxsize, int maxcol);

void find_fill_square()
{
	int maxsize = 0;
	int maxrow = 0;
	int maxcol = 0;

	//aloca matriz dp;
	int **dp = calloc(g_rows, sizeof(int*));
	for (int i = 0; i < g_rows; i++)
		dp[i] = calloc(g_colum, sizeof(int));
	for (int i = 0; i < g_rows; i++)
	{
		for (int j = 0; j < g_colum; j++)
		{
			if (g_map[i][j] == g_obstacle)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;

			if (dp[i][j] > maxsize ||
				(dp[i][j] == maxsize && (i < maxrow || (i == maxrow && j < maxcol))))
			{
				maxsize = dp[i][j];
				maxrow = i;
				maxcol = j;
			}
		}
	}
	print_map(maxrow, maxsize, maxcol);
}

void print_map(int maxrow, int maxsize, int maxcol)
{
	for (int i = maxrow; i > maxrow - maxsize; i--)
		for (int j = maxcol; j > maxcol - maxsize; j--)
			g_map[i][j] = g_full;

	for (int i = 0; i < g_rows; i++)
		printf("%s\n", g_map[i]);
}

int main(int argc, char **argv)
{
	FILE *file;

	if (argc < 2)
		file = stdin;
	else
		file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "map error\n");
		return 1;
	}

	read_header(file);
	read_map(file);
	fclose(file);

	find_fill_square();

	return 0;
}
