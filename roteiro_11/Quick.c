/*---------------- File: Quick.c  ----------------------+
|Quick Sort                                             |
| | | | | Implementado por Guilherme C. Pena em 14/11/2023      |
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

// Versao do livro
int particiona(int *v, int ini, int fim) {
  int esq, dir, pivo, aux;
  esq = ini;
  dir = fim;
  pivo = v[ini];
  while (esq < dir) {
    while (esq <= fim && v[esq] <= pivo)
      esq++;
    while (dir >= 0 && v[dir] > pivo)
      dir--;
    if (esq < dir)
      troca(&v[esq], &v[dir]);
  }
  v[ini] = v[dir];
  v[dir] = pivo;
  return dir;
}

int particao(int *v, int ini, int fim) {
  int i = ini, j = fim;
  int pivo = v[(ini + fim) / 2];
  while (1) {
    comp++;
    while (v[i] < pivo) {
      i++;
      comp++;
    } // procura algum >= pivo do lado esquerdo

    comp++;
    while (v[j] > pivo) {
      j--;
      comp++;
    } // procura algum <= pivo do lado direito

    if (i < j) {
      troca(&v[i], &v[j]); // troca os elementos encontrados
      mov++;
      i++;
      j--;
    } else
      return j; // retorna o local onde foi feita a particao
  }
}

void quickSort(int *v, int ini, int fim, int n) {
  if (ini < fim) {
    int q = particao(v, ini, fim);
    // printf("Parts: (%d, %d) e (%d, %d): ", ini, q, q+1, fim);
    // imprimeVetor(v, n);
    quickSort(v, ini, q, n);
    quickSort(v, q + 1, fim, n);
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
  quickSort(v, 0, n - 1, n);
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