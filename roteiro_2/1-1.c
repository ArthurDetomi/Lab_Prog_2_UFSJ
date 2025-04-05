#include <stdio.h>
#include "conta_bancaria.h"

int main() {
    ContaBancaria c;

    criarConta(&c, 1234, "Mario Augusto");

    imprimirInfo(&c);

    printf("Realizando deposito de 25,50...\n");
    depositar(&c, 25.50);

    imprimirInfo(&c);


    printf("Tentando realizar saque de 30,50...\n");
    sacar(&c, 30.50);

    printf("Tentando realizar saque de 15,50...\n");
    sacar(&c, 15.50);

    printf("Consultado saldo...\n");
    printf("%.2f\n", consultarSaldo(&c));

    imprimirInfo(&c);

    return 0;
}