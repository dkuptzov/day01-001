CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
GREP = grep.c args.c file.c malloc.c print.c reg.c
QUEST1 = s21_grep

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_grep: $(GREP)
	$(CC) $(CFLAGS) $^ -o $(QUEST1)

.PHONY: clean

clean:
	rm -rf $(QUEST1) $(TARGET)

rebuild: clean $(TARGET)
