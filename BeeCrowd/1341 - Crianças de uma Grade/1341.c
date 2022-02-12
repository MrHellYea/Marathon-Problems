#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int smc(char*, char*);


int main() {
	int i, j, t, h, w, n0, x0, y0, n1, x1, y1, aux;
	
	scanf("%i", &t);
	
	for (i = 1; i <= t; i++) {
	    scanf("%i %i", &h, &w);
		
		char **mat = malloc(sizeof(char*) * h);
		for (j = 0; j < h; j++) {
			mat[j] = malloc(w + 2);
			scanf("%s", mat[j]);
		}
		
		scanf("%i %i %i", &n0, &x0, &y0);
		
		char string1[n0 + 2];
		if (n0)
			scanf("%s", string1);
		else 
			scanf("[^\n]", string1);
			
		scanf("%i %i %i", &n1, &x1, &y1);
	
		char string2[n1 + 2];
		if (n1)
			scanf("%s", string2);
		else 
			scanf("[^\n]", string2);

		char *path1 = malloc(n0 + 2);
		char *path2 = malloc(n1 + 2);
		
		for (j = 0; j <= n0; j++) {
			path1[j] = mat[x0 - 1][y0 - 1];
			
			if (n0) {
				if (string1[j] == 'N')
					x0--;
				else if (string1[j] == 'S')
					x0++;
				else if (string1[j] == 'W')
					y0--;
				else
					y0++;
			}
		} path1[j] = '\0';
		

		for (j = 0; j <= n1; j++) {
			path2[j] = mat[x1 - 1][y1 - 1];
			
			if (n1) {
				if (string2[j] == 'N')
					x1--;
				else if (string2[j] == 'S')
					x1++;
				else if (string2[j] == 'W')
					y1--;
				else
					y1++;
			}
		} path2[j] = '\0';
		
		aux = smc(path1, path2);
		printf("Case %i: %i %i\n", i, ++n0 - aux, ++n1 - aux);
	}
	
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
