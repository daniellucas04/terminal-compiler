#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

struct dirent *dp;

/*
* atualizarPastas: Percorre o diret�rio e atualiza as pastas
*/
void atualizarPastas() {
	DIR *dr = opendir(".");
	char problema[26]="";
	int i, count=0, caso=0;
  
  	// Se o diret�rio for NULL, encerra a busca
    if (dr == NULL){
        printf("N�o foi posss�vel abrir o diret�rio.\n\n" );
    }
  
  	// Percorre os diret�rios
    while ((dp = readdir(dr)) != NULL){
    	// Verifica o nome do diret�rio
        if(dp->d_namlen==1 && strcmp(dp->d_name,".")!=0){
        	strcat(problema, dp->d_name);
        	count++;
		}	
	}
	closedir(dr);
	
	// Percorre as pastas e encontra a quantidade de problemas
	for(i=0;i<count;i++){
		char caminho[50];
		// Adicionado o caminho para percorrer
		sprintf(caminho, ".\\%c\\input", problema[i]);
		
		// Descrobre a quantidade de casos no caminho
    	caso = qtdCasos(caminho);
    	
		// mostra a quantidade de problemas
		printf("| O Problema %c tem %d casos de teste |\n", problema[i], caso);
		caso=0;
		
		// Fecha a pasta
		closedir(dr);
	}
}

/*
* qtdCasos: Percorre o diret�rio e encontra a quantidade de casos
* @param STRING dir = diret�rio do problema
* @return int casosEncontrados = Quantidade de casos encontrados
*/
int qtdCasos(char dir[]) {
	DIR *dr;
	dr = opendir(dir);
	int casosEncontrados;
	
	// Se o diret�rio for NULL, encerra a busca
	if (dr == NULL) {
	    printf("N�o foi posss�vel abrir o diret�rio.\n");
	    return 0;
	}	
	
	while ((dp = readdir(dr)) != NULL){
    	if(dp->d_namlen > 2){
    		casosEncontrados++;
		}	
	}
	// Retorna a quantidade encontrada
	return casosEncontrados;
}

/*
* executaCodigo: Executa o codigo enviado e envia o resultado para pasta temp
* @param INT casos     = Quantidade de casos que existe no problema
* @param CHAR problema = Problema a ser executado
*/
void executaCodigo(int casos, char problema) {
	int i;
	for(i=1; i<=casos; i++){
		char comando[100];
		// Define o comando para recuperar a sa�da
		sprintf(comando, ".\\%c\\temp\\%c.exe < .\\%c\\input\\%d.txt > .\\%c\\temp\\%d.txt", problema, problema, problema, i, problema, i);
		system(comando);
	}
}

/*
* validaCasos: Valida os casos de teste utilizando a resposta do c�digo enviado
* @param INT casos     = Quantidade de casos que existe no problema
* @param CHAR problema = Problema a ser verificado
*/
void validaCasos(int casos, char problema) {
	int i, erro=0;
    FILE *output;
    FILE *temp;
    char outputr, tempr, arqo[50], arqt[50];
    
	// Percorre a quantidade de casos de teste
    for(i=1; i<=casos; i++){
    	// Define o caminho do caso de teste
        sprintf(arqo,".\\%c\\output\\%d.txt", problema, i);
        output = fopen(arqo, "r");
        // Define o caminho da resposta do aluno
        sprintf(arqt,".\\%c\\temp\\%d.txt", problema, i);
        temp = fopen(arqt, "r");
        
        // Percorre o arquivo
		while((tempr = fgetc(temp)) != EOF){
            outputr = fgetc(output);
            // Valida se o caracter da resposta esperada � igual ao caracter da resposta enviada
            if(outputr != tempr){
            	erro=1; // Possui um erro
            }
        }
        
        // Realiza valida��o do erro
        if(erro == 0){
            printf("Caso de teste [%d] ................. [OK] \n", i);
        }else{
            printf("Caso de teste [%d] ............... [ERRO] \n", i);
        }
        
        // Limpa os buffers e fecha os arquivos
        fflush(stdout);
        fclose(output);
        fflush(stdout);
        fclose(temp);
        erro=0;
    }
}

/*
* deletaExecutavel: Deleta o execut�vel do c�digo enviado
* @param CHAR problema = caracter do problema
*/
void deletaExecutavel(char problema) {
	char pasta[20], executavel[10], deleta[20];
	
	// Atribui os caminhos para as vari�veis
	sprintf(executavel, "%c.exe", problema);
	sprintf(pasta, ".\\%c\\temp", problema);
	// Comando para deletar o execut�vel
	sprintf(deleta, "DEL .\\%c\\temp\\%c.exe", problema, problema);
	DIR *dr = opendir(pasta);
  
  	// Se o diret�rio for NULL, encerra a busca
    if (dr == NULL){
        printf("N�o foi posss�vel abrir o diret�rio.\n\n" );
    }
  
  	// Percorre os diret�rios
    while ((dp = readdir(dr)) != NULL){
    	// Verifica o nome do execut�vel
        if(strcmp(dp->d_name, executavel)==0){
			system(deleta); // deleta o execut�vel
		}	
	}
	
	// Fecha a pasta
	closedir(dr);
}


/*
* checarExecutavel: Valida se o execut�vel do programa existe
* @param CHAR problema = caracter do problema
* @return int existe = Quantidade de execut�veis na pasta
*/
int checarExecutavel(char problema) {
	char pasta[20],executavel[10];
	// Declara os caminhos para as vari�veis
	sprintf(executavel, "%c.exe", problema);
	sprintf(pasta, ".\\%c\\temp", problema);
	DIR *dr = opendir(pasta);
	
	int existe = 0;
  
  	// Se o diret�rio for NULL, encerra a busca
    if (dr == NULL){
        printf("N�o foi posss�vel abrir o diret�rio.\n\n" );
    }
  
  	// Percorre os diret�rios
    while ((dp = readdir(dr)) != NULL){
    	// Verifica o nome do diret�rio
        if(strcmp(dp->d_name, executavel)==0){
			existe++;
		}	
	}
	// Fecha a pasta
	closedir(dr);
	return existe;
}

/*
* checarPasta: Valida se a pasta do problema existe
* @param CHAR problema = caracter do problema
* @return int = 0 para n�o existe | 1 para existe
*/
int checarPasta(char problema) {
	char pasta[20];
	// Define o caminho para vari�vel
	sprintf(pasta, ".\\%c", problema);
	DIR *dr = opendir(pasta);
  
  	// Se o diret�rio for NULL, encerra a busca
    if (dr == NULL){
        printf("N�o foi posss�vel abrir o diret�rio.\n\n" );
        return 0;
    }
    // Fecha a pasta
	closedir(dr);
	return 1;	
}

