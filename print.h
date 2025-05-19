#ifndef PRINT_H
#define PRINT_H

#include "struct.h"

void print_res(int value, const short *args, const char *file_name,
               const char *str, int count_files, int *string_count,
               const struct param *param);
void final_print(int value, char *final_print_string, const short *args,
                 const char *file_name, int count_files, int *string_count,
                 int *len_final_print, struct param *param);
void printf_error(const struct param *param);
void print_reg_o(const short *args, int count_files, int **string_count,
                 const char *print_this, const char *file_name);
void print_no_file(const short *args, char *final_print_str,
                   const char *file_name, const int *len_final_print);

#endif