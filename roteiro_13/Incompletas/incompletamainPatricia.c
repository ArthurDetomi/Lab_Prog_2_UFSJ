#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definição da estrutura do nó da árvore de Patricia
typedef struct PatriciaTrieNode {
    int number;
    int data;
    struct PatriciaTrieNode *leftChild;
    struct PatriciaTrieNode *rightChild;
} PatriciaTrieNode;

// Definição da estrutura do teste de Patricia
typedef struct PatriciaTest {
    PatriciaTrieNode *root;
    int MaxBits;
} PatriciaTest;

// Protótipos das funções
PatriciaTrieNode *search(PatriciaTrieNode *t, int k);
PatriciaTrieNode *insert(PatriciaTrieNode *t, int element);
int bit(int k, int i);
int searchPatricia(PatriciaTest *pt, int k);
void insertPatricia(PatriciaTest *pt, int element);

// Função principal (main)
int main() {
    // Declaração do objeto da classe PatriciaTest
    PatriciaTest pt;

    // Inicialização do objeto
    pt.root = NULL;
    pt.MaxBits = 10;

    // Variáveis para o menu
    char ch;
    int choice;

    do {
        // Menu de operações
        printf("\n Patricia Trie Operations\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Check Empty\n");
        printf("4. Make Empty\n");
        printf("Make your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                int element;
                scanf("%d", &element);
                insertPatricia(&pt, element);
                break;

            case 2:
                printf("Enter element to search: ");
                int searchElement;
                scanf("%d", &searchElement);
                printf("Search result: %d\n", searchPatricia(&pt, searchElement));
                break;

            case 3:
                printf("Empty status: %s\n", pt.root == NULL ? "true" : "false");
                break;

            case 4:
                printf("Patricia Trie Cleared\n");
                pt.root = NULL;
                break;

            default:
                printf("Wrong entry\n");
                break;
        }

        // Continuar ou não
        printf("\nDo you want to continue (Type y or n): ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    return 0;
}

// Função para buscar um elemento na árvore de Patricia
PatriciaTrieNode *search(PatriciaTrieNode *t, int k) {
    PatriciaTrieNode *currentNode, *nextNode;
    if (t == NULL) {
        return NULL;
    }
    nextNode = t->leftChild;
    currentNode = t;
    while (nextNode->number > currentNode->number) {
        currentNode = nextNode;
        nextNode = (bit(k, nextNode->number)) ? nextNode->rightChild : nextNode->leftChild;
    }
    return nextNode;
}

// Função para inserir um elemento na árvore de Patricia
PatriciaTrieNode *insert(PatriciaTrieNode *t, int element) {
    PatriciaTrieNode *current, *parent, *lastNode, *newNode;
    int i;
    if (t == NULL) {
        t = (PatriciaTrieNode *)malloc(sizeof(PatriciaTrieNode));
        t->number = 0;
        t->data = element;
        t->leftChild = t;
        t->rightChild = NULL;
        return t;
    }
    lastNode = search(t, element);
    if (element == lastNode->data) {
        printf("Key already Present\n");
        return t;
    }
    for (i = 1; bit(element, i) == bit(lastNode->data, i); i++)
        current = t->leftChild;
    parent = t;
    while (current->number > parent->number && current->number < i) {
        parent = current;
        current = (bit(element, current->number)) ? current->rightChild : current->leftChild;
    }
    newNode = (PatriciaTrieNode *)malloc(sizeof(PatriciaTrieNode));
    newNode->number = i;
    newNode->data = element;
    newNode->leftChild = (bit(element, i)) ? current : newNode;
    newNode->rightChild = (bit(element, i)) ? newNode : current;
    if (current == parent->leftChild) {
        parent->leftChild = newNode;
    } else {
        parent->rightChild = newNode;
    }
    return t;
}

// Função para obter um bit específico de um número binário
int bit(int k, int i) {
    char binary[32];
    snprintf(binary, sizeof(binary), "%d", k);
    while (strlen(binary) != 10)
        strcpy(binary, "0");
    return (binary[i - 1] == '1') ? 1 : 0;
}

// Função de busca exposta para o usuário
int searchPatricia(PatriciaTest *pt, int k) {
    int num = (int)(log(k) / log(2));
    if (num > pt->MaxBits) {
        printf("Exceeded the limit\n");
        return 0;
    }
    PatriciaTrieNode *searchNode = search(pt->root, k);
    return (searchNode->data == k) ? 1 : 0;
}

// Função de inserção exposta para o usuário
void insertPatricia(PatriciaTest *pt, int element) {
    int num = (int)(log(element) / log(2)) + 1;
    if (num > pt->MaxBits) {
        printf("We are full, The number is too large\n");
        return;
    }
    pt->root = insert(pt->root, element);
}
