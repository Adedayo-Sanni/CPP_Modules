#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int is_printable(char c);
void read_header(FILE* file);
void read_map(FILE* file);
void free_map(void);
void read_stdin();
void find_bsq();
void print_map(int maxsize, int maxlinha, int maxcoluna);
void bsq_file(FILE *file);
void bsq_stdin();
