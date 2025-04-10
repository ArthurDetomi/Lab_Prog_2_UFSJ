#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdbool.h>

typedef int elemento;

typedef struct conjunto Conjunto;

Conjunto *criar_conjunto();

Conjunto *unir_conjuntos(Conjunto *c1, Conjunto *c2);

void inserir(Conjunto *c1, elemento elemento);

void remover(Conjunto *c1, elemento elemento);

Conjunto *get_intersecao_conjuntos(Conjunto *c1, Conjunto *c2);

Conjunto *get_diferenca_conjuntos(Conjunto *c1, Conjunto *c2);

bool is_pertence_ao_conjunto(Conjunto *c, elemento elemento);

elemento get_menor_valor_conjunto(Conjunto *c);

elemento get_maior_valor_conjunto(Conjunto *c);

bool is_equal(Conjunto *c1, Conjunto *c2);

int get_tamanho_conjunto(Conjunto *c);

bool is_empty_conjunto(Conjunto *c);

void liberar_conjunto(Conjunto *c);

void imprimir_conjunto(Conjunto *c);

#endif