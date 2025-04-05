#include "catalogo_produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void verificar_catalogo(CatalogoProdutos *c) {
  if (c == NULL) {
    printf("Catalogo de produtos não foi inicializado\n");
    exit(1);
  }
}

// Cria um catalogo vazio, zerando o total de produtos.
void criarCatalogo(CatalogoProdutos *c) {
  verificar_catalogo(c);

  c->total = 0;
}

// Adiciona um novo produto ao cat´alogo.
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco,
                      int quantidade) {
  verificar_catalogo(c);

  Produto p;
  strcpy(p.nome, nome);
  p.preco = preco;
  p.quantidade = quantidade;

  c->produtos[c->total] = p;

  c->total++;
}
// Verifica a quantidade em estoque de um produto.
// Se não existir o respectivo produto retorna -1
int verificarEstoque(CatalogoProdutos *c, char *nome) {
  verificar_catalogo(c);

  for (int i = 0; i < c->total; i++) {
    Produto p = c->produtos[i];

    if (strcmp(nome, p.nome) == 0) {
      return p.quantidade;
    }
  }

  return -1;
}

void imprimirProduto(Produto p) {
  printf("\nProduto nome: %s\n", p.nome);
  printf("Quantidade: %d\n", p.quantidade);
  printf("Preço = %.2f \n\n", p.preco);
}

// Imprime todas as informa¸c˜oes dos produtos no cat´alogo.
void imprimirCatalogo(CatalogoProdutos *c) {
  verificar_catalogo(c);
  for (int i = 0; i < c->total; i++) {
    Produto p = c->produtos[i];

    imprimirProduto(p);
  }
}