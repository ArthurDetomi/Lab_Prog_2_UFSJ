#include "./fila_priori_heap.h"

#define MAX_OPTIONS 8

enum options {
  CRIAR_FILA = 0,
  INSERIR_ITEM,
  SHOW_INICIO,
  REMOVER_ITEM,
  IMPRIMIR,
  SHOW_TAMANHO,
  DESTRUIR,
  SAIR,
};

int get_option() {
  int opt = -1;
  do {
    printf("\tOperacoes\n");
    printf("[%d] Criar fila, ", CRIAR_FILA);
    printf("[%d] Inserir um item pela prioridade, ", INSERIR_ITEM);
    printf("[%d] Ver o inı́cio da Fila, ", SHOW_INICIO);
    printf("[%d] Remover um item, \n", REMOVER_ITEM);
    printf("[%d] Imprimir a Fila, ", IMPRIMIR);
    printf("[%d] Mostrar o tamanho da Fila, ", SHOW_TAMANHO);
    printf("[%d] Destruir a Fila, ", DESTRUIR);
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

  printf("%s\n", msg);
  scanf("%d", &value);

  return value;
}

int main() {
  int opt, valor, priori;

  FilaP *fila_priori = NULL;

  do {
    opt = get_option();

    switch (opt) {
    case CRIAR_FILA:
      printf("Executando comando...\n");

      if (fila_priori == NULL) {
        fila_priori = criaFila();
      } else {
        destroiFila(&fila_priori);
        fila_priori = NULL;
        fila_priori = criaFila();
      }

      printf("Fila de prioridade criada com sucesso!\n");
      break;
    case INSERIR_ITEM:
      printf("Executando comando...\n");

      if (fila_priori == NULL) {
        printf("Fila de prioridade não instanciado impossivel realizar "
               "operação..\n");
        break;
      }

      if (!inserirPrio(fila_priori, get_valor("Valor a inserir:"),
                       get_valor("Insira a prioridade: "))) {
        printf("Falha ao inserir na Fila de prioridade!\n");
      }

      printf("Item inserido com sucesso\n");

      break;

    case SHOW_INICIO:
      printf("Executando comando...\n");

      if (fila_priori == NULL) {
        printf("Fila de prioridade não instanciado impossivel realizar "
               "operação..\n");
        break;
      }

      if (!verInicio(fila_priori, &valor, &priori)) {
        printf("Erro ao ver inicio do Fila de prioridade\n");
        break;
      }

      printf("Item [valor = %d, prioridade = %d]\n", valor, priori);
      break;

    case REMOVER_ITEM:
      printf("Executando comando...\n");

      if (fila_priori == NULL) {
        printf("Fila de prioridade não instanciado impossivel realizar "
               "operação..\n");
        break;
      }

      if (!removeInicio(fila_priori)) {
        printf("Erro ao executar comando\n");
      }

      printf("Removido primeiro item da Fila de prioridade com sucesso!\n");

      break;

    case IMPRIMIR:
      printf("Executando comando...\n");

      if (fila_priori == NULL) {
        printf("Fila de prioridade não instanciado impossivel realizar "
               "operação..\n");
        break;
      }

      imprime(fila_priori);

      break;
    case SHOW_TAMANHO:
      printf("Executando comando...\n");

      if (fila_priori == NULL) {
        printf("Fila de prioridade não instanciado impossivel realizar "
               "operação..\n");
        break;
      }

      printf("Tamanho da fila = %d\n", tamanhoFila(fila_priori));

      break;

    case DESTRUIR:
      printf("Executando comando...\n");

      destroiFila(&fila_priori);
      fila_priori = NULL;

      printf("Fila de prioridade destruida com sucesso!\n");

      break;
    case SAIR:
      printf("Finalizando programa! Até mais!\n");
      break;
    }

  } while (opt != SAIR);

  return 0;
}