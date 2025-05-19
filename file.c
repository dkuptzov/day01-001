#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main_get_file_name(const char *str1, char *str2, int *count, int *i, int *len_files_name, struct param *param) {
  while (str1[*i] != '\n') {
    if (*count > *len_files_name - 100) {
      *len_files_name *= 2;
      char *temp = realloc(str2, (*len_files_name + 1));
      if (temp == NULL) {
        param->error = 2;
      } else str2 = temp;
    } 
    else {
      str2[*count] = str1[*i];
      *count += 1;
      str2[*count] = '\0';
      if (str1[*i] == '\0') break;
      *i += 1;
    }
  }
  *i += 1;
}

void search_query_from_file(const char *file_name, char ***str, const short *args,
                            long int *max_memory, struct param *param) {
  long int count = (long int)strlen(**str);
  FILE *file = NULL;
  file = fopen(file_name, "r+");
  if (file == NULL && args[7] == 0)
    fprintf(stderr, "grep: %s: No such file or directory\n", file_name);
  else {
    int c = fgetc(file);
    while (c != EOF && param->error == 0) {
      (**str)[count++] = c;
      if (count > *max_memory - 100) {
        *max_memory *= 2;
        char *temp = realloc(**str, ((*max_memory) * sizeof(char)) + 1);
        if (temp == NULL) {
          param->error = 2;
          break;
        } else **str = temp;
      }
      c = fgetc(file);
    }
    (**str)[count] = '\0';
    fclose(file);
  }
}