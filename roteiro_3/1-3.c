#include "conjunto.h"
#include <stdbool.h>
#include <stdio.h>

#define MAX 5

int main() {
  enum opcoes {
    UNIAO = 0,
    INTERSECAO = 1,
    DIFERENCA = 2,
    IGUAIS = 3,
    SAIR = -1
  };

  printf("Testes de funções básicas:\n");
  Conjunto *conjunto_teste = criar_conjunto();

  for (int i = 1; i <= 5; i++) {
    inserir(conjunto_teste, i);
  }

  printf("Conjunto de teste:\n");
  imprimir_conjunto(conjunto_teste);

  printf("Maior valor = %d\n", get_maior_valor_conjunto(conjunto_teste));
  printf("Menor valor = %d\n", get_menor_valor_conjunto(conjunto_teste));

  remover(conjunto_teste, 1);
  printf("Conjunto após remover o número 1\n");
  imprimir_conjunto(conjunto_teste);

  liberar_conjunto(conjunto_teste);

  Conjunto *c1 = criar_conjunto(), *c2 = criar_conjunto();

  printf("Insira %d elementos no conjunto 1:\n", MAX);
  for (int i = 0; i < MAX; i++) {
    int value;
    scanf("%d", &value);

    inserir(c1, value);
  }

  printf("Insira %d elementos no conjunto 2:\n", MAX);
  for (int i = 0; i < MAX; i++) {
    int value;
    scanf("%d", &value);

    inserir(c2, value);
  }

  while (1) {
    printf("Digite a operação:\n");

    printf("UNIAO[%d]\n", UNIAO);
    printf("INTERSECAO[%d]\n", INTERSECAO);
    printf("DIFERENCA[%d]\n", DIFERENCA);
    printf("IGUAIS[%d]\n", IGUAIS);
    printf("SAIR[%d]\n", SAIR);

    int input;

    printf("Opção : ");
    scanf("%d", &input);

    Conjunto *resultado;

    switch (input) {
    case UNIAO:
      printf("UNIAO[%d] choosed:\n", UNIAO);
      resultado = unir_conjuntos(c1, c2);
      imprimir_conjunto(resultado);
      liberar_conjunto(resultado);

      break;
    case INTERSECAO:
      printf("INTERSECAO[%d] choosed:\n", INTERSECAO);
      resultado = get_intersecao_conjuntos(c1, c2);
      imprimir_conjunto(resultado);
      liberar_conjunto(resultado);

      break;
    case DIFERENCA:
      printf("DIFERENCA[%d] choosed:\n", DIFERENCA);
      resultado = get_diferenca_conjuntos(c1, c2);
      imprimir_conjunto(resultado);
      liberar_conjunto(resultado);

      break;
    case IGUAIS:
      printf("IGUAIS[%d] choosed:\n", IGUAIS);
      bool iguais = is_equal(c1, c2);

      if (iguais) {
        printf("Os conjuntos são iguais\n");
      } else {
        printf("Os conjuntos não são iguais\n");
      }

      break;
    case SAIR:
      return 0;
    }

    printf("\n\n");
  }

  liberar_conjunto(c1);
  liberar_conjunto(c2);

  return 0;
}