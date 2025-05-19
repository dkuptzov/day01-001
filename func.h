#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>

void work_with_argv(const char *argv, short *args);
void work_with_files(FILE *file, const short *args, int *str_count);
void cat(int *ptr_first_c, int **str_count, int c, char prev_c, short *args);
void cat_print_1(int **ptr_first_c, int **str_count);
void cat_args_b(int *first_b, int *str_count, int c, char prev_c);
int cat_args_evt(int *c, const short *args);
void cat_args_E(int c);
void cat_args_n(int *first_n, int *str_count, char prev_c);
int cat_args_s(int *first_s, int c, char prev_c);
int cat_args_T(int c);
int cat_ascii(int c);

#endif