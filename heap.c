#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};

    // Tentando acessar um elemento al�m dos limites do array
    int valor = array[10];

    // O programa pode continuar executando c�digo ap�s o erro,
    // mas a execu��o geralmente � interrompida.
    printf("Valor: %d\n", valor);

    return 0;
}

