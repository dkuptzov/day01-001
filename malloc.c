#include "malloc.h"

#include <stdio.h>
#include <stdlib.h>

void make_malloc_str(char **search_queries, char **files, char **file_name,
                     char **string, char **final_print_string,
                     struct param *param) {
  int max_count = 1024;
  *search_queries = calloc(max_count + 1, sizeof(char));
  *files = calloc(max_count + 1, sizeof(char));
  *file_name = calloc(max_count + 1, sizeof(char));
  *string = calloc(max_count + 1, sizeof(char));
  *final_print_string = calloc(max_count + 1, sizeof(char));
  if (*search_queries == NULL || *files == NULL || *file_name == NULL ||
      *string == NULL || *final_print_string == NULL)
    param->error = 2;
}

void free_malloc_str(char **search_queries, char **files, char **file_name,
                     char **string, char **final_print_string,
                     const struct param *param) {
  if (param->error == 0) printf("%s", *final_print_string);
  free(*final_print_string);
  free(*search_queries);
  free(*files);
  free(*file_name);
  free(*string);
}

void malloc_is_ok(int c_count, int *len_str, char **str,
                  struct param *param) {
  if (c_count >= (*len_str)) {
    *len_str *= 2;
    char *temp = realloc(*str, (*len_str) + 1);
    if (temp == NULL) {
      param->error = 2;
    } else
      *str = temp;
  }
}
