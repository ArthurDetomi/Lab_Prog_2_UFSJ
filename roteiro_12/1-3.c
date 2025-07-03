#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int matricula;
} Aluno;

void liberar_vetor(Aluno **v) {
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

int comp;

void troca(Aluno *a, Aluno *b) {
  Aluno aux = *a;
  *a = *b;
  *b = aux;
}

int particao(Aluno *v, int ini, int fim, int (*compara)(Aluno *, Aluno *)) {
  int i = ini, j = fim;
  Aluno pivo = v[(ini + fim) / 2];
  while (1) {
    while (compara(&(v[i]), &pivo) < 0) {
      i++;
    }
    while (compara(&(v[j]), &pivo) > 0) {
      j--;
    }

    if (i < j) {
      troca(&v[i], &v[j]);
      i++;
      j--;
    } else
      return j;
  }
}

void QuickSort(Aluno *v, int ini, int fim, int (*compara)(Aluno *, Aluno *)) {
  if (ini < fim) {
    int q = particao(v, ini, fim, compara);
    QuickSort(v, ini, q, compara);
    QuickSort(v, q + 1, fim, compara);
  }
}

int rec_buscaBinaria(Aluno *v, int ini, int fim, Aluno elem,
                     int (*compara)(Aluno *, Aluno *)) {
  if (ini > fim)
    return -1;
  int meio = (ini + fim) / 2;
  comp++;
  if (compara(&(v[meio]), &elem) == 0)
    return meio;
  else if (compara(&(v[meio]), &elem) > 0)
    return rec_buscaBinaria(v, ini, meio - 1, elem, compara);
  else
    return rec_buscaBinaria(v, meio + 1, fim, elem, compara);
}

int comparaNome(Aluno *a, Aluno *b) { return strcmp(a->nome, b->nome); }

int comparaMatricula(Aluno *a, Aluno *b) { return a->matricula - b->matricula; }

void print_aluno(const Aluno *aluno) {
  printf("--------------------\n");
  printf("Aluno Info:\n");
  printf("Nome: %s\n", aluno->nome);
  printf("Matricula: %d\n", aluno->matricula);
  printf("--------------------\n");
}

int main() {
  int n;

  printf("Digite a quantidade de alunos:\n");
  scanf("%d", &n);

  Aluno *alunos = malloc(n * sizeof(Aluno));

  printf("Cadastro de alunos:\n");
  for (int i = 0; i < n; i++) {
    printf("Nome:\n");
    scanf("%s", alunos[i].nome);
    printf("Matricula:\n");
    scanf("%d", &alunos[i].matricula);
  }

  Aluno al_busca;
  printf("Digite um nome de um aluno para busca:\n");
  scanf("%s", al_busca.nome);

  printf("Nome de aluno buscado : %s\n", al_busca.nome);

  QuickSort(alunos, 0, n - 1, comparaNome);

  printf("Lista de alunos cadastrados:\n");
  for (int i = 0; i < n; i++) {
    printf("{%s, %d}, ", alunos[i].nome, alunos[i].matricula);
  }
  printf("\n");

  int index = rec_buscaBinaria(alunos, 0, n - 1, al_busca, comparaNome);

  if (index != -1) {
    printf("----- Sucesso ! --------\n");
    printf("Aluno encontrado\n");
    print_aluno(&alunos[index]);
    printf("--------------------\n");
  } else {
    printf("----- Not Found --------\n");
    printf("Aluno não encontrado\n");
    printf("--------------------\n");
  }

  printf("Digite uma matricula para busca:\n");
  scanf("%d", &al_busca.matricula);

  QuickSort(alunos, 0, n - 1, comparaMatricula);

  printf("Matricula buscada : %d\n", al_busca.matricula);

  index = rec_buscaBinaria(alunos, 0, n - 1, al_busca, comparaMatricula);

  if (index != -1) {
    printf("----- Sucesso ! --------\n");
    printf("Aluno encontrado\n");
    print_aluno(&alunos[index]);
    printf("--------------------\n");

  } else {
    printf("----- Not Found --------\n");
    printf("Aluno não encontrado\n");
    printf("--------------------\n");
  }

  liberar_vetor(&alunos);

  return 0;
}