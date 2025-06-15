#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_ALGORITMOS_TESTE 2

enum algoritmos_para_teste { SELECION_SORT = 0, INSERTION_SORT };

enum ordens_ordenacao { CRESCENTE = 'c', DECRESCENTE = 'd' };

typedef struct Pessoa {
  char nome[50];
  int idade;
} Pessoa;

void imprimeVetor(Pessoa *v, int n) {
  for (int i = 0; i < n; i++) {
    printf("%s (%d)\n", v[i].nome, v[i].idade);
  }
}

void troca(Pessoa *a, Pessoa *b) {
  Pessoa aux = *a;
  *a = *b;
  *b = aux;
}

int comparaCrescente(Pessoa p1, Pessoa p2) {
  int comparacao = strcmp(p1.nome, p2.nome);
  if (comparacao == 0) {
    return p1.idade - p2.idade;
  }
  return comparacao;
}

int comparaDecrescente(Pessoa p1, Pessoa p2) {
  int comparacao = strcmp(p2.nome, p1.nome);
  if (comparacao == 0) {
    return p2.idade - p1.idade;
  }
  return comparacao;
}

int comparaPorOrdem(Pessoa p1, Pessoa p2, char ordem) {
  if (ordem == CRESCENTE) {
    return comparaCrescente(p1, p2);
  }
  return comparaDecrescente(p1, p2);
}

void selectionSort(Pessoa *v, int n, int *comp, int *mov, char ordem) {
  int i, j, menor;
  for (i = 0; i < n - 1; i++) {
    menor = i;
    for (j = i + 1; j < n; j++) {
      (*comp)++;
      if (comparaPorOrdem(v[j], v[menor], ordem) < 0) {
        menor = j;
      }
    }
    if (i != menor) {
      troca(&v[i], &v[menor]);
      (*mov)++;
    }
  }
}

void insertionSort(Pessoa *v, int n, int *comp, int *mov, char ordem) {
  int i, j;
  for (i = 1; i < n; i++) {
    Pessoa atual = v[i];
    (*comp)++;
    for (j = i; (j > 0) && comparaPorOrdem(atual, v[j - 1], ordem) < 0; j--) {
      v[j] = v[j - 1];
      (*comp)++;
      (*mov)++;
    }
    v[j] = atual;
  }
}

Pessoa *copiaVetor(Pessoa *v, int n) {
  int i;
  Pessoa *v2;
  v2 = (Pessoa *)malloc(n * sizeof(Pessoa));
  for (i = 0; i < n; i++) {
    strcpy(v2[i].nome, v[i].nome);
    v2[i].idade = v[i].idade;
  }
  return v2;
}

void liberar_vetor(Pessoa **v) {
  free(*v);
  *v = NULL;
}

int main() {
  int n;

  printf("Digite o tamanho do vetor:");
  scanf("%d", &n);

  char ordem;
  printf("Digite a ordem de ordenação (c) crescente (d) decrescente:");
  scanf(" %c", &ordem);

  if (ordem != CRESCENTE && ordem != DECRESCENTE) {
    printf("Ordem inserida invalida\n");
    exit(1);
  }

  Pessoa *array_original = (Pessoa *)malloc(n * sizeof(Pessoa));

  for (int i = 0; i < n; i++) {
    printf("Cadastro pessoa %d:\n", i + 1);
    printf("Nome: ");
    scanf("%s", array_original[i].nome);
    printf("Idade: ");
    scanf("%d", &array_original[i].idade);
  }

  for (int i = 0; i < QTD_ALGORITMOS_TESTE; i++) {
    Pessoa *array_copia = copiaVetor(array_original, n);

    int comp = 0, mov = 0;

    switch (i) {
    case SELECION_SORT:
      printf("Ordenando com Selecion Sort:\n");
      selectionSort(array_copia, n, &comp, &mov, ordem);
      imprimeVetor(array_copia, n);
      break;
    case INSERTION_SORT:
      printf("Ordenando com Insertion Sort:\n");
      insertionSort(array_copia, n, &comp, &mov, ordem);
      imprimeVetor(array_copia, n);
      break;
    }

    liberar_vetor(&array_copia);
  }

  liberar_vetor(&array_original);
  return 0;
}