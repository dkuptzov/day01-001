#ifndef ARGS_H
#define ARGS_H

#include "struct.h"

int analize_args(int argc, const char *argv[], char **search_queries,
                 char *files, short *args, struct param *param);
void work_with_argv(const char *argv, short *args, char *files,
                    char ***search_queries, struct param *param);
void str_cat(char *str1, const char *str2, long int *max_memory,
             struct param *param);

#endif