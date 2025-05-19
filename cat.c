#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

int main(int argc, const char *argv[]) {
  int str_count = 1;
  short args[9] = {0};
  if (argc > 1) {
    for (int i = 1; i < argc; i++) {
      work_with_argv(argv[i], args);
    }
    for (int j = 1; j < argc && args[8] == 0; j++) {
      FILE *file = NULL;
      if (argv[j][0] != '-') {
        file = fopen(argv[j], "r");
        if (file != NULL) {
          work_with_files(file, args, &str_count);
          fclose(file);
        } else
          printf("cat: %s: No such file or directory\n", argv[j]);
      }
    }
  } else
    fprintf(stderr, "No args! Try again.\n");
  if (args[8] == 1) fprintf(stderr, "Invalid option.\n");
  return 0;
}