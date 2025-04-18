#include "LDE.h"

Lista *criaLista() {
  Lista *li;
  li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL) {
    *li = NULL;
  }
  return li;
}

int listaVazia(Lista *li) {
  if (li == NULL)
    return 1;
  if (*li == NULL)
    return 1; // True - Vazia!
  return 0;   // False - tem elemento!
}

NO *alocarNO() { return (NO *)malloc(sizeof(NO)); }

void liberarNO(NO *q) { free(q); }

int insereIni(Lista *li, int elem) {
  if (li == NULL)
    return 0;
  NO *novo = alocarNO();
  if (novo == NULL)
    return 0;
  novo->info = elem;
  novo->prox = *li;
  novo->ant = NULL;
  if (!listaVazia(li))
    (*li)->ant = novo;
  *li = novo;
  return 1;
}

int insereFim(Lista *li, int elem) {
  if (li == NULL)
    return 0;
  NO *novo = alocarNO();
  if (novo == NULL)
    return 0;
  novo->info = elem;
  novo->prox = NULL;
  if (listaVazia(li)) {
    novo->ant = NULL;
    *li = novo;
  } else {
    NO *aux = *li;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = novo;
    novo->ant = aux;
  }
  return 1;
}

int removeIni(Lista *li) {
  if (li == NULL)
    return 0;
  if (listaVazia(li))
    return 0;
  NO *aux = *li;
  *li = aux->prox;
  if (aux->prox != NULL)
    aux->prox->ant = NULL;
  liberarNO(aux);
  return 1;
}

int removeFim(Lista *li) {
  if (li == NULL)
    return 0;
  if (listaVazia(li))
    return 0;
  NO *aux = *li;
  while (aux->prox != NULL)
    aux = aux->prox;
  if (aux->ant == NULL)
    *li = aux->prox;
  else
    aux->ant->prox = NULL;
  liberarNO(aux);
  return 1;
}

void imprimeLista(Lista *li) {
  if (li == NULL)
    return;
  if (listaVazia(li)) {
    printf("Lista Vazia!\n");
    return;
  }
  printf("Elementos:\n");
  NO *aux = *li;
  while (aux != NULL) {
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
}

void destroiLista(Lista *li) {
  if (li != NULL) {
    NO *aux;
    while ((*li) != NULL) {
      aux = *li;
      *li = (*li)->prox;
      // printf("Destruindo.. %d\n", aux->info);
      liberarNO(aux);
    }
    free(li);
  }
}

int procura(Lista *li, int elem) {
  if (li == NULL || listaVazia(li)) {
    return 0;
  }

  NO *aux = *li;

  while (aux != NULL) {
    if (aux->info == elem) {
      return 1;
    }

    aux = aux->prox;
  }

  return 0;
}

int tamanho(Lista *li) {
  if (li == NULL || listaVazia(li)) {
    return 0;
  }
  int tamanho = 0;

  NO *aux = *li;

  while (aux != NULL) {
    tamanho++;

    aux = aux->prox;
  }

  return tamanho;
}

int insereOrdenado(Lista *li, int elem) {
  if (li == NULL) {
    return 0;
  }

  NO *atual = *li;

  while (atual != NULL && atual->info < elem) {
    atual = atual->prox;
  }

  if (atual == NULL) {
    return insereFim(li, elem);
  }

  NO *anterior = atual->ant;

  if (anterior == NULL) {
    return insereIni(li, elem);
  }

  NO *novo_no = alocarNO();

  novo_no->info = elem;
  novo_no->prox = atual;
  novo_no->ant = anterior;

  atual->ant = novo_no;

  anterior->prox = novo_no;

  return 1;
}

int removeCasoExista(Lista *li, int elem) {
  if (li == NULL || listaVazia(li)) {
    return 0;
  }

  NO *atual = *li;

  while (atual != NULL && atual->info != elem) {
    atual = atual->prox;
  }

  if (atual == NULL) {
    return 0;
  }

  NO *anterior = atual->ant, *proximo = atual->prox;

  if (anterior == NULL) {
    return removeIni(li);
  }

  if (proximo == NULL) {
    return removeFim(li);
  }

  proximo->ant = anterior;
  anterior->prox = proximo;

  liberarNO(atual);

  return 1;
}
