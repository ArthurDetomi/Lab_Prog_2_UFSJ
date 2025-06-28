/*---------------- File: Quick.c  ----------------------+
|Heap Sort                                             |
| | | | | Implementado por Guilherme C. Pena em 18/11/2023      |
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
  for (i = 0; i < n; i++) {
    v[i] = ini + rand() % (fim - ini + 1);
    // v[i] = (n-i); //Para o pior caso
  }
}

void troca(int *a, int *b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}

void criaHeap(int *v, int pai, int fim) {
  int aux = v[pai];
  int filho = 2 * pai + 1;
  while (filho <= fim) {
    if (filho < fim)
      if (v[filho] < v[filho + 1])
        filho++;
    if (aux < v[filho]) {
      v[pai] = v[filho];
      pai = filho;
      filho = 2 * pai + 1;
    } else
      filho = fim + 1;
  }
  v[pai] = aux;
}

void heapSort(int *v, int n) {
  int i;
  for (i = (n - 1) / 2; i >= 0; i--)
    criaHeap(v, i, n - 1);
  for (i = n - 1; i >= 1; i--) {
    troca(&v[0], &v[i]);
    criaHeap(v, 0, i - 1);
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
  heapSort(v, n);
  t = clock() - t;
  printf("-----Informacoes:\n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t) / CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);
  printf("Memoria (bytes): %ld\n", n * sizeof(int));

  imprimeVetor(v, n);

  free(v);
  return 0;
}