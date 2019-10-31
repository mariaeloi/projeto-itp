#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>
//void criaImagem()

void salvaImagem(FILE *comandos, FILE *arquivoImagem, Pixel **matrizImagem, int largura, int altura){
	char nomeImagem[31];
  	int i, j;
  	fscanf(comandos, " %s", nomeImagem);
  	fseek(comandos, 0, SEEK_CUR);
  	arquivoImagem = fopen(nomeImagem, "w");
	if(arquivoImagem == NULL){
		printf("Erro na abertura do arquivo.\n");
		return; 
	}
  	fprintf(arquivoImagem, "P3\n%d %d\n255\n", largura, altura);
  	for(i=0; i<largura; i++){
    	for(j=0; j<altura; j++){
      		fprintf(arquivoImagem, "%d %d %d\n", matrizImagem[i][j].r, matrizImagem[i][j].g, matrizImagem[i][j].b);
    	}
  	}
  	fclose(arquivoImagem);
}

void limpaImagem(FILE *comandos, Pixel **matrizImagem, int largura, int altura){
  	int i, j;
  	Pixel cor;
  	fscanf(comandos, " %d %d %d", &cor.r, &cor.g, &cor.b);
  	fseek(comandos, 0, SEEK_CUR);
  	for(i=0; i<largura; i++){
    	for(j=0; j<altura; j++){
      		matrizImagem[i][j] = cor;
    	}
  	}
}