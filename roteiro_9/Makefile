CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  -o $@.out AVL_FUNC.c $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
