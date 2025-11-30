#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/* ************************************************************************** */
/*                            Funções utilitárias                              */
/* ************************************************************************** */

void print_error()
{
    write(2, "map error\n", 10);
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int min3(int a, int b, int c)
{
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

/* ************************************************************************** */
/*                          Alocação e liberação                               */
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

void free_map(char **map, int rows)
{
    for (int i = 0; i < rows; i++)
        free(map[i]);
    free(map);
}

/* ************************************************************************** */
/*                             Leitura de arquivo                              */
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
/*                               Parsing do mapa                               */
/* ************************************************************************** */

int parse_header(char *buf, int *rows, char *empty, char *obst, char *full)
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

    *rows = num;
    *empty = buf[i++];
    *obst  = buf[i++];
    *full  = buf[i++];

    if (buf[i] != '\n')
        return -1;

    return i + 1; // retorna posição após header
}

int parse_map(char *buf, int start, char **map,
              int rows, int cols, char empty, char obst)
{
    int i = start;
    int r = 0;

    while (r < rows)
    {
        for (int c = 0; c < cols; c++)
        {
            if (buf[i] != empty && buf[i] != obst)
                return -1;

            map[r][c] = buf[i];
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
/*                               Algoritmo BSQ                                 */
/* ************************************************************************** */

void solve_bsq(char **map, int rows, int cols,
               char full, char obst)
{
    int **dp = malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++)
        dp[i] = calloc(cols, sizeof(int));

    int max = 0, mr = 0, mc = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] == obst)
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
            map[i][j] = full;

    for (int i = 0; i < rows; i++)
    {
        write(1, map[i], cols);
        write(1, "\n", 1);
    }

    for (int i = 0; i < rows; i++)
        free(dp[i]);
    free(dp);
}

/* ************************************************************************** */
/*                                    MAIN                                    */
/* ************************************************************************** */

int main(int argc, char **argv)
{
    int arg = 1;
    int printed = 0;

    if (argc == 1) // STDIN
    {
        char *buffer;
        if (!read_stdin(&buffer))
            return print_error(), 0;

        int rows, cols;
        char e, o, f;

        int start = parse_header(buffer, &rows, &e, &o, &f);
        if (start < 0)
            return print_error(), free(buffer), 0;

        cols = 0;
        while (buffer[start + cols] != '\n')
            cols++;

        char **map = alloc_map(rows, cols);

        if (parse_map(buffer, start, map, rows, cols, e, o) < 0)
        {
            print_error();
            free_map(map, rows);
            free(buffer);
            return 0;
        }

        solve_bsq(map, rows, cols, f, o);

        free_map(map, rows);
        free(buffer);
        return 0;
    }

    while (arg < argc)
    {
        char *buffer;
        if (!read_file(argv[arg], &buffer))
        {
            print_error();
            arg++;
            continue;
        }

        int rows, cols;
        char e, o, f;

        int start = parse_header(buffer, &rows, &e, &o, &f);
        if (start < 0)
        {
            print_error();
            free(buffer);
            arg++;
            continue;
        }

        cols = 0;
        while (buffer[start + cols] != '\n')
            cols++;

        char **map = alloc_map(rows, cols);

        if (parse_map(buffer, start, map, rows, cols, e, o) < 0)
        {
            print_error();
            free_map(map, rows);
            free(buffer);
            arg++;
            continue;
        }

        if (printed)
            write(1, "\n", 1);
        printed = 1;

        solve_bsq(map, rows, cols, f, o);

        free_map(map, rows);
        free(buffer);
        arg++;
    }

    return 0;
}
