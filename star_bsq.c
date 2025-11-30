#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/* ************************************************************************** */
/*                               Variáveis globais                             */
/* ************************************************************************** */

char **g_map;
int   g_rows;
int   g_cols;
char  g_empty;
char  g_obstacle;
char  g_full;

/* ************************************************************************** */
/*                                  Utilidades                                 */
/* ************************************************************************** */

void print_error()
{
    write(2, "map error\n", 10);
}

int min3(int a, int b, int c)
{
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

/* ************************************************************************** */
/*                          Alocação e liberação                                */
/* ************************************************************************** */

char **alloc_map(int rows, int cols)
{
    char **m = malloc(sizeof(char*) * rows);
    if (!m)
        return 0;

    for (int i = 0; i < rows; i++)
    {
        m[i] = malloc(cols + 1);
        if (!m[i])
            return 0;
        m[i][cols] = '\0';
    }
    return m;
}

void free_map()
{
    for (int i = 0; i < g_rows; i++)
        free(g_map[i]);
    free(g_map);
}

/* ************************************************************************** */
/*                              Leitura de arquivo                              */
/* ************************************************************************** */

int read_file(char *path, char **buffer)
{
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return 0;

    char *buf = malloc(2000000);
    int r = read(fd, buf, 2000000);
    close(fd);

    if (r <= 0)
    {
        free(buf);
        return 0;
    }

    buf[r] = '\0';
    *buffer = buf;
    return r;
}

int read_stdin(char **buffer)
{
    char *buf = malloc(2000000);
    int r = read(0, buf, 2000000);

    if (r <= 0)
    {
        free(buf);
        return 0;
    }
    buf[r] = '\0';
    *buffer = buf;
    return r;
}

/* ************************************************************************** */
/*                               Parsing                                         */
/* ************************************************************************** */

int parse_header(char *buf)
{
    int i = 0;
    int num = 0;

    while (buf[i] >= '0' && buf[i] <= '9')
    {
        num = num * 10 + (buf[i] - '0');
        i++;
    }

    if (num <= 0)
        return -1;

    g_rows = num;
    g_empty = buf[i++];
    g_obstacle = buf[i++];
    g_full = buf[i++];

    if (buf[i] != '\n')
        return -1;

    return i + 1; // próxima posição após header
}

int parse_map(char *buf, int start)
{
    int i = start;
    int r = 0;

    while (r < g_rows)
    {
        for (int c = 0; c < g_cols; c++)
        {
            if (buf[i] != g_empty && buf[i] != g_obstacle)
                return -1;
            g_map[r][c] = buf[i];
            i++;
        }
        if (buf[i] != '\n')
            return -1;
        i++;
        r++;
    }
    return i;
}

/* ************************************************************************** */
/*                               Algoritmo BSQ                                  */
/* ************************************************************************** */

void solve_bsq()
{
    int **dp = malloc(sizeof(int*) * g_rows);
    for (int i = 0; i < g_rows; i++)
        dp[i] = calloc(g_cols, sizeof(int));

    int max = 0, mr = 0, mc = 0;

    for (int i = 0; i < g_rows; i++)
    {
        for (int j = 0; j < g_cols; j++)
        {
            if (g_map[i][j] == g_obstacle)
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

    for (int i = mr; i > mr - max; i--)
        for (int j = mc; j > mc - max; j--)
            g_map[i][j] = g_full;

    for (int i = 0; i < g_rows; i++)
    {
        write(1, g_map[i], g_cols);
        write(1, "\n", 1);
    }

    for (int i = 0; i < g_rows; i++)
        free(dp[i]);
    free(dp);
}

/* ************************************************************************** */
/*                                    MAIN                                      */
/* ************************************************************************** */

int process_buffer(char *buffer)
{
    int start = parse_header(buffer);
    if (start < 0)
        return print_error(), 0;

    g_cols = 0;
    while (buffer[start + g_cols] != '\n')
        g_cols++;

    g_map = alloc_map(g_rows, g_cols);

    if (parse_map(buffer, start) < 0)
    {
        print_error();
        free_map();
        return 0;
    }

    solve_bsq();
    free_map();
    return 1;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        char *buffer;
        if (!read_stdin(&buffer))
            return print_error(), 0;

        process_buffer(buffer);
        free(buffer);
        return 0;
    }

    int printed = 0;

    for (int i = 1; i < argc; i++)
    {
        char *buffer;
        if (!read_file(argv[i], &buffer))
        {
            print_error();
            continue;
        }

        if (printed)
            write(1, "\n", 1);
        printed = 1;

        process_buffer(buffer);
        free(buffer);
    }

    return 0;
}
