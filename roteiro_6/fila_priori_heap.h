#ifndef FILA_PRIORI_HEAP
#define FILA_PRIORI_HEAP

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct NO {
  int info, prio;
} NO;

typedef struct {
  int qtd;
  NO dados[MAX];
} FilaP;

FilaP *criaFila();

void destroiFila(FilaP **fp);

int tamanhoFila(FilaP *fp);

int estaCheia(FilaP *fp);

int estaVazia(FilaP *fp);

void trocaNO(NO *a, NO *b);

void ajustaHeapInsere(FilaP *fp, int filho);

int inserirPrio(FilaP *fp, int elem, int pri);

void ajustaHeapRemove(FilaP *fp, int pai);

int removeInicio(FilaP *fp);

int verInicio(FilaP *fp, int *valor, int *pri);

void imprime(FilaP *fp);

#endif