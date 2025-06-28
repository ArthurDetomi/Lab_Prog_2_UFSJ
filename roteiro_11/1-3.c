#include <stdio.h>
#include <stdlib.h>

#include "tempo.h"

void liberar_vetor(int **v) {
  free(*v);
  *v = NULL;
}

int *copiaVetor(int *v, int n) {
  int i;
  int *v2 = (int *)malloc(n * sizeof(int));
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

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void shellSort(int *v, int n, int *comp, int *mov) {
  int i, j, atual;
  int h = 1;
  while (h < n)
    h = 3 * h + 1;
  while (h > 0) {
    for (i = h; i < n; i++) {
      atual = v[i];
      j = i;
      while (j > h - 1 && atual <= v[j - h]) {
        (*comp)++;
        (*mov)++;
        v[j] = v[j - h];
        j = j - h;
      }
      (*comp)++;
      v[j] = atual;
      (*mov)++;
    }
    h = h / 3;
  }
}

void criaHeap(int *v, int pai, int fim, int *comp, int *mov) {
  int aux = v[pai];
  int filho = 2 * pai + 1;
  while (filho <= fim) {
    if (filho < fim) {
      (*comp)++;
      if (v[filho] < v[filho + 1]) {
        filho++;
      }
    }
    (*comp)++;
    if (aux < v[filho]) {
      v[pai] = v[filho];
      (*mov)++;
      pai = filho;
      filho = 2 * pai + 1;
    } else {
      break;
    }
  }
  v[pai] = aux;
  (*mov)++;
}

void heapSort(int *v, int n, int *comp, int *mov) {
  for (int i = (n - 1) / 2; i >= 0; i--)
    criaHeap(v, i, n - 1, comp, mov);
  for (int i = n - 1; i >= 1; i--) {
    troca(&v[0], &v[i]);
    (*mov) += 2;
    criaHeap(v, 0, i - 1, comp, mov);
  }
}

int particao(int *v, int ini, int fim, int *comp, int *mov) {
  int i = ini, j = fim;
  int pivo = v[(ini + fim) / 2];
  while (1) {
    while (v[i] < pivo) {
      i++;
      (*comp)++;
    }

    while (v[j] > pivo) {
      j--;
      (*comp)++;
    }

    (*comp)++;
    if (i < j) {
      troca(&v[i], &v[j]);
      (*mov)++;
      i++;
      j--;
    } else {
      return j;
    }
  }
}

void quickSort(int *v, int ini, int fim, int *comp, int *mov) {
  if (ini < fim) {
    int q = particao(v, ini, fim, comp, mov);
    quickSort(v, ini, q, comp, mov);
    quickSort(v, q + 1, fim, comp, mov);
  }
}

void merge(int *v, int ini, int meio, int fim, int *comp, int *mov) {
  int tam = fim - ini + 1;
  int *A = (int *)malloc(tam * sizeof(int));
  int i = ini, j = meio + 1, k = 0;
  while (i <= meio && j <= fim) {
    (*comp)++;
    if (v[i] < v[j]) {
      A[k++] = v[i++];
      (*mov)++;
    } else {
      A[k++] = v[j++];
      (*mov)++;
    }
  }
  while (i <= meio) {
    A[k++] = v[i++];
    (*mov)++;
  }
  while (j <= fim) {
    A[k++] = v[j++];
    (*mov)++;
  }
  for (i = ini, k = 0; i <= fim; i++, k++) {
    v[i] = A[k];
    (*mov)++;
  }
  free(A);
}

void mergeSort(int *v, int ini, int fim, int *comp, int *mov) {
  if (ini < fim) {
    int meio = (ini + fim) / 2;
    mergeSort(v, ini, meio, comp, mov);
    mergeSort(v, meio + 1, fim, comp, mov);
    merge(v, ini, meio, fim, comp, mov);
  }
}

enum algoritmos_para_teste {
  SHELL_SORT = 0,
  QUICK_SORT,
  MERGE_SORT,
  HEAP_SORT
};

#define QTD_ALGORITMOS_TESTE 4

int main() {
  int n;
  printf("Digite o tamanho do vetor:");
  scanf("%d", &n);

  int *array_original = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &array_original[i]);
  }

  for (int i = 0; i < QTD_ALGORITMOS_TESTE; i++) {
    int *array_copia = copiaVetor(array_original, n);
    int comp = 0, mov = 0;

    Temporizador tempo_teste;
    iniciarTemporizador(&tempo_teste);

    switch (i) {
    case SHELL_SORT:
      printf("\nOrdenando com Shell Sort:\n");
      shellSort(array_copia, n, &comp, &mov);
      break;
    case QUICK_SORT:
      printf("\nOrdenando com Quick Sort:\n");
      quickSort(array_copia, 0, n - 1, &comp, &mov);
      break;
    case MERGE_SORT:
      printf("\nOrdenando com Merge Sort:\n");
      mergeSort(array_copia, 0, n - 1, &comp, &mov);
      break;
    case HEAP_SORT:
      printf("\nOrdenando com Heap Sort:\n");
      heapSort(array_copia, n, &comp, &mov);
      break;
    }

    finalizarTemporizador(&tempo_teste);

    imprimeVetor(array_copia, n);
    printf("Quantidade de movimentações realizadas: %d\n", mov);
    printf("Quantidade de comparações realizadas: %d\n", comp);
    imprimirTempos(&tempo_teste);
    printf("--------------------------------\n");

    liberar_vetor(&array_copia);
  }

  liberar_vetor(&array_original);
  return 0;
}
