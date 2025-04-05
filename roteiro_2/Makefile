CC = gcc
CFLAGS = -Wall -Wextra -g

%: %.c
	$(CC) $(CFLAGS)  -o $@.out catalogo_produtos.c conta_bancaria.c $<  -lm 

clean:
	@echo 'Cleaning...'
	rm *.out
