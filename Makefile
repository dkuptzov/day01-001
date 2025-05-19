CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
CAT = cat.c func.c
QUEST1 = s21_cat

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

s21_cat: $(CAT)
	$(CC) $(CFLAGS) $^ -o $(QUEST1)

.PHONY: clean

clean:
	rm -rf $(QUEST1) $(TARGET)

rebuild: clean $(TARGET)
