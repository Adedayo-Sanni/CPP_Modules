#include "life.h"

char** g_matriz;
char** g_temp;

int ft_strlen(char* str)
{
	int i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}
void fill_temp_with_spaces(int height, int width);
void fill_with_spaces(int height, int width)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
			g_matriz[i][j] = 32;
	}
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
			g_temp[i][j] = 32;
	}
}

void fill_temp_with_spaces(int height, int width)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
			g_temp[i][j] = 32;
	}
}

void create_matrix(int height, int width)
{
	g_matriz = calloc(height + 1, sizeof(char*));
	int i = 0;
	for(int i = 0; i < height; i++)
		g_matriz[i] = calloc( width + 1, sizeof(char));
	g_temp = calloc(height + 1, sizeof(char*));
	 i = 0;
	for(i= 0; i < height; i++)
		g_temp[i] = calloc( width + 1, sizeof(char));
	fill_with_spaces(height, width);
}

char* read_cmds()
{
	char* comands;
	long last_position = 0;
	char temp[50];
	int int_read = read(0, temp, 50);
	comands = malloc(int_read);
	while (int_read > 0)
	{
		comands = realloc(comands, ft_strlen(comands) + int_read + 1);
		int i = 0;
		while (i < int_read)
		{
			comands[last_position] = temp[i];
			last_position++;
			i++;
		}
		int_read = read(0, temp, 50);
		comands[last_position] = '\0';
	}
	if (comands[last_position - 1] == '\n')
		comands[last_position - 1] = '\0';
	return (comands);
}

void draw_matrix(char *str, int height, int width)
{
	int line = 0;
	int col = 0;
	bool draw = false;

	while(*str)
	{
		if(*str == 'w' && line != 0)
			line--;
		if(*str == 'a' && col != 0)
			col--;
		if(*str == 's' && line != height - 1)
			line++;
		if(*str == 'd' && col != width -1)
			col++;
		if(*str == 'x')
			draw = !draw;
		if (draw)
			g_matriz[line][col] = '0';
		str++;
	}
}

void print_matrix(int height, int width)
{
	for(int i = 0; i<height; i++)
	{
		for (int j = 0; j< width; j++)
		{
			putchar(g_matriz[i][j]);
		}
		putchar('\n');
	}
}

/**
 
-1,-1	|-1,0	|	-1,1
0,-1	|0,0	|	0,1
1,-1	|1,0	|1,1

*/

int count_neighbors(int height,int width, int i , int j)
{
	int neighbors = 0;
	if (i-1 >= 0 && j-1 >= 0 && g_matriz[i -1][j -1] == '0')
		neighbors++;
	if (i - 1>= 0 && g_matriz[i -1][j] == '0')
		neighbors++;
	if (i -1 >= 0 && j + 1 < width && g_matriz[i -1][j +1] == '0')
		neighbors++;
	if (j-1 >= 0 && g_matriz[i][j -1] == '0')
		neighbors++;
	if (j+1 < width && g_matriz[i][j+ 1] == '0')
		neighbors++;
	if (i+1 < height && j-1 >= 0 && g_matriz[i+1][j-1] == '0')
		neighbors++;
	if (i+1 < height && g_matriz[i+1][j] == '0')
		neighbors++;
	if (i+1 < height && j+1 < width && g_matriz[i+1][j+1] == '0')
		neighbors++;
	return (neighbors);
}

void start_game(int height,int width, int it)
{
	while(it > 0)
	{
		for(int i = 0; i < height ; i++)
		{
			for (int j = 0; j < width ; j++)
			{
				int neighbors = count_neighbors(height,width, i , j);
				if (g_matriz[i][j] == '0')
				{
					if (neighbors == 2 || neighbors == 3)
						g_temp[i][j] = '0';
					else
						g_temp[i][j] = ' ';
				}
				else
				{
					if (neighbors == 3)
						g_temp[i][j] = '0';
					else
						g_temp[i][j] = ' ';
				}
			}
		}
		char** aux = g_matriz;
		g_matriz = g_temp;
		g_temp = aux;
		it--;
	}
}



int main (int argc, char **argv){
	if (argc != 4)
		return (putchar('X'));
	struct game_init game;
	game.width = atoi(argv[1]);
	game.height = atoi(argv[2]);
	game.it = atoi(argv[3]);
	char* comands;

	create_matrix(game.height, game.width);
	comands = read_cmds();
	draw_matrix(comands, game.height, game.width);
	// dar o free no cmds aqui
	start_game(game.height, game.width, game.it);
	print_matrix(game.height, game.width);
	free_matrix()

	return 0;
}


void free_matrix()
{
	//dar free na matrix e na temp globais;
}
/*
          $
 0   000  $
 0     0  $
 000  0   $
  0  000  $
          $

      0   $
      00  $
00   0 0  $
 0 0 0    $
 000 000  $
      0   $


      00  $
 0   0 0  $
000 00 0  $
   0 0 0  $
 0 0 0 0  $
  0  000  $

      00  $
000 00 00 $
0000 0 00 $
0  0 0 00 $
   0 0 00 $
  0 00 0  $

 0   0000 $
0   00    $
     0   0$
0  0 0   0$
 000 0    $
   000 00 $


    0000 $
 0 000    $
00 0 0   0$
 0 0 0   0$
  00 0    $
   000 00 $

      00  $
 0  00 00 $
 000 0 00 $
0  0 0 00 $
   0 0 00 $
  0 00 0  $

      00  $
     0 0  $
000 00 0  $
   0 0 0  $
 0 0 0 0  $
  0  000  $

      0   $
      00  $
00   0 0  $
 0 0 0    $
 000 000  $
      0   $

          $
 0   000  $
 0     0  $
 000  0   $
  0  000  $
          $

*/
