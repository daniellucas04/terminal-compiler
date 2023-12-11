#include<stdio.h>
#include "./dependencies/functions.h"

// Estrutura de diretórios
struct dirent *dp;

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int casosEncontrados = 0;
	char compilar[100], arquivo[50], diretorio[50], problema;
	
	printf("     _                             _                 _       _             \n");
	printf("    | | ___  _ __   ___  ___   ___(_)_ __ ___  _   _| | __ _| |_ ___  _ __ \n");
	printf(" _  | |/ _ \\| '_ \\ / _ \\/ __| / __| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|\n");
	printf("| |_| | (_) | | | |  __/\\__ \\ \\__ \\ | | | | | | |_| | | (_| | || (_) | |   \n");
	printf(" \\___/ \\___/|_| |_|\\___||___/ |___/_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   \n\n");
	
	// Percorre as pastas e encontra os casos de teste
	printf("------- Problemas encontrados -------\n");
	atualizarPastas();
	printf("-------------------------------------\n\n");
	
	// Recebe o problema a ser resolvido
	printf("Escolha qual problema será resolvido: ");
	scanf("%c", &problema);
	
	// Verifica se a pasta do problema existe. Se a pasta não existir, fecha o programa
	if(checarPasta(problema) == 0){
		return 0;
	}

	// Recebe o código fonte a ser compilado
	printf("Escolha qual arquivo será enviado: ");
	scanf("%s", arquivo);
	
	// Define o diretório para encontrar a quantidade de casos
	sprintf(diretorio, ".\\%c\\input", problema);
	dp = opendir(diretorio);
	
	// Encontra a quantidade de casos no diretório
	casosEncontrados = qtdCasos(diretorio);
	
	// Compila o código no terminal
	sprintf(compilar,"gcc %s -o .\\%c\\temp\\%c.exe 2> erros.txt", arquivo, problema, problema);
	system(compilar);
	
	system("DEL erros.txt"); // Deleta o arquivo de erros de compilação do diretório
	
	// Verifica se o executável foi criado
	if(checarExecutavel(problema) == 0){
		printf("\n****************************************\n");
		printf("----------------------------------------\n");
		printf("          Erro de Compilação            \n");
		printf("----------------------------------------\n");
		printf("****************************************\n");
		return 0;
	}
	
	printf("\nExecutando casos de teste...\n");
	// Executa o código do aluno e coloca a saída no diretório temp
	executaCodigo(casosEncontrados, problema);
	
	// Verifica se os casos estão certos ou errados
	validaCasos(casosEncontrados, problema);
	
	// Deleta o executável gerado pela compilação
	deletaExecutavel(problema);

	return 0;
}
