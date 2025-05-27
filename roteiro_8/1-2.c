#include "ABP_aluno.h"

#define MAX_OPTIONS 12

enum options {
  CRIAR = 0,
  INSERIR,
  BUSCAR,
  REMOVER,
  MELHOR_ALUNO,
  PIOR_ALUNO,
  IMPRIMIR_ORDEM,
  IMPRIMIR_PRE_ORDEM,
  IMPRIMIR_POS_ORDEM,
  QUANTIDADE_NOS,
  DESTRUIR,
  SAIR,
};

int get_option() {
  int opt = -1;
  do {
    printf("\tOperacoes\n");
    printf("[%d] Criar árvore ABP, ", CRIAR);
    printf("[%d] Inserir um aluno, ", INSERIR);
    printf("[%d] Buscar um aluno, ", BUSCAR);
    printf("[%d] Remover um aluno, ", REMOVER);
    printf("[%d] Mostrar melhor aluno, ", MELHOR_ALUNO);
    printf("[%d] Mostrar pior aluno, ", PIOR_ALUNO);
    printf("[%d] Imprimir a ABP em ordem, ", IMPRIMIR_ORDEM);
    printf("[%d] Imprimir a ABP em pré-ordem, ", IMPRIMIR_PRE_ORDEM);
    printf("[%d] Imprimir a ABP em pós-ordem, ", IMPRIMIR_POS_ORDEM);
    printf("[%d] Mostrar a quantidade de nós na ABP, ", QUANTIDADE_NOS);
    printf("[%d] Destruir a ABP, ", DESTRUIR);
    printf("[%d] Sair do programa \n", SAIR);

    printf("\nInsira a opção desejada: ");
    scanf("%d", &opt);
    printf("\n");

    if (opt < 0 || opt >= MAX_OPTIONS) {
      printf("Opção escolhida inválida!\n");
    }

  } while (opt < 0 || opt >= MAX_OPTIONS);

  return opt;
}

int get_valor(char *msg) {
  int value;

  printf("%s", msg);
  scanf("%d", &value);

  return value;
}

int main() {
  int opt;

  ABP *arvore = NULL;

  do {
    opt = get_option();

    switch (opt) {
    case CRIAR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        arvore = criaABP();
      } else {
        destroiABP(arvore);
        arvore = NULL;
        arvore = criaABP();
      }

      printf("Árvore ABP criada com sucesso!\n");
      break;
    case INSERIR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      Aluno aluno;

      printf("Nome aluno:");
      scanf("%49s", aluno.nome);
      aluno.matricula = get_valor("Matricula: ");
      printf("Nota:");
      scanf("%lf", &aluno.nota);

      if (insereElem(arvore, aluno)) {
        printf("Aluno inserido na árvore com sucesso!\n");
      } else {
        printf("Falha ao inserir aluno!\n");
      }

      break;
    case BUSCAR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      Aluno aluno_search;

      printf("Insira o nome do aluno para busca:");
      scanf("%49s", aluno_search.nome);

      if (pesquisa(arvore, aluno_search)) {
        printf("aluno está presente na árvore ABP!\n");
      } else {
        printf("aluno não está presente na árvore ABP!\n");
      }

      break;
    case REMOVER:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      Aluno aluno_removal;

      printf("Insira o nome do aluno para remover:");
      scanf("%49s", aluno_removal.nome);

      if (removeElem(arvore, aluno_removal)) {
        printf("aluno removido com sucesso!\n");
      }

      break;
    case MELHOR_ALUNO:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      Aluno *aluno_temp = get_aluno_maior_nota(arvore);

      if (aluno_temp != NULL) {
        printf("O aluno com melhor nota é:\n");
        printf("Nome : %s Matricula: %d, Nota :%.2f\n", aluno_temp->nome,
               aluno_temp->matricula, aluno_temp->nota);
      } else {
        printf("Falha ao buscar melhor aluno\n");
      }

      break;
    case PIOR_ALUNO:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      Aluno *aluno_temp_2 = get_aluno_pior_nota(arvore);

      if (aluno_temp_2 != NULL) {
        printf("O aluno com pior nota é:\n");
        printf("Nome : %s Matricula: %d, Nota :%.2f\n", aluno_temp_2->nome,
               aluno_temp_2->matricula, aluno_temp_2->nota);
      } else {
        printf("Falha ao buscar pior aluno\n");
      }

      break;
    case IMPRIMIR_ORDEM:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      em_ordem(*arvore, 0);

      printf("Árvore imprimida com sucesso!\n");

      break;
    case IMPRIMIR_PRE_ORDEM:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      pre_ordem(*arvore, 0);

      printf("Árvore imprimida com sucesso!\n");

      break;
    case IMPRIMIR_POS_ORDEM:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      pos_ordem(*arvore, 0);

      printf("Árvore imprimida com sucesso!\n");

      break;
    case QUANTIDADE_NOS:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      int qtd_nos = get_quantidade_nos(arvore);

      printf("A quantidade de nós é %d\n", qtd_nos);

      break;
    case DESTRUIR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      destroiABP(arvore);
      arvore = NULL;

      printf("Árvore ABP destruida com sucesso!");

      break;
    case SAIR:
      if (arvore != NULL) {
        destroiABP(arvore);
        arvore = NULL;
      }

      printf("Finalizando programa! Até mais!\n");
      break;
    }
  } while (opt != SAIR);

  return 0;
}