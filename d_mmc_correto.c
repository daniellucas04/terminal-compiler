#include <stdio.h>

// Função para calcular o Mínimo Múltiplo Comum (MMC) de dois números
int calcularMMC(int a, int b) {
    int temp, num1 = a, num2 = b;

    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    return (a * b) / num1;
}

// Função para calcular o MMC de uma sequência de números
int calcularMMCDaSequencia(int numeros[], int n) {
    int mmc = numeros[0];
	int i;
    for (i = 1; i < n; i++) {
        mmc = calcularMMC(mmc, numeros[i]);
    }

    return mmc;
}

int main() {
    int n;
    int i;

    // Lê o tamanho da sequência
    scanf("%d", &n);

    // Lê os elementos da sequência
    int numeros[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    // Calcula e imprime o MMC da sequência
    int mmc = calcularMMCDaSequencia(numeros, n);
    printf("%d\n", mmc);

    return 0;
}
