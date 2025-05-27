CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  -o $@.out ABP.c $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
