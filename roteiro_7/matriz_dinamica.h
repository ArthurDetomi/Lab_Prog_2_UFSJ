#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int **dados;
  int lin, col;
} Matriz;

void zeraMatriz(Matriz *mat);

Matriz *criaMatriz(int l, int c);

void destroiMatriz(Matriz *mat);

int preencheAleatorio(Matriz *mat, int ini, int fim);

int insereElem(Matriz *mat, int elem, int l, int c);

int consultaElem(Matriz *mat, int *p, int l, int c);

void imprime(Matriz *mat);

#endif