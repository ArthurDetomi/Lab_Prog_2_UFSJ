#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

typedef struct ContaBancaria {
    int numero;
    double saldo;
    char titular[50];
} ContaBancaria;

void criarConta(ContaBancaria* c, int numero, char *titular);
void depositar(ContaBancaria *c, double valor);
void sacar(ContaBancaria *c, double valor);
double consultarSaldo(ContaBancaria *c);
void imprimirInfo(ContaBancaria *c);

#endif