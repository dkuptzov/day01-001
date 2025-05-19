#include "reg.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "malloc.h"
#include "print.h"

int work_with_reg(const short *args, const char *search_queries,
                  const char *str, struct param *param) {
  int value = 0;
  long int len_search_q = 1024;
  regex_t rx;
  char *search_q = calloc(len_search_q + 1, sizeof(char));
  if (search_q == NULL) param->error = 2;
  else {
    int count = 0;
    for (int i = 0; i < (int)strlen(search_queries); i++) {
      if (search_queries[i] != '\n') {
        search_q[count++] = search_queries[i];
        if (count >= len_search_q - 100) {
          len_search_q *= 2;
          char *temp = realloc(search_q, (len_search_q * sizeof(char)) + 1);
          if (temp == NULL) {
            param->error = 2;
            break;
          } else
            search_q = temp;
        }
      } else {
        search_q[count] = '\0';
        if (args[1] == 1)
          value = regcomp(&rx, search_q, REG_ICASE);
        else
          value = regcomp(&rx, search_q, 0);
        if (value != 0) {
          param->error = 1;
          break;
        }
        else {
          value = regexec(&rx, str, 0, NULL, 0);
          regfree(&rx);
        }
        count = 0;
        memset(search_q, 0, len_search_q);
        if (value == 0) break;
      }
    }
  }
  free(search_q);
  return value;
}

int work_with_reg_o(const short *args, const char *search_queries, char *str,
                    const char *file_name, int count_files, int *string_count,
                    struct param *param) {
  int val = 0, ready = 0;
  position pos = {1000, 0, 0, 0, 0};
  regex_t rx;
  size_t nmatch = 1;
  regmatch_t pmatch[nmatch];
  long int len_search_q = 1024, len_print = 1024;
  char *search_q = calloc(len_search_q + 1, sizeof(char));
  char *print = calloc(len_print + 1, sizeof(char));
  if (search_q == NULL || print == NULL) param->error = 2;
  char *ptr = str;
  ptr[(int)strlen(ptr) - 1] = '\0';
  while (pos.next_position == 0 && param->error == 0) {
    pos.next_position = 1;
    for (int i = 0; i < (int)strlen(search_queries); i++) {
      if (search_queries[i] != '\n')
        search_q[pos.count++] = search_queries[i];
      else {
        ready = 1;
        search_q[pos.count] = '\0';
        pos.count = 0;
        val = (args[1] == 1) ? regcomp(&rx, search_q, REG_ICASE)
                             : regcomp(&rx, search_q, 0);
      }
      if (ready == 1 && val != 0)
        param->error = 1;
      else if (val == 0 && ready == 1) {
        val = regexec(&rx, ptr, nmatch, pmatch, 0);
        regfree(&rx);
        ready = 0;
        if (val == 0 && args[4] == 1)
          break;
        else if ((val == 0 && args[3] == 1) || (val != 0 && args[2] == 1)) {
          *string_count += 1;
          break;
        } else if (val == 0 && args[2] == 0 &&
                   (int)pmatch[0].rm_so < pos.start_position) {
          change_pos(&pos, (int)pmatch[0].rm_so, (int)pmatch[0].rm_eo, 0, 0, 0);
          memset(print, 0, 100);
        }
        pos.count2 = 0;
        for (int j = pos.start_position; j < pos.end_position; j++)
          print[pos.count2++] = ptr[j];
        memset(search_q, 0, 100);
      }
    }
    if (pos.next_position == 0 && param->error == 0) {
      ptr += pos.end_position;
      if ((args[2] == 1 && args[3] == 0) || (args[3] == 1))
        break;
      else
        print_reg_o(args, count_files, &string_count, print, file_name);
    } else if (args[5] == 1 && args[2] == 0 && args[3] == 0)
      *string_count += 1;
    change_pos(&pos, 1000, 0, pos.next_position, 0, 0);
    memset(search_q, 0, sizeof(len_search_q));
    memset(print, 0, sizeof(len_print));
  }
  free(search_q);
  free(print);
  return val;
}

void change_pos(position *pos, int start, int end, int next, int count,
                int count2) {
  pos->start_position = start;
  pos->end_position = end;
  pos->next_position = next;
  pos->count = count;
  pos->count2 = count2;
}
