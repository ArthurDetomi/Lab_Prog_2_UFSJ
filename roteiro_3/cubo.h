#ifndef CUBO_H
#define CUBO_H

typedef struct cubo Cubo;

Cubo *criar_cubo(double lado);

double get_lado_cubo(Cubo *cubo);

double get_area_cubo(Cubo *cubo);

double get_volume_cubo(Cubo *cubo);

void liberar_cubo(Cubo *cubo);

#endif