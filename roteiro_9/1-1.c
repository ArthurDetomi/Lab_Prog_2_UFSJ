#include "AVL.h"

#define MAX_OPTIONS 8

enum options {
  CRIAR = 0,
  INSERIR,
  BUSCAR,
  REMOVER,
  IMPRIMIR_ORDEM,
  QUANTIDADE_NOS,
  DESTRUIR,
  SAIR,
};

int get_option() {
  int opt = -1;
  do {
    printf("\tOperacoes\n");
    printf("[%d] Criar AVL, ", CRIAR);
    printf("[%d] Inserir um elemento, ", INSERIR);
    printf("[%d] Buscar um elemento, ", BUSCAR);
    printf("[%d] Remover um elemento, ", REMOVER);
    printf("[%d] Imprimir a AVL em ordem, ", IMPRIMIR_ORDEM);
    printf("[%d] Mostrar a quantidade de nós na AVL, ", QUANTIDADE_NOS);
    printf("[%d] Destruir a AVL, ", DESTRUIR);
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

  AVL *arvore = NULL;

  do {
    opt = get_option();

    switch (opt) {
    case CRIAR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        arvore = criaAVL();
      } else {
        destroiAVL(arvore);
        arvore = NULL;
        arvore = criaAVL();
      }

      printf("Árvore AVL criada com sucesso!\n");
      break;
    case INSERIR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore AVL não incializada impossível realizar operação..\n");
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
        printf("Árvore AVL não incializada impossível realizar operação..\n");
        break;
      }

      valor = get_valor("Insira o valor para buscar: ");

      if (pesquisa(arvore, valor)) {
        printf("Elemento está presente na árvore AVL!\n");
      } else {
        printf("Elemento não está presente na árvore AVL!\n");
      }

      break;
    case REMOVER:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore AVL não incializada impossível realizar operação..\n");
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
        printf("Árvore AVL não incializada impossível realizar operação..\n");
        break;
      }

      em_ordem(*arvore, 0);

      printf("Árvore imprimida com sucesso!\n");

      break;
    case QUANTIDADE_NOS:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore AVL não incializada impossível realizar operação..\n");
        break;
      }

      int qtd_nos = get_quantidade_nos(arvore);

      printf("A quantidade de nós é %d\n", qtd_nos);

      break;
    case DESTRUIR:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore AVL não incializada impossível realizar operação..\n");
        break;
      }

      destroiAVL(arvore);
      arvore = NULL;

      printf("Árvore AVL destruida com sucesso!");

      break;
    case SAIR:
      if (arvore != NULL) {
        destroiAVL(arvore);
        arvore = NULL;
      }

      printf("Finalizando programa! Até mais!\n");
      break;
    }
  } while (opt != SAIR);

  return 0;
}