#include "AVL_FUNC.h"

#define MAX_OPTIONS 9

enum options {
  CRIAR = 0,
  INSERIR,
  BUSCAR,
  REMOVER,
  IMPRIMIR_ORDEM,
  MAIOR_SALARIO,
  MENOR_SALARIO,
  DESTRUIR,
  SAIR,
};

int get_option() {
  int opt = -1;
  do {
    printf("\tOperacoes\n");
    printf("[%d] Criar AVL, ", CRIAR);
    printf("[%d] Inserir um Funcionario pelo sal´ario, ", INSERIR);
    printf(
        "[%d] Buscar um Funcionario pelo salario e imprimir suas informacoes, ",
        BUSCAR);
    printf("[%d] Remover um funcionario pelo nome, ", REMOVER);
    printf("[%d] Imprimir a AVL em ordem, ", IMPRIMIR_ORDEM);
    printf("[%d]  Imprimir as informacoes do Funcionario com o maior salario, ",
           MAIOR_SALARIO);
    printf("[%d]  Imprimir as informacoes do Funcionario com o menor salario, ",
           MENOR_SALARIO);
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

Funcionario get_funcionario() {
  Funcionario func;

  printf("Digite o nome do funcionario:");
  scanf("%49s", func.nome);
  printf("Digite o ano de contratacao:");
  scanf("%d", &func.ano);
  printf("Digite o salario do funcionario:");
  scanf("%lf", &func.salario);

  return func;
}

void print_funcionario(Funcionario *f) {
  printf("Funcionario:\n");
  printf("Nome: %s, Ano de contratacao: %d, Salário: %.2lf\n", f->nome, f->ano,
         f->salario);
}

double get_salario(char *msg) {
  double value;

  printf("%s", msg);
  scanf("%lf", &value);

  return value;
}

int main() {
  int opt;

  double valor;
  Funcionario elem;

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

      elem = get_funcionario();

      if (insereElem(arvore, elem)) {
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

      valor = get_salario("Insira o salario do funcionario para busca: ");

      Funcionario f;
      f.salario = valor;

      if (pesquisa(arvore, &f)) {
        printf("Funcionario presente\n");
        print_funcionario(&f);
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

      char nome_pesquisa[50];
      printf("Digite o nome do funcionario para remoção: ");
      scanf("%49s", nome_pesquisa);

      int encontrado = buscar_elem_por_nome(arvore, nome_pesquisa, &elem);

      if (encontrado && removeElem(arvore, elem)) {
        printf("Elemento removido com sucesso!\n");
      }

      break;
    case IMPRIMIR_ORDEM:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore AVL não inicializada impossível realizar operação..\n");
        break;
      }

      em_ordem(*arvore, 0);

      printf("Árvore imprimida com sucesso!\n");

      break;
    case MAIOR_SALARIO:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore AVL não inicializada impossível realizar operação..\n");
        break;
      }

      if (buscar_com_maior_salario(arvore, &elem)) {
        print_funcionario(&elem);
      } else {
        printf("Falha ao encontrar funcionário com maior salario\n");
      }

      break;
    case MENOR_SALARIO:
      printf("Executando comando...\n");

      if (arvore == NULL) {
        printf("Árvore AVL não inicializada impossível realizar operação..\n");
        break;
      }

      if (buscar_com_menor_salario(arvore, &elem)) {
        print_funcionario(&elem);
      } else {
        printf("Falha ao encontrar funcionário com maior salario\n");
      }

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