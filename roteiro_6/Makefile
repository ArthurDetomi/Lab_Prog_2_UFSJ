CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  -o $@.out fila_priori_heap.c $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
