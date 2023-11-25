#include<stdio.h>
#include "./dependencies/functions.h"

struct dirent *dp;

int main(){
	setlocale(LC_ALL, "Portuguese");
	int count, i, casosEncontrados = 0;
	char compilar[50], arquivo[50], exercicio;
	char diretorio[50];
	
	printf("     _                             _                 _       _             \n");
	printf("    | | ___  _ __   ___  ___   ___(_)_ __ ___  _   _| | __ _| |_ ___  _ __ \n");
	printf(" _  | |/ _ \\| '_ \\ / _ \\/ __| / __| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|\n");
	printf("| |_| | (_) | | | |  __/\\__ \\ \\__ \\ | | | | | | |_| | | (_| | || (_) | |   \n");
	printf(" \\___/ \\___/|_| |_|\\___||___/ |___/_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   \n\n");
	
	// Percorre as pastas e encontra os casos de teste
	printf("----- Problemas encontrados -----\n");
	atualizarPastas();
	
	// Recupera informações do exercicio e código fonte
	printf("Escolha qual o exercicio será resolvido: ");
	scanf("%c", &exercicio);

	printf("Escolha qual arquivo será enviado: ");
	scanf("%s", &arquivo);
	
	// Define o diretório para encontrar a quantidade de casos
	sprintf(diretorio,".\\%c\\input", exercicio);
	dp = opendir(diretorio);
	
	// Encontra a quantidade de casos no diretório
	casosEncontrados = qtdCasos(diretorio);
	
	// Compila o código no terminal
	sprintf(compilar,"gcc %s -o .\\%c\\temp\\%c.exe", arquivo, exercicio, exercicio);
	system(compilar);
	
	printf("\nExecutando casos de teste...\n");
	// Executa o código do aluno e coloca a saída no diretório temp
	executaCodigo(casosEncontrados, exercicio);
	
	// Verifica se os casos estão certos ou errados
	validaCasos(casosEncontrados, exercicio);
	
	return 0;
}
