#include <stdio.h>
#include <stdlib.h>

void create_mat(long long int**);

long long int **mult_mat(long long int**, long long int**, long long int**);

long long int **power_mat(long long int**, long long int);

int main() {
	long long int n;
	int total, i;

	long long int **mat = malloc(sizeof(long long int*) * 3);
	long long int **mat_aux = malloc(sizeof(long long int*) * 3);
	for (i = 0; i < 3; i++) {
		mat[i] = malloc(sizeof(long long int) * 3);
		mat_aux[i] = malloc(sizeof(long long int) * 3);
	}
	
	while (scanf("%lli", &n) != EOF) {
		if (n == 1) 
			total = 1;
		else if (n == 2 || n == 3)
			total = 2;
		else {
			create_mat(mat);
			mat_aux = power_mat(mat, n - 3);
			total = ((mat_aux[0][0] * 2)%1000000007 + (mat_aux[0][1] * 2)%1000000007 + mat_aux[0][2])%1000000007;
		}
		
		printf("%i\n", total);
	}
	
	return 0;
}


void create_mat(long long int **mat) {
	int i, j;
	mat[0][0] = 0; mat[0][1] = 1; mat[0][2] = 1;
	
	for (i = 1; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			mat[i][j] = 0;
			if (i - 1 == j)
				mat[i][j] = 1;
		}
	}
	
}


long long int **mult_mat(long long int **mat1, long long int **mat2, long long int **mat3) {
	int i, j, k;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			mat3[i][j] = 0;
			for (k = 0; k < 3; k++)
				mat3[i][j] = (mat3[i][j]%1000000007 + (mat1[i][k]%1000000007 * mat2[k][j]%1000000007)%1000000007)%1000000007;
		}
	}
	
	return mat3;
}


long long int **power_mat(long long int **mat1, long long int pot) {
	int i, j;
	
	long long int **mat = malloc(sizeof(long long int*) * 3);
	
	for (i = 0; i < 3; i++)
		mat[i] = malloc(sizeof(long long int) * 3);
	
	if (pot == 0) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				mat[i][j] = 0;
				if (i == j)
					mat[i][j] = 1;
			}
		}
		
		return mat;
	} else if (pot % 2 != 0) {
		return mult_mat(power_mat(mat1, pot - 1), mat1, mat);
	} else {
		long long int **mat2 = malloc(sizeof(long long int*) * 3);
		
		for (i = 0; i < 3; i++)
			mat2[i] = malloc(sizeof(long long int) * 3);
		
		mat = power_mat(mat1, pot / 2);
		
		return mult_mat(mat, mat, mat2);
	}
}
