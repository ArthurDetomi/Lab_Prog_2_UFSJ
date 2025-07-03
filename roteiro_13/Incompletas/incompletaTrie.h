/*---------------- File: Trie.h  -----------------------+
|TAD: Arvore Trie (Incompleta - Ainda nao Funciona)     |
|					      		                        |
| Adaptado da aula do Prof. Elverton                    |
| Implementado por Guilherme C. Pena em 04/12/2023      |
+-------------------------------------------------------+ */

#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>

#define D 32 // depende de int (32), char (8)

typedef struct registro {
    int chave;
    /* outros dados */
}Registro;

typedef struct no{
    struct no *esq;
    struct no *dir;
    Registro *reg;
}No;



No * cria_trie(Registro *reg){
    No * t = (No *) malloc (sizeof(No));
    t->dir = t->esq = NULL;
    t->reg = reg;
    return t;
}

int digit(int chave, int i){
    // Retorna o i-esimo bit da chave k a partir da esquerda
    int c, j;
    if (i == 0)
        return 0;
    else {
        c = chave;
        for (j = 1; j <= D - i; j++)
            c /= 2;
        return (c & 1);
    }
}

Registro * pesquisaR(No *t, int chave, int p) {
    if(t == NULL) return NULL;
    if(t->esq == NULL && t->dir == NULL) {
        int regchave = t->reg->chave;
        if(regchave == chave) { return t->reg; }
        else { return NULL; }
    }
    if(digit(chave, p) == 0) {
        return pesquisaR(t->esq, chave, p+1); }
    else { return pesquisaR(t->dir, chave, p+1); }
}

Registro * pesquisa(No *trie, int chave){   
    return pesquisaR(trie, chave, 0);
}

No* separa(No* no1, No* no2, int p) {
    No* novo = cria_trie(NULL);
    int chave1 = no1->reg->chave;
    int chave2 = no2->reg->chave;
    if(digit(chave1, p) == 0 && digit(chave2, p) == 0){
        novo->esq = separa(no1, no2, p+1);
    } else if(digit(chave1, p) == 0 && digit(chave2, p) == 1) {
        novo->esq = no1; novo->dir = no2;
    } else if(digit(chave1, p) == 1 && digit(chave2, p) == 0) {
        novo->dir = no1; novo->esq = no2;
    } else if(digit(chave1, p) == 1 && digit(chave2, p) == 1) {
        novo->dir = separa(no1, no2, p+1);
    }
    return novo;
}

No* insereR(No *t, Registro *reg, int p) {
    int chave = reg->chave;
    if(t == NULL) return cria_trie(reg);
    if(t->esq == NULL && t->dir == NULL) {
        return separa(cria_trie(reg), t, p);
    }
    if(digit(chave, p) == 0)
        t->esq = insereR(t->esq, reg, p+1);
    else t->dir = insereR(t->dir, reg, p+1);
    return t;
}

void insere(No **trie, Registro *reg) {
    *trie = insereR(*trie, reg, 0);
}




#endif
