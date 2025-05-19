#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"
#include "file.h"
#include "malloc.h"
#include "print.h"
#include "reg.h"
#include "struct.h"

int main(int argc, const char *argv[]) {
  struct param param = {0};
  short args[11] = {0};
  int count_files = 0, str_count = 0, is_work = 1, fls = 0, c = 0;
  int len_str = 1024, len_files_name = 1024, len_final_print = 1024;
  char *search_queries, *files, *file_name, *str, *final_print_str;
  make_malloc_str(&search_queries, &files, &file_name, &str,
                  &final_print_str, &param);
  if (argc > 2 && param.error == 0)
    count_files = analize_args(argc, argv, &search_queries, files, args, &param);
  else if (argc <= 2)
    fprintf(stderr, "No args! Try again.\n");
  while (is_work && param.error == 0) {
    FILE *file = NULL;
    int c_count = 0, val = 1, count = 0;
    main_get_file_name(files, file_name, &count, &fls, &len_files_name, &param);
    file = fopen(file_name, "r+");
    if (file != NULL) c = fgetc(file);
    while (c != EOF && file != NULL && param.error == 0) {
      str[c_count++] = c;
      printf("STR1: %s * %d**\n", str, c_count);
      malloc_is_ok(c_count, &len_str, &str, &param);
      printf("STR2: %s * %d**\n", str, c_count);
      if ((c == '\n') && param.error == 0) {
        str[c_count] = '\0';
        if (args[9] == 1)
          val = work_with_reg_o(args, search_queries, str, file_name,
                                count_files, &str_count, &param);
        else {
          val = work_with_reg(args, search_queries, str, &param);
          print_res(val, args, file_name, str, count_files, &str_count, &param);
        }
        memset(str, 0, len_str);
        c_count = 0;
      }
      c = fgetc(file);
      if (c == EOF || (val == 0 && args[4] == 1)) break;
    }
    if (file != NULL) {
      fclose(file);
      final_print(val, final_print_str, args, file_name, count_files,
                  &str_count, &len_final_print, &param);
    } else if (args[7] == 0 && (int)strlen(file_name) > 0)
      print_no_file(args, final_print_str, file_name, &len_final_print);
    else if ((int)strlen(file_name) == 0)
      is_work = 0;
    memset(file_name, 0, len_files_name);
  }
  free_malloc_str(&search_queries, &files, &file_name, &str,
                  &final_print_str, &param);
  printf_error(&param);
  return 0;
}
