#include "print.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_res(int value, const short *args, const char *file_name,
               const char *str, int count_files, int *string_count,
               const struct param *param) {
  if (param->error == 0) {
    if (value == 0 && args[2] == 0 && args[3] == 0 && args[4] == 0 &&
        args[5] == 0 && args[6] == 0) {
      if (count_files > 1)
        printf("%s:%s", file_name, str);
      else
        printf("%s", str);
    } else if (value == 0 && args[2] == 0 && (args[3] == 1 || args[4] == 1))
      *string_count += 1;
    else if (value != 0 && args[2] == 1 && (args[3] == 1 || args[4] == 1))
      *string_count += 1;
    else if (value != 0 && args[2] == 1 && args[3] == 0 && args[5] == 0) {
      if (count_files > 1 && args[6] == 0)
        printf("%s:%s", file_name, str);
      else
        printf("%s", str);
    } else if (value != 0 && args[2] == 1 && args[5] == 1 && args[6] == 1 &&
               count_files > 1) {
      *string_count += 1;
      printf("%d:%s", *string_count, str);
    } else if (value == 0 && args[2] == 0 && args[5] == 1 && args[6] == 1 &&
               count_files > 1) {
      *string_count += 1;
      printf("%d:%s", *string_count, str);
    } else if (value != 0 && args[5] == 1 && args[2] == 1 && count_files > 1) {
      *string_count += 1;
      printf("%s:%d:%s", file_name, *string_count, str);
    } else if (value == 0 && args[5] == 1 && args[2] == 0 && count_files > 1) {
      *string_count += 1;
      printf("%s:%d:%s", file_name, *string_count, str);
    } else if (args[5] == 1 && args[3] == 0) {
      *string_count += 1;
      if ((value == 0 && args[2] == 0) || (value != 0 && args[2] == 1))
        printf("%d:%s", *string_count, str);
    } else if (args[6] == 1 && value == 0 && args[2] == 0)
      printf("%s", str);
  }
}

void final_print(int value, char *final_print_string, const short *args,
                 const char *file_name, int count_files, int *string_count,
                 int *len_final_print, struct param *param) {
  char str[20];
  if (((int)strlen(final_print_string) + 20) > *len_final_print) {
    *len_final_print += 100;
    final_print_string =
        realloc(final_print_string, *len_final_print * sizeof(char) + 1);
    if (final_print_string == NULL) param->error = 2;
  }
  if ((args[4] == 1 && count_files > 0 && value == 0) ||
      (args[4] == 1 && args[2] == 1 && value != 0)) {
    strcat(final_print_string, file_name);
    strcat(final_print_string, "\n");
  } else if (args[3] == 1 && count_files > 1 && args[6] == 0 &&
             (args[5] == 1 || args[7] == 1 || args[8] || args[9] == 1 ||
              args[0] == 1)) {
    snprintf(str, sizeof str, "%d", *string_count);
    strcat(final_print_string, file_name);
    strcat(final_print_string, ":");
    strcat(final_print_string, str);
    strcat(final_print_string, "\n");
  } else if (args[3] == 1 && count_files > 1 && args[6] == 0 &&
             *string_count > 0) {
    snprintf(str, sizeof str, "%d", *string_count);
    strcat(final_print_string, file_name);
    strcat(final_print_string, ":");
    strcat(final_print_string, str);
    strcat(final_print_string, "\n");
  } else if ((args[3] == 1 && args[4] == 0) ||
             (args[3] == 1 && args[6] == 1 && count_files > 1)) {
    snprintf(str, sizeof str, "%d", *string_count);
    strcat(final_print_string, str);
    strcat(final_print_string, "\n");
  }
  *string_count = 0;
}

void printf_error(const struct param *param) {
  if (param->error == 1)
    fprintf(stderr, "Error compiling regular expression.\n");
  else if (param->error == 2)
    fprintf(stderr, "Memory allocation error.\n");
  else if (param->error == 3)
    fprintf(stderr, "Option requires an argument.\n");
  else if (param->error == 4)
    fprintf(stderr, "Invalid option. Try again.\n");
}

void print_reg_o(const short *args, int count_files, int **string_count,
                 const char *print_this, const char *file_name) {
  if (args[5] == 1 && args[6] == 1 && count_files > 1)
    printf("%d:%s\n", **string_count + 1, print_this);
  else if (args[5] == 1 && count_files > 1)
    printf("%s:%d:%s\n", file_name, **string_count + 1, print_this);
  else if (args[5] == 1)
    printf("%d:%s\n", **string_count + 1, print_this);
  else if (count_files > 1 && args[6] == 1)
    printf("%s\n", print_this);
  else if (count_files > 1 && args[4] == 0)
    printf("%s:%s\n", file_name, print_this);
  else if (args[4] == 0)
    printf("%s\n", print_this);
}

void print_no_file(const short *args, char *final_print_str,
                   const char *file_name, const int *len_final_print) {
  if (args[6] == 1 || args[3] == 1 || args[4] == 1) {
    printf("%s", final_print_str);
    printf("grep: %s: No such file or directory\n", file_name);
    memset(final_print_str, 0, *len_final_print);
    final_print_str[0] = '\0';
  } else
    printf("grep: %s: No such file or directory\n", file_name);
}