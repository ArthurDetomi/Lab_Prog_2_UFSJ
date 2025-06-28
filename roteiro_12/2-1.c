#include "Hash.h"

#include <math.h>

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

enum opcoes_func_hash { DIVISAO = 0, MULT, DOBRA };

#define QTD_OPCOES 3

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

  int (*funcoes_chave[])(int, int) = {&chaveDivisao, &chaveMultiplicacao,
                                      &chaveDobra};
  char *funcoes_nome[] = {"Divisão", "Multiplicação", "Dobra"};

  for (int fn_chave_idx = 0; fn_chave_idx < QTD_OPCOES; fn_chave_idx++) {
    const int INC = 3;

    Hash *hash_table = criaHash(n + INC);

    for (int j = 0; j < n; j++) {
      insereHash_EnderAberto(hash_table, array[j], funcoes_chave[fn_chave_idx],
                             LINEAR);
    }

    printf("-------------------------------------\n");
    printf("Função hash aplicada : %s\n", funcoes_nome[fn_chave_idx]);
    imprimeHash(hash_table);
    printf("-------------------------------------\n");

    destroiHash(hash_table);
  }

  liberar_vetor(&array);
  return 0;
}