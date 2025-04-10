#include "cubo.h"
#include <stdio.h>

int main() {
  Cubo *cubo = criar_cubo(7);

  printf("Lado do cubo = %.2lf mm\n", get_lado_cubo(cubo));
  printf("O volume do cubo = %.2lf mm³\n", get_volume_cubo(cubo));
  printf("A área do cubo = %.2lf mm²\n", get_area_cubo(cubo));

  liberar_cubo(cubo);

  return 0;
}