#include "Lista.h"

Lista *criaLista() {
  Lista *li;
  li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL)
    li->qtd = 0;
  return li;
}

void destroiLista(Lista *li) {
  if (li != NULL)
    free(li);
}

int tamanhoLista(Lista *li) {
  if (li == NULL)
    return -1;
  return li->qtd;
}

int listaCheia(Lista *li) {
  if (li == NULL)
    return -1;
  return (li->qtd == MAX);
}

int listaVazia(Lista *li) {
  if (li == NULL)
    return -1;
  return (li->qtd == 0);
}

int insereFim(Lista *li, int elem) {
  if (li == NULL)
    return 0;
  if (!listaCheia(li)) {
    li->dados[li->qtd] = elem;
    li->qtd++;
    return 1;
  } else {
    return 0;
  }
}

int insereIni(Lista *li, int elem) {
  if (li == NULL)
    return 0;
  if (!listaCheia(li)) {
    int i;
    for (i = li->qtd; i > 0; i--) {
      li->dados[i] = li->dados[i - 1];
    }
    li->dados[0] = elem;
    li->qtd++;
    return 1;
  } else {
    return 0;
  }
}

int imprimeLista(Lista *li) {
  if (li == NULL)
    return 0;
  int i;
  printf("Elementos:\n");
  for (i = 0; i < li->qtd; i++) {
    printf("%d ", li->dados[i]);
  }
  printf("\n");
  return 1;
}

int removeFim(Lista *li) {
  if (li == NULL)
    return 0;
  if (!listaVazia(li)) {
    li->qtd--;
    return 1;
  } else
    return 0;
}

int removeIni(Lista *li) {
  if (li == NULL)
    return 0;
  if (!listaVazia(li)) {
    int i;
    for (i = 0; i < li->qtd - 1; i++)
      li->dados[i] = li->dados[i + 1];
    li->qtd--;
    return 1;
  } else {
    return 0;
  }
}

int procura(Lista *li, int x) {
  if (li == NULL) {
    return -1;
  }

  for (int i = 0; i < li->qtd; i++) {
    if (li->dados[i] == x) {
      return i;
    }
  }

  return -1;
}

int insereOrdenado(Lista *li, int elem) {
  if (li == NULL || listaCheia(li)) {
    return 0;
  }

  int index = -1;

  for (int i = 0; i < li->qtd; i++) {
    if (li->dados[i] > elem) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    return insereFim(li, elem);
  }

  for (int i = li->qtd; i > index; i--) {
    li->dados[i] = li->dados[i - 1];
  }

  li->dados[index] = elem;
  li->qtd++;

  return 1;
}

int removeElemento(Lista *li, int elem) {
  if (li == NULL || listaVazia(li)) {
    return 0;
  }
  int index = -1;

  for (int i = 0; i < li->qtd; i++) {
    if (li->dados[i] == elem) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    return 0;
  }

  for (int i = index; i < li->qtd - 1; i++) {
    li->dados[i] = li->dados[i + 1];
  }

  li->qtd--;

  return 1;
}