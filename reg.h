#ifndef REG_H
#define REG_H

#include "struct.h"

typedef struct pos {
  int start_position;
  int end_position;
  int next_position;
  int count;
  int count2;
} position;

int work_with_reg(const short *args, const char *search_queries,
  const char *str, struct param *param);
int work_with_reg_o(const short *args, const char *search_queries, char *str,
                    const char *file_name, int count_files, int *string_count,
                    struct param *param);
void change_pos(position *pos, int start, int end, int next, int count,
                int count2);

#endif