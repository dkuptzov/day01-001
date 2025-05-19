#ifndef FILE_H
#define FILE_H

#include "struct.h"

void main_get_file_name(const char *str1, char *str2, int *count, int *i, int *len_files_name, struct param *param);
void search_query_from_file(const char *file_name, char ***str, const short *args,
                            long int *max_memory, struct param *param);

#endif