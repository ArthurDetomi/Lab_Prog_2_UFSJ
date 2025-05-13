#ifndef MATRIZ_FAIXA_H
#define MATRIZ_FAIXA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int *diagonal;
  int *superior;
  int *inferior;
  int tam;
} Matriz;

void zeraMatriz(Matriz *mf);

Matriz *criaMatriz(int t);

void destroiMatriz(Matriz **mf);

int preencheAleatorio(Matriz *mf, int ini, int fim);

int insereElem(Matriz *mf, int elem, int i, int j);

int consultaElem(Matriz *mf, int i, int j);

void imprimeFaixaVetores(Matriz *mf);

void imprime(Matriz *mf);

#endif