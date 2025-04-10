CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  -o $@.out cubo.c $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
