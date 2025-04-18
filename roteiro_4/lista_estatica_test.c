#include "Lista.h"

int main() {
  Lista *L;
  L = criaLista();

  insereOrdenado(L, 30);
  insereOrdenado(L, 20);
  insereOrdenado(L, 10);
  insereOrdenado(L, 11);
  insereOrdenado(L, 5);
  insereOrdenado(L, 2);
  imprimeLista(L);
  if (removeElemento(L, 11)) {
    printf("Elemento %d removido com sucesso\n", 11);
  }

  int index = procura(L, 30);

  if (index != -1) {
    printf("Elemento 30 encontrado na posição %d\n", index);
  }

  imprimeLista(L);

  destroiLista(L);
  return 0;
}