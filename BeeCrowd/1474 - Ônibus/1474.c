#include <stdio.h>
#include <stdlib.h>


long long int pow2(long long int, long long int);

void create_mat(long long int**, long long int, long long int);

long long int **mult_mat(long long int**, long long int**);

long long int **power_mat(long long int**, long long int);


int main() {
	long long int n, k, l, total;
	int i, j;
	
	long long int **mat = malloc(sizeof(long long int*) * 2);
	long long int **mat_aux = malloc(sizeof(long long int*) * 2);
	for (i = 0; i < 2; i++) {
		mat[i] = malloc(sizeof(long long int) * 2);
		mat_aux[i] = malloc(sizeof(long long int) * 2);
	}
	
	while (scanf("%lli %lli %lli", &n, &k, &l) != EOF) {
		n /= 5;
		k %= 1000000;
		l %= 1000000;
		if (n == 1) 
			total = k%1000000;
		else if (n == 2) 
			total = (l%1000000 + pow2(k%1000000, 2))%1000000;
		else {
			create_mat(mat, k%1000000, l%1000000);
			mat_aux = power_mat(mat, n - 2);
			total = ((mat_aux[0][0] * (l%1000000 + pow2(k%1000000, 2))%1000000)%1000000 + (mat_aux[0][1] * k%1000000)%1000000)%1000000;
		}
		
		printf("%06lli\n", total);
	}
	
	return 0;
}


long long int pow2(long long int n, long long int k) {	
	long long int x;
	
	if (k == 0)
		return 1;
	else if (k % 2 != 0)
		return (pow2(n%1000000, k - 1)%1000000 * n%1000000)%1000000;
	else {
		x = pow2(n%1000000, k / 2)%1000000;
		return (x%1000000 * x%1000000)%1000000;
	}
}


void create_mat(long long int **mat, long long int k, long long int l) {
	int i, j;
	mat[0][0] = k; mat[0][1] = l;
	
	for (i = 1; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			mat[i][j] = 0;
			if (i - 1 == j)
				mat[i][j] = 1;
		}
	}
}


long long int **mult_mat(long long int **mat1, long long int **mat2) {
	int i, j, k;
	
	long long int **mat = malloc(sizeof(long long int*) * 2);
	
	for (i = 0; i < 2; i++)
		mat[i] = malloc(sizeof(long long int) * 2);	
	
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			mat[i][j] = 0;
			for (k = 0; k < 2; k++)
				mat[i][j] = (mat[i][j]%1000000 + (mat1[i][k]%1000000 * mat2[k][j]%1000000)%1000000)%1000000;
		}
	}
	
	return mat;
}


long long int **power_mat(long long int **mat1, long long int pot) {
	int i, j;

	if (pot == 0) {
		long long int **mat = malloc(sizeof(long long int*) * 2);
	
		for (i = 0; i < 2; i++)
			mat[i] = malloc(sizeof(long long int) * 2);	
		
		for (i = 0; i < 2; i++) {
			for (j = 0; j < 2; j++) {
				mat[i][j] = 0;
				if (i == j)
					mat[i][j] = 1;
			}
		}
		
		return mat;
	} else if (pot % 2 != 0) {
		return mult_mat(power_mat(mat1, pot - 1), mat1);
	} else {
		long long int **mat = malloc(sizeof(long long int*) * 2);
	
		for (i = 0; i < 2; i++)
			mat[i] = malloc(sizeof(long long int) * 2);	
		
		mat = power_mat(mat1, pot / 2);
		
		return mult_mat(mat, mat);
	}
}
