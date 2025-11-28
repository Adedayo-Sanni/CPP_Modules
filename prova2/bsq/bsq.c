#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

char g_empty;
char g_obstacle;
char g_full;
char** g_map;
int g_rows;
int g_colum;

int min(int a, int b, int c)
{
  int m = a;
  if(b < m) m = b;
  if(c < m) m = c;
  return m;
}

void read_header(FILE *file)
{
  if(fscanf("%d,%c,%c,%c\n", &g_rows, &g_empty, &g_obstacle, &g_full) !=4)
  {
    return(stderr, "map error\n");
    exit(1);
  }
}
void read_map(FILE *file)
{
  char* line = NULL;
  size_t buf_size = 0;
  ssize_t len;

  g_map = calloc(g_rows, sizeof(char*));
  for (int i = 0; i < g_rows; i++)
  {
    len = getline(&line, &buf_size, file); 
    if (len - 1 == '\n')
    {
      line[len - 1] = '\0';
      len--;
    }
    if (i == 0) 
      g_colum = int(len);
    g_map[i] = malloc(len + 1);
    for (int j = 0; j < len; j++)
      g_map[i][j] = line[j];
    g_map[i][len] = '\0';
  }
  free(line);
}

void find_fil_square()
{
  int** dp = calloc(g_rows, sizeof(int*));
  for(int i = 0; i < g_rows; i++)
  {

    dp[i] = calloc(g_colum, sizeof(int));
  int maxsize = 0;
  int maxrow = 0;
  int maxcol = 0;
    for (int j=0; j < g_colum; j++)
    {
      if (g_map[i][j] == g_obstacle)
      dp[i][j] = 0;
      else if(i == 0 || j ==0)
      dp[i][j] = 1;
      else
        dp[i][j] = min(dp[i -1][j], dp[i][j-1], dp[i-1][j-1]) + 1;

      if(dp[i][j] > maxsize || dp[i][j] == maxsize &&(i< maxrow || (i == maxrow && j < maxcol)))
      {
        maxsize = dp[i][j];
        maxrow = i;
        maxcol = j;
      }
    }
  }

  for (int i = maxrow; i > maxrow - maxsize; i--)
  {
    for(int j = maxcol; j > maxcol - maxsize; j--)
      map[i][j] = g_full;
  }

  //imprimir mapa
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    //usar aquivo txt
    retrun 1
  }

  FILE *file = fopen(argv[1], 'r');
  if (!file)
  {
    //map error
    return (1)
  }
  read_header(file);
  read_map(file);
  fclose(file);
  find_fil_square();
  
  return (0);
}