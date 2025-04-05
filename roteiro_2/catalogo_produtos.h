#ifndef CATALOGO_PRODUTOS_H
#define CATALOGO_PRODUTOS_H

typedef struct Produto {
  char nome[50];
  double preco;
  int quantidade;
} Produto;

typedef struct CatalogoProdutos {
  Produto produtos[100];
  int total;
} CatalogoProdutos;

// Cria um cat´alogo vazio, zerando o total de produtos.
void criarCatalogo(CatalogoProdutos *c);
// Adiciona um novo produto ao cat´alogo.
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco,
                      int quantidade);
// Verifica a quantidade em estoque de um produto.
int verificarEstoque(CatalogoProdutos *c, char *nome);
// Imprime todas as informa¸c˜oes dos produtos no cat´alogo.
void imprimirCatalogo(CatalogoProdutos *c);

#endif