#ifndef AVL_FUNC_H
#define AVL_FUNC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAIOR(a, b) ((a > b) ? (a) : (b))

typedef struct Funcionario {
  char nome[50];
  double salario;
  int ano;
} Funcionario;

typedef struct NO {
  Funcionario info;
  int fb, alt;
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

int insereRec(NO **raiz, Funcionario elem);

int insereElem(AVL *raiz, Funcionario elem);

int pesquisa(AVL *raiz, Funcionario *elem);

int removeRec(NO **raiz, Funcionario elem);

int removeElem(AVL *raiz, Funcionario elem);

void em_ordem(NO *raiz, int nivel);

void pre_ordem(NO *raiz, int nivel);

void pos_ordem(NO *raiz, int nivel);

void imprime(AVL *raiz);

int get_quantidade_nos(AVL *raiz);

int buscar_elem_por_nome(AVL *raiz, char *nome, Funcionario *f);

int buscar_com_maior_salario(AVL *raiz, Funcionario *f);

int buscar_com_menor_salario(AVL *raiz, Funcionario *f);

#endif