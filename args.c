#include "args.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

int analize_args(int argc, const char *argv[], char **search_queries,
                 char *files, short *args, struct param *param) {
  int count_files = 0;
  long int max_memory_find = 1024, max_memory_files = 1024;
  char prev = '+';
  for (int i = 1; i < argc; i++) {
    if (i == argc - 1 && argv[i][0] == '-' &&
        argv[i][(int)strlen(argv[i]) - 1] == 'e') {
      param->error = 3;
      break;
    } else if (args[10] == 1) {
        memset(files, 0, max_memory_files);
        param->error = 4;
        break;
    } else if (prev == 'f') {
      search_query_from_file(argv[i], &search_queries, args, &max_memory_find,
                             param);
      prev = '+';
    } else if (argv[i][0] == '-' && prev != 'e') {
      work_with_argv(argv[i], args, files, &search_queries, param);
      if (argv[i][(int)strlen(argv[i]) - 1] == 'e' ||
          argv[i][(int)strlen(argv[i]) - 1] == 'f')
        prev = argv[i][(int)strlen(argv[i]) - 1];
      else if ((int)strlen(*search_queries) == 0)
        prev = '-';
    } else if (prev == 'e' || (prev == '-' && argv[i][0] != '-') ||
               (prev == '+' && (int)strlen(*search_queries) == 0)) {
      str_cat(*search_queries, argv[i], &max_memory_find, param);
      prev = '+';
    } else if (prev == '+' && argv[i][0] != '-') {
      count_files++;
      str_cat(files, argv[i], &max_memory_files, param);
    }
  }
  return count_files;
}

void work_with_argv(const char *argv, short *args, char *files,
                    char ***search_queries, struct param *param) {
  int len_search_q = 1024;
  char *search_que = calloc(len_search_q + 1, sizeof(char));
  if (search_que == NULL) param->error = 2;
  else {
    int count = 0, e = 0, f = 0;
    for (int i = 1; i < (int)strlen(argv); i++) {
      if (count > len_search_q) {
        len_search_q *= 2;
        char* temp = realloc(search_que, ((len_search_q * sizeof(char)) + 1));
        if (temp == NULL) {
          param->error = 2;
          break;
        }
        else search_que = temp;
      }
      if (e == 1)
        search_que[count++] = argv[i];
      else if (f == 1)
        search_que[count++] = argv[i];
      else if (argv[i] == 'e') {
        args[0] = 1;
        e = 1;
      } else if (argv[i] == 'i')
        args[1] = 1;
      else if (argv[i] == 'v')
        args[2] = 1;
      else if (argv[i] == 'c')
        args[3] = 1;
      else if (argv[i] == 'l')
        args[4] = 1;
      else if (argv[i] == 'n')
        args[5] = 1;
      else if (argv[i] == 'h')
        args[6] = 1;
      else if (argv[i] == 's')
        args[7] = 1;
      else if (argv[i] == 'f') {
        args[8] = 1;
        f = 1;
      } else if (argv[i] == 'o')
        args[9] = 1;
      else
        args[10] = 1;
    }
    if (e == 1 && (int)strlen(search_que) > 0) {
      strcat((**search_queries), search_que);
      strcat((**search_queries), "\n");
    } else if (f == 1 && (int)strlen(search_que) > 0) {
      strcat(files, search_que);
      strcat(files, "\n");
    }
    free(search_que);
  }
}

void str_cat(char *str1, const char *str2, long int *max_memory,
             struct param *param) {
  if ((int)strlen(str1) + (int)strlen(str2) > *max_memory) {
    *max_memory *= 2;
    char* temp = realloc(str1, ((*max_memory * sizeof(char)) + 1));
    if (temp == NULL) {
      param->error = 2;
    }
    else str1 = temp;
  }
  if (param->error == 0) {
    strcat(str1, str2);
    strcat(str1, "\n");
  }
}