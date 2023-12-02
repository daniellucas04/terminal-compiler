#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

struct dirent *dp;

void atualizarPastas() {
	DIR *dr = opendir(".");
	char problema[26]="";
	int i, count=0, caso=0;
  
  	// Se o diretório for NULL, encerra a busca
    if (dr == NULL){
        printf("Não foi posssível abrir o diretório.\n\n" );
    }
  
  	// Percorre os diretórios
    while ((dp = readdir(dr)) != NULL){
    	// Verifica o nome do diretório
        if(dp->d_namlen==1 && strcmp(dp->d_name,".")!=0){
        	strcat(problema,dp->d_name);
        	count++;
		}	
	}
	closedir(dr);
	
	// Percorre as pastas e encontra a quantidade de problemas
	for(i=0;i<count;i++){
		char caminho[50];
		// Adicionado o caminho para percorrer
		sprintf(caminho,".\\%c\\input", problema[i]);
		
		// Descrobre a quantidade de casos no caminho
    	caso = qtdCasos(caminho);
    	
		// mostra a quantidade de problemas
		printf("| O Problema %c tem %d casos de teste |\n", problema[i], caso);
		caso=0;
		closedir(dr);
	}
}

int qtdCasos(char dir[]) {
	DIR *dr;
	dr = opendir(dir);
	int casoEncontrado;
	
	// Se o diretório for NULL, encerra a busca
	if (dr == NULL) {
	    printf("Não foi posssível abrir o diretório.\n");
	    return 0;
	}	
	
	while ((dp = readdir(dr)) != NULL){
    	if(dp->d_namlen>2){
    		casoEncontrado++;
		}	
	}
	// Retorna a quantidade encontrada
	return casoEncontrado;
}

void executaCodigo(int casos, char problema) {
	int i;
	for(i=1;i<=casos;i++){
		char comando[100];
		// Define o comando para recuperar a sapida
		sprintf(comando,".\\%c\\temp\\%c.exe < .\\%c\\input\\%d.txt > .\\%c\\temp\\%d.txt\n\n", problema, problema, problema, i, problema, i);
		system(comando);
	}
}

void validaCasos(int casos, char problema) {
	int i;
	// Percorre todos os casos de teste
	for(i=1;i<=casos;i++){
		FILE *output;
		FILE *temp;
		char output1[100]="", tempr[100]="", arqo[50], arqt[50];
		
		// Constrói o comando para acessar o caso de teste esperado
		sprintf(arqo,".\\%c\\output\\%d.txt", problema, i);
		output=fopen(arqo,"r");
		while(fscanf(output,"%s",output1) !=EOF)
		
		fflush(stdout);
		fclose(output);
		
		// Constrói o comando para acessar a reposta recebida
		sprintf(arqt,".\\%c\\temp\\%d.txt", problema, i);
		temp=fopen(arqt,"r");
		while(fscanf(temp,"%s",tempr) !=EOF)
		
		fflush(stdout);
		fclose(temp);
		
		// Realiza a comparação do caso de teste esperado com a resposta recebida
		if(strcmp(tempr,output1)==0){
			// Resposta correta
			printf("Caso de teste [%d] ................. [OK] \n", i);
		}else{
			// Resposta errada
			printf("Caso de teste [%d] ............... [ERRO] \n", i);
		}
	}
}

void deletaExecutavel(char problema) {
	char pasta[20],executavel[10],deleta[20];
	sprintf(executavel,"%c.exe",problema);
	sprintf(pasta,".\\%c\\temp",problema);
	sprintf(deleta,"DEL .\\%c\\temp\\%c.exe",problema,problema);
	DIR *dr = opendir(pasta);
  
  	// Se o diretório for NULL, encerra a busca
    if (dr == NULL){
        printf("Não foi posssível abrir o diretório.\n\n" );
    }
  
  	// Percorre os diretórios
    while ((dp = readdir(dr)) != NULL){
    	// Verifica o nome do executável
        if(strcmp(dp->d_name,executavel)==0){
			system(deleta); // deleta o executável
		}	
	}
	closedir(dr);
}


int checarExecutavel(char problema) {
	char pasta[20],executavel[10];
	sprintf(executavel,"%c.exe",problema);
	sprintf(pasta,".\\%c\\temp",problema);
	DIR *dr = opendir(pasta);
	int i=0;
  
  	// Se o diretório for NULL, encerra a busca
    if (dr == NULL){
        printf("Não foi posssível abrir o diretório.\n\n" );
    }
  
  	// Percorre os diretórios
    while ((dp = readdir(dr)) != NULL){
    	// Verifica o nome do diretório
        if(strcmp(dp->d_name,executavel)==0){
			i++;
		}	
	}
	closedir(dr);
	
	return i;
}

int checarPasta(char problema) {
	char pasta[20];
	sprintf(pasta,".\\%c",problema);
	DIR *dr = opendir(pasta);
  
  	// Se o diretório for NULL, encerra a busca
    if (dr == NULL){
        printf("Não foi posssível abrir o diretório.\n\n" );
        return 0;
    }
	closedir(dr);
	return 1;	
}

