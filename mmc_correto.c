#include <stdio.h>

// Fun��o para calcular o M�nimo M�ltiplo Comum (MMC) de dois n�meros
int calcularMMC(int a, int b) {
    long long int temp, num1 = a, num2 = b;

    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    return (a * b) / num1;
}

// Fun��o para calcular o MMC de uma sequ�ncia de n�meros
int calcularMMCDaSequencia(int numeros[], int n) {
    long long int mmc = numeros[0];
	int i;
    for (i = 1; i < n; i++) {
        mmc = calcularMMC(mmc, numeros[i]);
    }

    return mmc;
}

int main() {
    long long int n;

    // L� o tamanho da sequ�ncia
    scanf("%lld", &n);

    // L� os elementos da sequ�ncia
    long long int numeros[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lld", &numeros[i]);
    }

    // Calcula e imprime o MMC da sequ�ncia
    long long int mmc = calcularMMCDaSequencia(numeros, n);
    printf("%lld\n", mmc);

    return 0;
}

