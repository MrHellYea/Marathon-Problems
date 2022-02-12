#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int smc(char*, char*);


int main() {
	char busca[1001], artigo[1001];
	
	scanf("%s %s", busca, artigo);
	
	printf("%i\n", strlen(busca) + strlen(artigo) - smc(busca, artigo));
	
	return 0;
}


int smc(char *busca, char *artigo) {
	int i, j, k, l, len_bus = strlen(busca), len_art = strlen(artigo);
	
	int **mat = malloc(sizeof(int*) * (len_bus + 1));
	
	for (i = 0; i <= len_bus; i++) {
		mat[i] = malloc(sizeof(int) * (len_art + 1));
		mat[i][0] = 0;
	}
	
	for (j = 0; j <= len_art; j++)
		mat[0][j] = 0;

	for (i = 1; i <= len_bus; i++) {
		for (j = 1; j <= len_art; j++) {
			if (busca[i - 1] == artigo[j - 1])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else {
				if (mat[i - 1][j] >= mat[i][j - 1])
					mat[i][j] = mat[i - 1][j];
				else 
					mat[i][j] = mat[i][j - 1];
			}
		} 
	}

	return mat[len_bus][len_art];
}
