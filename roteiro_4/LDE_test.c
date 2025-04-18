#include "LDE.h"
#include <stdio.h>

int main() {
  Lista *L;
  L = criaLista();

  insereOrdenado(L, 20);
  insereOrdenado(L, 30);
  insereOrdenado(L, 60);
  insereOrdenado(L, 40);
  insereOrdenado(L, 50);
  insereOrdenado(L, 80);
  insereOrdenado(L, 70);
  insereOrdenado(L, 90);
  insereOrdenado(L, 10);

  imprimeLista(L);

  printf("O tamanho da lista é %d\n", tamanho(L));

  if (procura(L, 10)) {
    printf("Valor 10 encontrado na lista\n");
  }

  if (removeCasoExista(L, 20)) {
    printf("Elemento 20 removido com sucesso!\n");
  }

  imprimeLista(L);

  destroiLista(L);
  return 0;
}