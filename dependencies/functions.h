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
  
    if (dr == NULL)
    {
        printf("Não foi possível abrir o diretório\n" );
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
	
	// Percorre as pastas e encontra a quantidade de exercicios
	for(i=0;i<count;i++){
		char caminho[50];
		// Adicionado o caminho para percorrer
		sprintf(caminho,".\\%c\\input", problema[i]);
		
		// Descrobre a quantidade de casos no caminho
    	caso = qtdCasos(caminho);
    	
		// mostra a quantidade de problemas
		printf("O Problema %c tem %d casos de teste\n", problema[i], caso);
		caso=0;
		closedir(dr);
	}
	printf("\n");
}

int qtdCasos(char dir[]) {
	DIR *dr;
	dr = opendir(dir);
	int casoEncontrado;
	
	// Se o diretório for NULL, encerra a busca
	if (dr == NULL) {
	    printf("Não foi possível abrir o diretório.\n");
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

void executaCodigo(int casos, char exercicio) {
	int i;
	for(i=1;i<=casos;i++){
		char comando[100];
		// Define o comando para recuperar a sapida
		sprintf(comando,".\\%c\\temp\\%c.exe < .\\%c\\input\\%d.txt > .\\%c\\temp\\%d.txt\n\n", exercicio, exercicio, exercicio, i, exercicio, i);
		system(comando);
	}
}

void validaCasos(int casos, char exercicio) {
	int i;
	for(i=1;i<=casos;i++){
		FILE *output;
		FILE *temp;
		char output1[100]="", tempr[100]="", arqo[50], arqt[50];
		
		sprintf(arqo,".\\%c\\output\\%d.txt", exercicio, i);
		output=fopen(arqo,"r");
		while(fscanf(output,"%s",output1) !=EOF)
		
		fflush(stdout);
		fclose(output);
		
		sprintf(arqt,".\\%c\\temp\\%d.txt", exercicio, i);
		temp=fopen(arqt,"r");
		while(fscanf(temp,"%s",tempr) !=EOF)
		
		fflush(stdout);
		fclose(temp);
		
		if(strcmp(tempr,output1)==0){
			printf("Caso %d [OKAY] \n", i);
		}else{
			printf("Caso %d [ERRO] \n", i);
		}
	}
}
