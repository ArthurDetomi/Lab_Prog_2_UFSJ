#include "LCSE.h"

int main() {
  Lista *L;
  L = criaLista();

  insereFim(L, 10);
  insereFim(L, 20);
  insereFim(L, 30);
  insereFim(L, 40);
  insereFim(L, 50);
  insereFim(L, 60);
  insereFim(L, 70);
  insereFim(L, 80);
  insereFim(L, 90);

  imprimeLista(L);

  printf("%d tamanho da lista \n", tamanho(L));

  if (procura(L, 90)) {
    printf("Elemento 90 encontrado com sucesso!\n");
  }

  if (!procura(L, 2)) {
    printf("Elemento 2 não encontrado!\n");
  }

  destroiLista(L);

  return 0;
}