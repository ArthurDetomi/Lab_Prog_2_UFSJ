#include <stdio.h>
#include <stdlib.h>

#define QTD_ALGORITMOS_TESTE 3

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

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void selectionSort(int *v, int n, int *comp, int *mov) {
  int i, j, maior;
  for (i = 0; i < n - 1; i++) {
    maior = i;
    for (j = i + 1; j < n; j++) {
      (*comp)++;
      if (v[j] > v[maior])
        maior = j;
    }
    if (i != maior) {
      troca(&v[i], &v[maior]);
      (*mov)++;
    }
  }
}

void insertionSort(int *v, int n, int *comp, int *mov) {
  int i, j, atual;
  for (i = 1; i < n; i++) {
    atual = v[i];
    (*comp)++;
    for (j = i; (j > 0) && (atual > v[j - 1]); j--) {
      v[j] = v[j - 1];
      (*comp)++;
      (*mov)++;
    }
    v[j] = atual;
  }
}

void BubbleSort(int *v, int n, int *comp, int *mov) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++) {
      (*comp)++;
      if (v[j] < v[j + 1]) {
        troca(&v[j], &v[j + 1]);
        (*mov)++;
      }
    }
}

int *copiaVetor(int *v, int n) {
  int i;
  int *v2;
  v2 = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
    v2[i] = v[i];
  return v2;
}

void liberar_vetor(int **v) {
  free(*v);
  *v = NULL;
}

enum algoritmos_para_teste { SELECION_SORT = 0, INSERTION_SORT, BUBLE_SORT };

int main() {
  int n;

  printf("Digite o tamanho do vetor:");
  scanf("%d", &n);

  int *array_original = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &array_original[i]);
  }

  printf("Agora a ordenação será decrescente:\n");
  for (int i = 0; i < QTD_ALGORITMOS_TESTE; i++) {
    int *array_copia = copiaVetor(array_original, n);

    int comp, mov;

    switch (i) {
    case SELECION_SORT:
      printf("Ordenando com Selecion Sort:\n");
      selectionSort(array_copia, n, &comp, &mov);
      imprimeVetor(array_copia, n);
      break;
    case INSERTION_SORT:
      printf("Ordenando com Insertion Sort:\n");
      insertionSort(array_copia, n, &comp, &mov);
      imprimeVetor(array_copia, n);
      break;
    case BUBLE_SORT:
      printf("Ordenando com Buble Sort:\n");
      BubbleSort(array_copia, n, &comp, &mov);
      imprimeVetor(array_copia, n);
      break;
    }

    liberar_vetor(&array_copia);
  }

  liberar_vetor(&array_original);
  return 0;
}