#include "func.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void work_with_argv(const char *argv, short *args) {
  if (argv[0] == '-' && argv[1] == '-') {
    if (!strncmp(argv, "--number-nonblank", 17))
      args[0] = 1;
    else if (!strncmp(argv, "--number", 8))
      args[4] = 1;
    else if (!strncmp(argv, "--squeeze-blank", 15))
      args[5] = 1;
  } else if (argv[0] == '-') {
    for (int i = 1; i < (int)strlen(argv); i++) {
      if (argv[i] == 'b')
        args[0] = 1;
      else if (argv[i] == 'e')
        args[1] = 1;
      else if (argv[i] == 'v')
        args[2] = 1;
      else if (argv[i] == 'E')
        args[3] = 1;
      else if (argv[i] == 'n')
        args[4] = 1;
      else if (argv[i] == 's')
        args[5] = 1;
      else if (argv[i] == 't')
        args[6] = 1;
      else if (argv[i] == 'T')
        args[7] = 1;
      else
        args[8] = 1;
    }
  }
}

void work_with_files(FILE *file, const short *args, int *str_count) {
  int c = fgetc(file);
  int dont_print = 0, first_n = 0, first_s = 0, first_b = 0;
  char prev_c = 'x';
  while (c != EOF) {
    if (args[0] == 1 && args[5] == 1) {
      dont_print = cat_args_s(&first_s, c, prev_c);
      if (dont_print == 0) cat_args_b(&first_b, str_count, c, prev_c);
    } else if (args[0] == 1)
      cat_args_b(&first_b, str_count, c, prev_c);
    else if (args[4] == 1 && args[5] == 1) {
      dont_print = cat_args_s(&first_s, c, prev_c);
      if (dont_print == 0) cat_args_n(&first_n, str_count, prev_c);
    } else if (args[4] == 1)
      cat_args_n(&first_n, str_count, prev_c);
    else if (args[5] == 1) {
      dont_print = cat_args_s(&first_s, c, prev_c);
    }
    if (dont_print == 0) {
      if (args[1] == 1 || args[2] == 1 || args[6] == 1)
        dont_print = cat_args_evt(&c, args);
      else if (args[7] == 1)
        dont_print = cat_args_T(c);
      if (args[3] == 1 && args[1] == 0) cat_args_E(c);
    }
    if (dont_print == 0) fputc(c, stdout);
    prev_c = c;
    c = fgetc(file);
    dont_print = 0;
  }
}

void cat_args_b(int *first_b, int *str_count, int c, char prev_c) {
  if ((*first_b == 0 && c != '\n') || (prev_c == '\n' && c != '\n'))
    cat_print_1(&first_b, &str_count);
}

int cat_args_evt(int *c, const short *args) {
  if (*c <= 31 && *c != '\t' && *c != '\n') {
    printf("^");
    *c += 64;
  } else if (*c > 127 && *c < 160) {
    printf("M-^");
    *c -= 64;
  } else if (*c >= 160) {
    printf("M-");
    *c -= 128;
  } else if (*c == 127)
    printf("^?");
  else if (*c == '\n' && args[1] == 1) {
    printf("$");
  } else if (*c == '\t' && (args[6] == 1 || args[7] == 1)) {
    printf("^I");
    return 1;
  }
  return 0;
}

void cat_args_E(int c) {
  if (c == '\n') printf("$");
}

void cat_args_n(int *first_n, int *str_count, char prev_c) {
  if (*first_n == 0 || prev_c == '\n') cat_print_1(&first_n, &str_count);
}

int cat_args_s(int *first_s, int c, char prev_c) {
  int dont_print = 0;
  if (c == '\n' && prev_c == '\n' && *first_s != 2)
    *first_s = 2;
  else if (c == '\n' && prev_c == '\n' && *first_s == 2)
    dont_print = 1;
  else {
    *first_s = 1;
    dont_print = 0;
  }
  return dont_print;
}

int cat_args_T(int c) {
  if (c == '\t') {
    printf("^I");
    return 1;
  }
  return 0;
}

void cat_print_1(int **first, int **str_count) {
  printf("%6d\t", **str_count);
  **str_count += 1;
  **first = 1;
}