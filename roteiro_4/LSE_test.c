#include "LSE.h"
#include <stdio.h>

int main() {
  Lista *L;
  L = criaLista();

  insereOrdenado(L, 20);
  insereOrdenado(L, 30);
  insereOrdenado(L, 40);
  insereOrdenado(L, 50);
  insereOrdenado(L, 60);
  insereOrdenado(L, 70);
  insereOrdenado(L, 80);
  insereOrdenado(L, 90);
  insereOrdenado(L, 10);

  printf("Tamanho %d\n", tamanho(L));

  if (procura(L, 20)) {
    printf("Elemento 20 encontrado com sucesso!\n");
  }
  imprimeLista(L);

  printf("Removendo o 20\n");
  removePrimeiraOcorrencia(L, 20);

  imprimeLista(L);

  destroiLista(L);
  return 0;
}
