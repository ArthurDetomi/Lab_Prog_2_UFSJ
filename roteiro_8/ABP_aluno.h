#ifndef ABP_ALUNO_H
#define ABP_ALUNO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
  char nome[50];
  int matricula;
  double nota;
} Aluno;

typedef struct NO {
  Aluno info;
  struct NO *esq;
  struct NO *dir;
} NO;

typedef struct NO *ABP;

NO *alocarNO();

void liberarNO(NO *q);

ABP *criaABP();

void destroiRec(NO *no);

void destroiABP(ABP *raiz);

int estaVazia(ABP *raiz);

int insereRec(NO **raiz, Aluno aluno);

int insereElem(ABP *raiz, Aluno aluno);

int pesquisaRec(NO **raiz, Aluno aluno);

int pesquisa(ABP *raiz, Aluno aluno);

int removeRec(NO **raiz, Aluno aluno);

int removeElem(ABP *raiz, Aluno aluno);

void em_ordem(NO *raiz, int nivel);

void pre_ordem(NO *raiz, int nivel);

void pos_ordem(NO *raiz, int nivel);

void imprime(ABP *raiz);

int get_quantidade_nos(ABP *raiz);

Aluno *get_aluno_maior_nota(ABP *raiz);

Aluno *get_aluno_pior_nota(ABP *raiz);

#endif