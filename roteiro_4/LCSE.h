/*----------------- File: LCSE.h  ----------------------+
|Lista Circular Simplesmente Encadeada                  |
| | | | | Implementado por Guilherme C. Pena em 19/09/2023      |
+-------------------------------------------------------+ */

#ifndef LCSE_H
#define LCSE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
  int info;
  struct NO *prox;
} NO;

typedef struct NO *Lista;

Lista *criaLista();

int listaVazia(Lista *li);

NO *alocarNO();

void liberarNO(NO *q);

int insereIni(Lista *li, int elem);

int insereFim(Lista *li, int elem);

int removeIni(Lista *li);

int removeFim(Lista *li);

void imprimeLista(Lista *li);

void destroiLista(Lista *li);

/*
  Exercício 4.2
*/
int tamanho(Lista *li);
int procura(Lista *li, int elem);

#endif