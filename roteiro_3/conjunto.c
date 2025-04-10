#include "conjunto.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct conjunto {
  elemento *elementos;
  int tamanho;
  int max_size;
};

void verificar_estouro_memoria(void *ponteiro) {
  if (ponteiro == NULL) {
    printf("Erro presença de ponteiro nulo em local indevido\n");
    exit(1);
  }
}

Conjunto *criar_conjunto() {
  Conjunto *conjunto = (Conjunto *)malloc(sizeof(Conjunto));

  verificar_estouro_memoria(conjunto);

  conjunto->tamanho = 0;
  conjunto->max_size = MAX;

  conjunto->elementos =
      (elemento *)malloc(conjunto->max_size * sizeof(elemento));

  verificar_estouro_memoria(conjunto->elementos);

  return conjunto;
}

Conjunto *unir_conjuntos(Conjunto *c1, Conjunto *c2) {
  Conjunto *novo_conjunto = criar_conjunto();

  for (int i = 0; i < c1->tamanho; i++) {
    inserir(novo_conjunto, c1->elementos[i]);
  }

  for (int i = 0; i < c2->tamanho; i++) {
    inserir(novo_conjunto, c2->elementos[i]);
  }

  return novo_conjunto;
}

// Inseri elementos no conjunto não permitindo duplicatas
void inserir(Conjunto *c1, elemento el) {
  verificar_estouro_memoria(c1);

  if (is_pertence_ao_conjunto(c1, el)) {
    return;
  }

  if (c1->tamanho + 1 >= c1->max_size) {
    c1->elementos =
        (elemento *)realloc(c1->elementos, c1->max_size * 2 * sizeof(elemento));
  }

  c1->elementos[c1->tamanho] = el;

  c1->tamanho++;
}

void remover(Conjunto *c1, elemento elemento) {
  verificar_estouro_memoria(c1);

  int index = -1;

  for (int i = 0; i < c1->tamanho; i++) {
    if (elemento == c1->elementos[i]) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    return;
  }

  for (int i = index; i < c1->tamanho - 1; i++) {
    c1->elementos[i] = c1->elementos[i + 1];
  }

  c1->tamanho--;
}

Conjunto *get_intersecao_conjuntos(Conjunto *c1, Conjunto *c2) {
  verificar_estouro_memoria(c1);
  verificar_estouro_memoria(c2);

  Conjunto *novo_conjunto = criar_conjunto();

  Conjunto *menor_conjunto = (c1->tamanho < c2->tamanho) ? c1 : c2;
  Conjunto *maior_conjunto = (c2->tamanho > c1->tamanho) ? c2 : c1;

  for (int i = 0; i < menor_conjunto->tamanho; i++) {
    elemento elemento_atual = menor_conjunto->elementos[i];

    if (is_pertence_ao_conjunto(maior_conjunto, elemento_atual)) {
      inserir(novo_conjunto, elemento_atual);
    }
  }

  return novo_conjunto;
}

Conjunto *get_diferenca_conjuntos(Conjunto *c1, Conjunto *c2) {
  verificar_estouro_memoria(c1);
  verificar_estouro_memoria(c2);

  Conjunto *novo_conjunto = criar_conjunto();

  Conjunto *menor_conjunto = (c1->tamanho < c2->tamanho) ? c1 : c2;
  Conjunto *maior_conjunto = (c2->tamanho > c1->tamanho) ? c2 : c1;

  for (int i = 0; i < maior_conjunto->tamanho; i++) {
    elemento elemento_atual = maior_conjunto->elementos[i];

    if (!is_pertence_ao_conjunto(menor_conjunto, elemento_atual)) {
      inserir(novo_conjunto, elemento_atual);
    }
  }

  return novo_conjunto;
}

bool is_pertence_ao_conjunto(Conjunto *c, elemento el) {
  verificar_estouro_memoria(c);
  for (int i = 0; i < c->tamanho; i++) {
    if (c->elementos[i] == el) {
      return true;
    }
  }
  return false;
}

elemento get_menor_valor_conjunto(Conjunto *c) {
  verificar_estouro_memoria(c);

  elemento menor = c->elementos[0];

  for (int i = 1; i < c->tamanho; i++) {
    if (c->elementos[i] < menor) {
      menor = c->elementos[i];
    }
  }

  return menor;
}

elemento get_maior_valor_conjunto(Conjunto *c) {
  verificar_estouro_memoria(c);

  elemento maior = c->elementos[0];

  for (int i = 1; i < c->tamanho; i++) {
    if (c->elementos[i] > maior) {
      maior = c->elementos[i];
    }
  }

  return maior;
}

bool is_equal(Conjunto *c1, Conjunto *c2) {
  verificar_estouro_memoria(c1);
  verificar_estouro_memoria(c2);

  if (c1->tamanho != c2->tamanho) {
    return false;
  }

  for (int i = 0; i < c1->tamanho; i++) {
    if (!is_pertence_ao_conjunto(c2, c1->elementos[i])) {
      return false;
    }
  }

  return true;
}

int get_tamanho_conjunto(Conjunto *c) {
  verificar_estouro_memoria(c);

  return c->tamanho;
}

bool is_empty_conjunto(Conjunto *c) {
  verificar_estouro_memoria(c);
  return c->tamanho == 0;
}

void liberar_conjunto(Conjunto *c) {
  free(c->elementos);
  c->elementos = NULL;

  free(c);
  c = NULL;
}

void imprimir_conjunto(Conjunto *c) {
  printf("[ ");
  for (int i = 0; i < c->tamanho; i++) {
    printf("%d ", c->elementos[i]);
    if (i != c->tamanho - 1) {
      printf(",");
    }
  }
  printf("]\n");
}