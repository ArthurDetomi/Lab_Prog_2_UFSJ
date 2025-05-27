#include "ABP.h"

#define MAX_OPTIONS 10

enum options {
  CRIAR = 0,
  INSERIR,
  BUSCAR,
  REMOVER,
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
    printf("[%d] Inserir um elemento, ", INSERIR);
    printf("[%d] Buscar um elemento, ", BUSCAR);
    printf("[%d] Remover um elemento, ", REMOVER);
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
  int opt, valor;

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

      valor = get_valor("Insira um valor: ");

      if (insereElem(arvore, valor)) {
        printf("Elemento inserido na árvore com sucesso!\n");
      } else {
        printf("Falha ao inserir elemento!\n");
      }

      break;
    case BUSCAR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      valor = get_valor("Insira o valor para buscar: ");

      if (pesquisa(arvore, valor)) {
        printf("Elemento está presente na árvore ABP!\n");
      } else {
        printf("Elemento não está presente na árvore ABP!\n");
      }

      break;
    case REMOVER:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore ABP não incializada impossível realizar operação..\n");
        break;
      }

      valor = get_valor("Elemento a se remover: ");

      if (removeElem(arvore, valor)) {
        printf("Elemento removido com sucesso!\n");
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