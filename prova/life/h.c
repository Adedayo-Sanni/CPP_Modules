char ** g_matriz;
char** g_temp;

void create_matrix(int linha, int coluna)
{
  g_matriz = callooc(linha + 1, sizeof(char*));
  for (int i = 0; i < linha; i++)
    g_matriz[i] = calloc(coluna+1, sizeof(char));
  g_temp = callooc(linha + 1, sizeof(char*));
  for (int j = 0; j < linha; j++)
    g_temp[j] = calloc(coluna+1, sizeof(char));
  fill_with_spaces(linha, coluna);
}

void fill_with_spaces(int linha, int coluna)
{
  for (int i = 0; i < linha; i++)
  {
    for(int j = 0; j < coluna; j++)
      g_matriz[i][j] = 32;
    g_matriz[i][coluna] = '\0';
  }
  for (int x = 0; x < linha; x++)
  {
    for(int y = 0; y < coluna; y++)
      g_temp[x][y] = 32;
    g_temp[x][coluna] = '\0';
  }
}

char* read_cmds()
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
	return(cmds);
}