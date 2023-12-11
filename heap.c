#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};

    // Tentando acessar um elemento além dos limites do array
    int valor = array[10];

    // O programa pode continuar executando código após o erro,
    // mas a execução geralmente é interrompida.
    printf("Valor: %d\n", valor);

    return 0;
}

