#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int compare(const void *a, const void *b) {
  return (*(int*)a - *(int*)b);
}


void print_value(float);


float dist_ed(char**, char**, int, int, int);


float min(float, float, float);


int main() {
	int i, j, t, r, m, n;

	char **mat = malloc(sizeof(char*) * 101);
	for (i = 0; i < 101; i++)
		mat[i] = malloc(51);
	
	char **mat2 = malloc(sizeof(char*) * 101);
	for (i = 0; i < 101; i++)
		mat2[i] = malloc(51);
	
	scanf("%i", &t);
	
	for (i = 1; i <= t; i++) {
		scanf("%i %i", &r, &m);
		
		for (j = 1; j <= m; j++) 
			scanf("%s", mat[j]);

		scanf("%i", &n);
		
		for (j = 1; j <= n; j++) 
			scanf("%s", mat2[j]);

		if (!m && !n) {
			printf("Caso #%i: R$ 0,00\n", i);
		} else if (!m) {
			printf("Caso #%i: R$ ", i);
			print_value(2.5 * n * r);
		} else if (!n) {
			printf("Caso #%i: R$ ", i);
			print_value(0.5 * m * r);
		} else {
			printf("Caso #%i: R$ ", i);
			print_value(dist_ed(mat, mat2, m, n, r));
		}
	}
	
	return 0;
}


void print_value(float value) {
	int i = value;
	float f = value - i;
	
	printf("%i,%.2i\n", i, (int) round(f * 100));
}    


float dist_ed(char **mat, char **mat2, int m, int n, int r) {
	int i, j;

	float **matr = malloc(sizeof(float*) * (m + 1));
	
	for (i = 0; i <= m; i++) {
		matr[i] = malloc(sizeof(float) * (n + 1));
		matr[i][0] = i * 0.5 * r;
	}
	
	for (i = 0; i <= n; i++)
		matr[0][i] = i * 2.5 * r;
	
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (!strcmp(mat[i], mat2[j]))
				matr[i][j] = matr[i - 1][j - 1];
			else
				matr[i][j] = min(matr[i - 1][j - 1] + r, matr[i - 1][j] + (0.5 * r), matr[i][j - 1] + (r * 2.5));
		}
	}
	
	return matr[m][n];
}


float min(float a, float b, float c) {
	float vet[3] = {a, b, c};
	
	qsort(vet, 3, sizeof(float), compare);
	
	return vet[0];
}
