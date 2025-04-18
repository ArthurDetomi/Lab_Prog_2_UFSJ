/*----------------- File: Lista.h ----------------------+
|Lista Sequencial Estatica                              |
| | | | | Implementado por Guilherme C. Pena em 12/09/2023      |
+-------------------------------------------------------+ */
#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int qtd;
  int dados[MAX];
} Lista;

Lista *criaLista();

void destroiLista(Lista *li);

int tamanhoLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int insereFim(Lista *li, int elem);

int insereIni(Lista *li, int elem);
/*
  Exercício 1-3 - Insere um elemento na lista de forma ordenada
*/
int insereOrdenado(Lista *li, int elem);

/*
  Exercício 1.4 - Remove a primeira ocorrência do elemento caso exista
*/
int removeElemento(Lista *li, int elem);

int imprimeLista(Lista *li);

int removeFim(Lista *li);

int removeIni(Lista *li);

// Exercicio 1-1 busca determinado elemento e se encontra retorna seu indice
// caso contrário retorna -1
int procura(Lista *li, int x);

#endif
