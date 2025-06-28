CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  tempo.c -o $@.out $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
