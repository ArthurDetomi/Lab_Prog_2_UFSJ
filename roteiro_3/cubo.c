#include "cubo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct cubo {
  double lado;
};

void verificar_estouro_memoria(void *ponteiro) {
  if (ponteiro == NULL) {
    printf("Erro presença de ponteiro nulo em local indevido\n");
    exit(1);
  }
}

Cubo *criar_cubo(double lado) {
  Cubo *cubo = (Cubo *)malloc(sizeof(Cubo));

  verificar_estouro_memoria(cubo);

  cubo->lado = lado;

  return cubo;
}

double get_lado_cubo(Cubo *cubo) {
  verificar_estouro_memoria(cubo);

  return cubo->lado;
}

double get_volume_cubo(Cubo *cubo) {
  verificar_estouro_memoria(cubo);

  return pow(cubo->lado, 3);
}

double get_area_cubo(Cubo *cubo) {
  verificar_estouro_memoria(cubo);

  double area_base = pow(cubo->lado, 2);

  double area_lateral = 4 * area_base;

  return 2 * area_base + area_lateral;
}

void liberar_cubo(Cubo *cubo) {
  free(cubo);
  cubo = NULL;
}