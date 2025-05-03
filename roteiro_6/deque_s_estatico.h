#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int qtd, ini, fim;
  int dados[MAX];
} Deque;

Deque *criaDeque();

void destroiDeque(Deque **dq);

int tamanhoDeque(Deque *dq);

int estaCheio(Deque *dq);

int estaVazio(Deque *dq);

int insereInicio(Deque *dq, int elem);

int insereFim(Deque *dq, int elem);

int removeInicio(Deque *dq);

int removeFim(Deque *dq);

int verInicio(Deque *dq, int *p);

int verFim(Deque *dq, int *p);

void imprime(Deque *dq);

#endif