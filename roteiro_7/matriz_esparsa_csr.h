#ifndef MATRIZ_ESPARSA_CSR
#define MATRIZ_ESPARSA_CSR

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int *A; // Valores
  int *IA;
  int *JA;
  int lin, col, QNN, QI;
} Matriz;
// QNN - Quantidade de Nao Nulos
// QI - Quantidade de Inseridos

Matriz *criaMatriz(int l, int c, int qnn);

int *meuRealloc(int *v, int tam);

void imprimeVetores(Matriz *ms);

int insereElem(Matriz *ms, int elem, int i, int j);

int removeElem(Matriz *ms, int i, int j);

int consultaElem(Matriz *ms, int i, int j);

void imprime(Matriz *ms);

void destroiMatriz(Matriz **ms);

#endif