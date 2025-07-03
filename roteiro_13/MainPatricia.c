#include "Patricia.h"
#include <stdio.h>

void binary(int n) {
  if (n < 2)
    printf("%d ", n % 2);
  else {
    binary(n / 2);
    printf("%d ", n % 2);
  }
}

int main() {

  int valores[7] = {18, 19, 24, 33, 40, 54, 34};

  ArvorePat P = NULL;
  int x, i;

  printf("\nPatricia - Inserção:\n");

  for (i = 0; i < 7; i++) {
    printf("%d em binario: ", valores[i]);
    binary(valores[i]);
    printf("\n");
    P = Insere(valores[i], &P);
  }

  printf("\nPatricia - Após inserção:\n");
  imprimePatricia(P);

  printf("\nPatricia - Pesquisa:\n");
  for (i = 0; i < 7; i++) {
    Pesquisa(valores[i], P);
  }

  return 0;
}
