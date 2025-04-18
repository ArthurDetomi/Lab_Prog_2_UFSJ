CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  -o $@.out LCSE.c $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
