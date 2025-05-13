CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  -o $@.out matriz_esparsa_csr.c $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
