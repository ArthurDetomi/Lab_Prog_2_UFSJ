#include "./deque_s_estatico.h"

#define MAX_OPTIONS 10

enum options {
  CRIAR_FILA = 0,
  INSERIR_ITEM,
  INSERIR_INICIO,
  SHOW_INICIO,
  SHOW_FIM,
  REMOVER_ITEM,
  REMOVER_INICIO,
  IMPRIMIR,
  DESTRUIR,
  SAIR,
};

int get_option() {
  int opt = -1;
  do {
    printf("\tOperacoes\n");
    printf("[%d] Criar deque, ", CRIAR_FILA);
    printf("[%d] Inserir no fim, ", INSERIR_ITEM);
    printf("[%d] Inserir no inicio, ", INSERIR_INICIO);
    printf("[%d] Ver o inicio do deque, ", SHOW_INICIO);
    printf("[%d] Ver o fim do deque, ", SHOW_FIM);
    printf("\n[%d] Remover do fim do deque, ", REMOVER_ITEM);
    printf("[%d] Remover do inicio do deque, ", REMOVER_INICIO);
    printf("[%d] Imprimir deque, ", IMPRIMIR);
    printf("[%d] Destruir deque, ", DESTRUIR);
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

int get_valor() {
  int value;

  printf("Digite o valor a inserir:");
  scanf("%d", &value);

  return value;
}

int main() {
  int opt, valor;

  Deque *deque = NULL;

  do {
    opt = get_option();

    switch (opt) {
    case CRIAR_FILA:
      printf("Executando comando...\n");

      if (deque == NULL) {
        deque = criaDeque();
      } else {
        destroiDeque(&deque);
        deque = NULL;
        deque = criaDeque();
      }

      printf("Deque criado com sucesso!\n");
      break;
    case INSERIR_ITEM:
      printf("Executando comando...\n");

      if (deque == NULL) {
        printf("Deque não instanciado impossivel realizar operação..\n");
        break;
      }

      if (!insereFim(deque, get_valor())) {
        printf("Falha ao inserir no fim do deque!\n");
      }

      printf("Valor inserido com sucesso\n");

      break;

    case INSERIR_INICIO:
      printf("Executando comando...\n");

      if (deque == NULL) {
        printf("Deque não instanciado impossivel realizar operação..\n");
        break;
      }

      if (!insereInicio(deque, get_valor())) {
        printf("Falha ao inserir no inicio do deque!\n");
      }

      printf("Valor inserido com sucesso!\n");

      break;
    case SHOW_INICIO:
      printf("Executando comando...\n");

      if (deque == NULL) {
        printf("Deque não instanciado impossivel realizar operação..\n");
        break;
      }

      if (!verInicio(deque, &valor)) {
        printf("Erro ao ver inicio do deque\n");
        break;
      }

      printf("Valor de inicio = %d\n", valor);
      break;
    case SHOW_FIM:
      printf("Executando comando...\n");

      if (deque == NULL) {
        printf("Deque não instanciado impossivel realizar operação..\n");
        break;
      }

      if (!verFim(deque, &valor)) {
        printf("Erro ao ver fim do deque\n");
        break;
      }

      printf("Valor do fim do deque = %d\n", valor);
      break;
    case REMOVER_ITEM:
      printf("Executando comando...\n");

      if (deque == NULL) {
        printf("Deque não instanciado impossivel realizar operação..\n");
        break;
      }

      if (!removeFim(deque)) {
        printf("Erro ao executar comando\n");
      }

      printf("Removido item do fim do deque com sucesso!\n");

      break;
    case REMOVER_INICIO:
      printf("Executando comando...\n");

      if (deque == NULL) {
        printf("Deque não instanciado impossivel realizar operação..\n");
        break;
      }

      if (!removeInicio(deque)) {
        printf("Erro ao executar comando\n");
      }

      printf("Removido item do inicio do deque com sucesso!\n");

      break;
    case IMPRIMIR:
      printf("Executando comando...\n");

      if (deque == NULL) {
        printf("Deque não instanciado impossivel realizar operação..\n");
        break;
      }

      imprime(deque);

      break;
    case DESTRUIR:
      printf("Executando comando...\n");

      destroiDeque(&deque);
      deque = NULL;

      printf("Deque destruido com sucesso!\n");

      break;
    case SAIR:
      printf("Finalizando programa! Até mais!\n");
      break;
    }

  } while (opt != SAIR);

  return 0;
}