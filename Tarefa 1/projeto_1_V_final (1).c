#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv) {//pegando os dados no terminal quando executamos o código
	char palavra[512], dados[512];
	int n, m, i, j, linha;
	FILE* ao;
	ao = fopen(argv[2], "r");	//entrada de dados
    strcpy(palavra, argv[1]);  // copiando a palavra para um char array
	m = strlen(palavra);
	linha = 0;

    if (argc < 1) {
        printf("Nao pode inserir valor numerico");
        return EXIT_FAILURE;
    }// caso coloque um valor no int

    if(ao == NULL) {// caso o arquivo não exista
        printf("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }

    //abrindo o arquivo e comparar cada linha para achar a palavra
	while (fgets(dados, 256, ao) != NULL) {
		i = 0;
		n = strlen(dados);
        //Loop para encontrar a palavra nos dados
		while (i < n) {
			//comparando palavra com a linha do arquivo que está nos dados
			j = 0;
			while (i < n && j < m && dados[i] == palavra[j]) {
				++i, ++j;
			}
			// Vendo se a palavra está na linha do dados  
			if ((i == n || dados[i] == ' ' || dados[i] == '\n') && j == m) {
				printf( "%d: %s \n", linha,dados);
			}
			// movendo para a próxima palavra
			while (i < n && dados[i] != ' ') {
				++i;
			}
			++i;
		}
		++linha;
	}
	fclose(ao);
    return 1;
}