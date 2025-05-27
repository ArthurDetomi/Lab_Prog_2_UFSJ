
#include "ABP_aluno.h"

#include <string.h>

NO *alocarNO() { return (NO *)malloc(sizeof(NO)); }

void liberarNO(NO *q) { free(q); }

ABP *criaABP() {
  ABP *raiz = (ABP *)malloc(sizeof(ABP));
  if (raiz != NULL)
    *raiz = NULL;
  return raiz;
}

void destroiRec(NO *no) {
  if (no == NULL)
    return;
  destroiRec(no->esq);
  destroiRec(no->dir);
  liberarNO(no);
  no = NULL;
}

void destroiABP(ABP *raiz) {
  if (raiz != NULL) {
    destroiRec(*raiz);
    free(raiz);
  }
}

int estaVazia(ABP *raiz) {
  if (raiz == NULL)
    return 0;
  return (*raiz == NULL);
}

int insereRec(NO **raiz, Aluno aluno) {
  if (*raiz == NULL) {
    NO *novo = alocarNO();
    if (novo == NULL)
      return 0;
    novo->info = aluno;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
  } else {

    int result_comp = strcmp(aluno.nome, (*raiz)->info.nome);

    if (result_comp == 0) {
      printf("Aluno Existente!\n");
      return 0;
    }
    if (result_comp < 0)
      return insereRec(&(*raiz)->esq, aluno);
    else if (result_comp > 0)
      return insereRec(&(*raiz)->dir, aluno);
  }
  return 1;
}

int insereElem(ABP *raiz, Aluno aluno) {
  if (raiz == NULL)
    return 0;
  return insereRec(raiz, aluno);
}

int pesquisaRec(NO **raiz, Aluno aluno) {
  if (*raiz == NULL)
    return 0;

  int result_comp = strcmp((*raiz)->info.nome, aluno.nome);

  if (result_comp == 0)
    return 1;
  if (result_comp < 0)
    return pesquisaRec(&(*raiz)->esq, aluno);
  else
    return pesquisaRec(&(*raiz)->dir, aluno);
}

int pesquisa(ABP *raiz, Aluno aluno) {
  if (raiz == NULL)
    return 0;
  if (estaVazia(raiz))
    return 0;
  return pesquisaRec(raiz, aluno);
}

int removeRec(NO **raiz, Aluno aluno) {
  if (*raiz == NULL)
    return 0;

  int result_comp = strcmp((*raiz)->info.nome, aluno.nome);

  if (result_comp == 0) {
    NO *aux;
    if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) {
      // Caso 1 - NO sem filhos
      printf("Caso 1: Liberando %s..\n", (*raiz)->info.nome);
      liberarNO(*raiz);
      *raiz = NULL;
    } else if ((*raiz)->esq == NULL) {
      // Caso 2.1 - Possui apenas uma subarvore direita
      printf("Caso 2.1: Liberando %s..\n", (*raiz)->info.nome);
      aux = *raiz;
      *raiz = (*raiz)->dir;
      liberarNO(aux);
    } else if ((*raiz)->dir == NULL) {
      // Caso 2.2 - Possui apenas uma subarvore esquerda
      printf("Caso 2.2: Liberando %s..\n", (*raiz)->info.nome);
      aux = *raiz;
      *raiz = (*raiz)->esq;
      liberarNO(aux);
    } else {
      // Caso 3 - Possui as duas subarvores (esq e dir)
      // Duas estrategias:
      // 3.1 - Substituir pelo NO com o MAIOR valor da subarvore esquerda
      // 3.2 - Substituir pelo NO com o MENOR valor da subarvore direita
      printf("Caso 3: Liberando %s..\n", (*raiz)->info.nome);
      // Estrategia 3.1:
      NO *Filho = (*raiz)->esq;
      while (Filho->dir != NULL) // Localiza o MAIOR valor da subarvore esquerda
        Filho = Filho->dir;
      (*raiz)->info = Filho->info;
      Filho->info = aluno;
      return removeRec(&(*raiz)->esq, aluno);
    }
    return 1;
  } else if (result_comp < 0)
    return removeRec(&(*raiz)->esq, aluno);
  else
    return removeRec(&(*raiz)->dir, aluno);
}

int removeElem(ABP *raiz, Aluno aluno) {
  if (pesquisa(raiz, aluno) == 0) {
    printf("Elemento inexistente!\n");
    return 0;
  }
  return removeRec(raiz, aluno);
}

void em_ordem(NO *raiz, int nivel) {
  if (raiz != NULL) {
    em_ordem(raiz->esq, nivel + 1);
    printf("[%s, %d] ", raiz->info.nome, nivel);
    em_ordem(raiz->dir, nivel + 1);
  }
}

void pre_ordem(NO *raiz, int nivel) {
  if (raiz != NULL) {
    printf("[%s, %d] ", raiz->info.nome, nivel);
    pre_ordem(raiz->esq, nivel + 1);
    pre_ordem(raiz->dir, nivel + 1);
  }
}

void pos_ordem(NO *raiz, int nivel) {
  if (raiz != NULL) {
    pos_ordem(raiz->esq, nivel + 1);
    pos_ordem(raiz->dir, nivel + 1);
    printf("[%s, %d] ", raiz->info.nome, nivel);
  }
}

void imprime(ABP *raiz) {
  if (raiz == NULL)
    return;
  if (estaVazia(raiz)) {
    printf("Arvore Vazia!\n");
    return;
  }
  printf("\nEm Ordem: ");
  em_ordem(*raiz, 0);
  printf("\nPre Ordem: ");
  pre_ordem(*raiz, 0);
  printf("\nPos Ordem: ");
  pos_ordem(*raiz, 0);
  printf("\n");
}

int get_quantidade_nos(ABP *raiz) {
  if (*raiz == NULL) {
    return 0;
  }

  int qtd = 1;

  qtd += get_quantidade_nos(&(*raiz)->esq);

  qtd += get_quantidade_nos(&(*raiz)->dir);

  return qtd;
}

Aluno *get_aluno_maior_nota(ABP *raiz) {
  if (*raiz == NULL)
    return NULL;

  Aluno *melhor_esq = get_aluno_maior_nota(&(*raiz)->esq);
  Aluno *melhor_dir = get_aluno_maior_nota(&(*raiz)->dir);

  Aluno *melhor = &(*raiz)->info;

  if (melhor_esq != NULL && (*melhor_esq).nota > (*melhor).nota) {
    melhor = melhor_esq;
  }

  if (melhor_dir != NULL && (*melhor_dir).nota > (*melhor).nota) {
    melhor = melhor_dir;
  }

  return melhor;
}

Aluno *get_aluno_pior_nota(ABP *raiz) {
  if (*raiz == NULL)
    return NULL;

  Aluno *pior_esq = get_aluno_pior_nota(&(*raiz)->esq);
  Aluno *pior_dir = get_aluno_pior_nota(&(*raiz)->dir);

  Aluno *pior = &(*raiz)->info;

  if (pior_esq != NULL && (*pior_esq).nota < (*pior).nota) {
    pior = pior_esq;
  }

  if (pior_dir != NULL && (*pior_dir).nota < (*pior).nota) {
    pior = pior_dir;
  }

  return pior;
}
