#include "conta_bancaria.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void verificar_conta(ContaBancaria *c) {
    if (c == NULL) {
        printf("Conta não foi inicializada\n");
        exit(1);
    }
}

void criarConta(ContaBancaria* c, int numero, char *titular) {
    verificar_conta(c);

    c->numero = numero;
    c->saldo = 0.0;
    strcpy(c->titular, titular);
}

void depositar(ContaBancaria *c, double valor) {
    verificar_conta(c);

    c->saldo += valor;
}

void sacar(ContaBancaria *c, double valor) {
    verificar_conta(c);

    if (c->saldo < valor) {
        printf("Você não possui saldo suficiente\n");
        return;
    }

    c->saldo-=valor;
    printf("Saque realizado com sucesso!\n");
}
double consultarSaldo(ContaBancaria *c) {
    verificar_conta(c);

    return c->saldo;
}
void imprimirInfo(ContaBancaria *c) {
    verificar_conta(c);
    
    printf("\n\tDados da conta bancaria\n");
    printf("Numero da Conta: %d\n", c->numero);
    printf("Titular: %s\n", c->titular);
    printf("Saldo: %.2f\n", c->saldo);
}