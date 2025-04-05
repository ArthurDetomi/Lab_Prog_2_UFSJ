#include "catalogo_produtos.h"
#include <stdio.h>

int main() {
  CatalogoProdutos c;

  criarCatalogo(&c);

  adicionarProduto(&c, "Cafe", 25.90, 20);
  adicionarProduto(&c, "Arroz", 35.90, 21);
  adicionarProduto(&c, "Macarrao", 5.90, 22);

  printf("Estoque de Macarrão = %d\n", verificarEstoque(&c, "Macarrao"));

  imprimirCatalogo(&c);

  return 0;
}