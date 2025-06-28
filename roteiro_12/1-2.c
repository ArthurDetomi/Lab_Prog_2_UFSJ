#include "tempo.h"

#include <stdio.h>
#include <stdlib.h>

void liberar_vetor(int **v) {
  free(*v);
  *v = NULL;
}

int *copiaVetor(int *v, int n) {
  int i;
  int *v2;
  v2 = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    v2[i] = v[i];
  return v2;
}

void imprimeVetor(int *v, int n) {
  int i, prim = 1;
  printf("[");
  for (i = 0; i < n; i++)
    if (prim) {
      printf("%d", v[i]);
      prim = 0;
    } else
      printf(", %d", v[i]);
  printf("]\n");
}

int buscaSequencial(int *v, int n, int elem, int *comp) {
  int i;
  for (i = 0; i < n; i++) {
    (*comp)++;
    if (v[i] == elem)
      return i; // Elemento encontrado
  }
  return -1; // Elemento encontrado
}

int it_buscaBinaria(int *v, int ini, int fim, int elem, int *comp) {
  int meio;
  while (ini <= fim) {
    meio = (ini + fim) / 2;
    (*comp)++;
    if (elem == v[meio])
      return meio;
    else if (elem < v[meio])
      ini = meio + 1;
    else
      fim = meio - 1;
  }
  return -1;
}

int rec_buscaBinaria(int *v, int ini, int fim, int elem, int *comp) {
  if (ini > fim)
    return -1;
  int meio = (ini + fim) / 2;
  (*comp)++;
  if (v[meio] == elem)
    return meio;
  else if (elem < v[meio])
    return rec_buscaBinaria(v, meio + 1, fim, elem, comp);
  else
    return rec_buscaBinaria(v, ini, meio - 1, elem, comp);
}

int compara_decrescente(const void *a, const void *b) {
  int x = *(int *)a;
  int y = *(int *)b;

  if (x < y)
    return 1;
  if (x > y)
    return -1;

  return 0;
}

enum algoritmos_para_teste {
  PESQUISA_SEQUENCIAL = 0,
  PESQUISA_BINARIA,
};

#define QTD_ALGORITMOS_TESTE 2

int main() {
  int n;

  printf("Digite o tamanho do vetor:");
  scanf("%d", &n);

  int *array_original = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &array_original[i]);
  }

  qsort(array_original, n, sizeof(int), compara_decrescente);

  int value;
  printf("Digite um valor para buscar no vetor:\n");
  scanf("%d", &value);

  printf("Vetor final da busca:\n");
  imprimeVetor(array_original, n);

  for (int i = 0; i < QTD_ALGORITMOS_TESTE; i++) {
    int comp = 0, index;

    Temporizador tempo_teste;
    iniciarTemporizador(&tempo_teste);

    switch (i) {
    case PESQUISA_SEQUENCIAL:

      index = buscaSequencial(array_original, n, value, &comp);

      if (index != -1) {
        printf("Elemento encontrado no indice %d\n", index);
      } else {
        printf("Elemento não encontrado\n");
      }

      break;
    case PESQUISA_BINARIA:
      index = it_buscaBinaria(array_original, 0, n - 1, value, &comp);

      if (index != -1) {
        printf("Elemento encontrado no indice %d\n", index);
      } else {
        printf("Elemento não encontrado\n");
      }

      break;
    }

    finalizarTemporizador(&tempo_teste);
    printf("Quantidade de comparações realizadas: %d\n", comp);
    imprimirTempos(&tempo_teste);
    printf("--------------------------------\n");
  }

  liberar_vetor(&array_original);
  return 0;

  return 0;
}