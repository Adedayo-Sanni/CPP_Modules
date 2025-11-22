#include <stdio.h>
#include <stdlib.h>

/*
    Assumindo que você implementará esta função:

    void simulate_life(int width, int height, int iterations, char **board);

    - board: matriz alocada dinamicamente contendo '0' (vivo) e ' ' (morto)
    - iterations: número de iterações do Game of Life
*/
void simulate_life(int width, int height, int iterations, char **board);

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Uso: %s width height iterations\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    int iterations = atoi(argv[3]);

    if (width <= 0 || height <= 0 || iterations < 0)
    {
        fprintf(stderr, "Parâmetros inválidos.\n");
        return 1;
    }

    // Aloca o tabuleiro (inicialmente tudo morto)
    char **board = (char **)malloc(sizeof(char *) * height);
    if (!board)
        return 1;

    for (int i = 0; i < height; i++)
    {
        board[i] = (char *)calloc(width, sizeof(char));
        if (!board[i])
            return 1;

        // Inicializa com espaço (célula morta)
        for (int j = 0; j < width; j++)
            board[i][j] = ' ';
    }

    // Interpreta comandos do stdin (movimento e desenho)
    int x = 0, y = 0;
    int drawing = 0;
    int c;

    while ((c = read(0, &c, 1)) > 0) { }

    /* 
       NOTE: Acima você irá substituir pelo seu parser de comandos,
       usando read ou getchar, aplicando:
       - w/a/s/d para mover
       - x para togglar desenho
       - Não sair dos limites do tabuleiro
       - Se drawing==1, marcar board[y][x] = '0'
    */

    // Após acabar a leitura do input, simula:
    simulate_life(width, height, iterations, board);

    // Imprime resultado final
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            putchar(board[i][j]);
        putchar('\n');
    }

    // Libera memória
    for (int i = 0; i < height; i++)
        free(board[i]);
    free(board);

    return 0;
}
