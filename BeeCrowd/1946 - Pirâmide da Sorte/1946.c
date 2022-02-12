#include <stdio.h>
#include <stdlib.h>


float **mat;


void free_mat(float**, int);


void build(float**, int);


int main() {
	int i, j, n;
	
	scanf("%i", &n);

	mat = malloc(sizeof(float*) * n);	
	for (i = 0; i < n; i++)
		mat[i] = malloc(sizeof(float) * n);
	mat[0][0] = 1;
	
	build(mat, n);
	
	/*for (i = 0; i < n; i++) {
		for (j = 0; j <= i ; j++)
			printf("%f ", mat[i][j]);
		printf("\n");
	}*/
	
	
	printf("%.2f\n", mat[n - 1][n / 2] * 100);
	return 0;
}


void free_mat(float **mat, int size) {
	int i;
	
	for (i = 0; i < size; i++)
		free(mat[i]);
	
	free(mat);
}


void build(float **mat, int size) {
	int i, j;
	
	for (i = 1; i < size; i++) {
		for (j = 0; j <= i; j++) {
			if (j - 1 >= 0)
				mat[i][j] = (mat[i - 1][j - 1] + mat[i - 1][j]) * 0.5;
			else
				mat[i][j] = mat[i - 1][j] * 0.5;
		}
	}
}
