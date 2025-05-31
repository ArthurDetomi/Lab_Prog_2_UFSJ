#ifndef AVL_H
#define AVL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct NO {
  int info, fb, alt;
  struct NO *esq;
  struct NO *dir;
} NO;

typedef struct NO *AVL;

NO *alocarNO();

void liberarNO(NO *q);

AVL *criaAVL();

void destroiRec(NO *no);

void destroiAVL(AVL *raiz);

int estaVazia(AVL *raiz);

// Calcula FB
int altura(NO *raiz);

int FB(NO *raiz);

// Funcoes de Rotacao Simples
void avl_RotDir(NO **raiz);

void avl_RotEsq(NO **raiz);

// Funcoes de Rotacao Dupla
void avl_RotEsqDir(NO **raiz);

void avl_RotDirEsq(NO **raiz);

void avl_RotEsqDir2(NO **raiz);

void avl_RotDirEsq2(NO **raiz);

// Funcoes Auxiliares referentes a cada filho
void avl_AuxFE(NO **raiz);

void avl_AuxFD(NO **raiz);

int insereRec(NO **raiz, int elem);

int insereElem(AVL *raiz, int elem);

int pesquisaRec(NO **raiz, int elem);

int pesquisa(AVL *raiz, int elem);

int removeRec(NO **raiz, int elem);

int removeElem(AVL *raiz, int elem);

void em_ordem(NO *raiz, int nivel);

void pre_ordem(NO *raiz, int nivel);

void pos_ordem(NO *raiz, int nivel);

void imprime(AVL *raiz);

#endif