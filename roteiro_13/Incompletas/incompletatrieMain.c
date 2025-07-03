#include <stdio.h>
#include "Trie.h"

int main(){

    Registro *r = (Registro*) malloc (sizeof(Registro));
    Registro *p = (Registro*) malloc (sizeof(Registro));
    No** trie;
    //trie = NULL;
    //*trie = (No*) malloc (sizeof(No));

    r->chave = 10;
    insere(trie, r);

    r->chave = 11;
    insere(trie, r);

    r->chave = 12;
    insere(trie, r);

    p = pesquisa(*trie, 12);
    if(p) printf("Registro %d encontrado.\n", p->chave);
    else printf("Registro NAO encontrado!\n");

    p = pesquisa(*trie, 9);
    if(p) printf("Registro %d encontrado.\n", p->chave);
    else printf("Registro NAO encontrado!\n");

    return 0;
}
