#include "./matriz_faixa.h"

#define MAX_OPTIONS 9

enum options {
  CRIAR = 0,
  PREENCHER,
  ZERAR,
  INSERIR,
  CONSULTAR,
  IMPRIMIR,
  IMPRIMIR_VETORES,
  DESTRUIR,
  SAIR,
};

int get_option() {
  int opt = -1;
  do {
    printf("\tOperacoes\n");
    printf("[%d] Criar matriz, ", CRIAR);
    printf("[%d] Preencher aleatoriamente, ", PREENCHER);
    printf("[%d] Zerar matriz, ", ZERAR);
    printf("[%d] Inserir elemento, ", INSERIR);
    printf("[%d] Consultar elemento, ", CONSULTAR);
    printf("[%d] Imprimir matriz, ", IMPRIMIR);
    printf("[%d] Imprimir faixa de vetores matriz, ", IMPRIMIR_VETORES);
    printf("[%d] Destruir matriz, ", DESTRUIR);
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
  int opt, valor, linha, coluna;

  Matriz *matrix = NULL;

  do {
    opt = get_option();

    switch (opt) {
    case CRIAR:
      printf("Executando comando...\n");

      printf("Insira as dimensões da matriz faixa:\n");
      linha = get_valor("Diagonal: ");

      if (matrix == NULL) {
        matrix = criaMatriz(linha);
      } else {
        destroiMatriz(&matrix);
        matrix = NULL;
        matrix = criaMatriz(linha);
      }

      printf("Matriz criada com sucesso!\n");
      break;
    case PREENCHER:
      printf("Executando comando...\n");

      if (matrix == NULL) {
        printf("Matriz não incializada impossível realizar operação..\n");
        break;
      }

      printf("Insira os limites dos valores a serem preenchidos\n");

      int min, max;

      min = get_valor("Min: ");
      max = get_valor("Max: ");

      preencheAleatorio(matrix, min, max);

      printf("Matriz preenchida com sucesso!\n");

      break;
    case ZERAR:
      printf("Executando comando...\n");

      if (matrix == NULL) {
        printf("Matriz não incializada impossível realizar operação..\n");
        break;
      }

      zeraMatriz(matrix);

      printf("Matriz zerada com sucesso!\n");

      break;
    case INSERIR:
      printf("Executando comando...\n");

      if (matrix == NULL) {
        printf("Matriz não incializada impossível realizar operação..\n");
        break;
      }

      printf("Insira a posição para inserir o elemento na matriz:\n");

      linha = get_valor("Linha :");
      coluna = get_valor("Coluna :");
      valor = get_valor("Valor :");

      if (insereElem(matrix, valor, linha, coluna)) {
        printf("Valor inserido com sucesso!\n");
      }

      break;
    case CONSULTAR:
      printf("Executando comando...\n");

      if (matrix == NULL) {
        printf("Matriz não incializada impossível realizar operação..\n");
        break;
      }

      printf("Insira a posição do elemento a ser consultado:\n");

      linha = get_valor("Linha :");
      coluna = get_valor("Coluna :");
      valor = consultaElem(matrix, linha, coluna);

      if (valor) {
        printf("matriz[%d][%d] = %d\n", linha, coluna, valor);
        printf("Elemento consultado com sucesso!");
      }

      break;
    case IMPRIMIR:
      printf("Executando comando...\n");

      if (matrix == NULL) {
        printf("Matriz não incializada impossível realizar operação..\n");
        break;
      }

      imprime(matrix);

      printf("Matriz imprimida com sucesso!\n");

      break;
    case IMPRIMIR_VETORES:
      printf("Executando comando...\n");

      if (matrix == NULL) {
        printf("Matriz não incializada impossível realizar operação..\n");
        break;
      }

      imprimeFaixaVetores(matrix);

      printf("Faixa de vetores imprimida com sucesso!\n");

      break;
    case DESTRUIR:
      printf("Executando comando...\n");

      destroiMatriz(&matrix);
      matrix = NULL;

      printf("Matriz destruida com sucesso!\n");

      break;
    case SAIR:
      if (matrix != NULL) {
        destroiMatriz(&matrix);
        matrix = NULL;
      }

      printf("Finalizando programa! Até mais!\n");
      break;
    }

  } while (opt != SAIR);

  return 0;
}