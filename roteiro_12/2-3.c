#include "HashLSE.h"

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

int main() {
  int n;

  printf("Digite o tamanho do vetor:");
  scanf("%d", &n);

  int *array = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  printf("-------------------------------------\n");
  imprimeVetor(array, n);
  printf("-------------------------------------\n");

  Hash *hash_table = criaHash(n);
  for (int i = 0; i < n; i++) {
    insereHashLSE(hash_table, array[i]);
  }

  printf("--------- Mostrando Tabela --------\n");
  imprimeHash(hash_table);
  printf("-------------------------------------\n");

  liberar_vetor(&array);
  return 0;
}