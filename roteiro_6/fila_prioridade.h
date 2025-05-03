#ifndef FILA_PRIORIDADE
#define FILA_PRIORIDADE

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int info, prio;
  struct NO *prox;
} NO;

typedef struct NO *FilaP;

NO *alocarNO();

void liberarNO(NO *q);

FilaP *criaFila();

int estaVazia(FilaP *fp);

int inserirPrio(FilaP *fp, int elem, int pri);

int removeInicio(FilaP *fp);

int verInicio(FilaP *fp, int *p, int *pri);

void imprime(FilaP *fp);

void destroiFila(FilaP **fp);

int tamanhoFila(FilaP *fp);

#endif