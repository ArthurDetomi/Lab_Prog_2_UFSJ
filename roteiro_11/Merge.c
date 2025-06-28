/*---------------- File: Merge.c  ----------------------+
|Merge Sort                                             |
| | | | | Implementado por Guilherme C. Pena em 08/11/2023      |
+-------------------------------------------------------+ */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Medidas de Complexidade
int comp; // Num. de comparacoes
int mov;  // Num. de movimentacoes

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

void preencheAleatorio(int *v, int n, int ini, int fim) {
  int i;
  for (i = 0; i < n; i++)
    v[i] = ini + rand() % (fim - ini + 1);
}

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void merge(int *v, int ini, int meio, int fim) {
  int tam = fim - ini + 1;
  // Vetor Auxiliar - A
  int *A = (int *)malloc(tam * sizeof(int));
  int i = ini, j = meio + 1, k = 0;
  while (i <= meio && j <= fim) {
    if (v[i] < v[j]) {
      A[k] = v[i];
      i++;
    } else {
      A[k] = v[j];
      j++;
    }
    k++;
  }
  while (i <= meio) {
    A[k] = v[i];
    i++;
    k++;
  }
  while (j <= fim) {
    A[k] = v[j];
    j++;
    k++;
  }
  for (i = ini, k = 0; i <= fim; i++, k++)
    v[i] = A[k];
  free(A);
}

void mergeSort(int *v, int ini, int fim) {
  if (ini < fim) {
    int meio = (ini + fim) / 2;
    mergeSort(v, ini, meio);
    mergeSort(v, meio + 1, fim);
    merge(v, ini, meio, fim);
  }
}

int main() {

  // Atribuicoes iniciais
  srand(time(NULL));
  comp = 0;
  mov = 0;
  clock_t t;

  /*
  //Template de Calculo do Tempo de Execucao
  t = clock();
  //Chamada do Algoritmo aqui...
  t = clock() - t;
  printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
  */

  int *v;
  int n;
  printf("Digite o tamanho do vetor:\n");
  scanf("%d", &n);
  v = (int *)malloc(n * sizeof(int));

  preencheAleatorio(v, n, 1, 100);
  imprimeVetor(v, n);

  t = clock();
  mergeSort(v, 0, n - 1);
  t = clock() - t;
  printf("-----Informacoes:\n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);
  printf("Memoria (bytes): %d\n", n * sizeof(int));

  imprimeVetor(v, n);

  free(v);
  return 0;
}