#ifndef MALLOC_H
#define MALLOC_H

#include "struct.h"

void make_malloc_str(char **search_queries, char **files, char **file_name,
                     char **string, char **final_print_string,
                     struct param *param);
void free_malloc_str(char **search_queries, char **files, char **file_name,
                     char **string, char **final_print_string,
                     const struct param *param);
void malloc_is_ok(int c_count, int *len_str, char **str,
                  struct param *param);

#endif