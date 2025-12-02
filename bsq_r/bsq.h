#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int is_printable(char c);
int ft_strlen(char* str);
void read_header(FILE* file);
void read_map(FILE* file);
void free_map(void);
void find_bsq();
void print_map(int maxsize, int maxlinha, int maxcoluna);
void bsq_file();
void bsq_stdin();
