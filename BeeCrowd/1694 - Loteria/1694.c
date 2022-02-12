#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int check_prime(int);


long long int fat(int);


long long int comb(int, int);


int main() {
	long long int total;
	int n, m, k, i, j, zeros;

	scanf("%i %i %i", &n, &m, &k);
	while (n + m + k > 0) {
		int **mat = malloc(sizeof(int*) * n);
		
		for (i = 0; i < n; i++) {
			mat[i] = malloc(sizeof(int) * m);
			for (j = 0; j < m; j++) {
				if (check_prime(i * m + j))
					mat[i][j] = 1;
				else
					mat[i][j] = 0;
			}
		}
		
		total = 0;

		if (n == 1 && m == 1 && k == 1) 
			total = 1;
		else {
			if (m > 1) {
				for (i = 0; i < n; i++) {  
					zeros = 0;
					for (j = 0; j < m; j++) {
						if (mat[i][j] == 0)
							zeros++;
					}
					total += comb(zeros, k);
				}
			}
			
			if (n > 1) {
				for (i = 0; i < m; i++) {  
					zeros = 0;
					for (j = 0; j < n; j++) {
						if (mat[j][i] == 0)
							zeros++;
					}
					total += comb(zeros, k);
				}
			}
		}
		
		if (n > 1 && m > 1 && k == 1)
			total /= 2;
		
		printf("%lli\n", total);
		scanf("%i %i %i", &n, &m, &k);
	}

	return 0;
}


int check_prime(int n) {
	int i;
	
	if ((n % 2 == 0 && n > 2) || n == 0 || n == 1)
		return 0;
	
	for (i = 3; i <= ceil(sqrt(n)); i += 2) {
		if (n % i == 0)
			return 0;
	}	
		
	return 1;
}


long long int fat(int n) {
	long long int i, total = 1;
	
	for (i = 2; i <= n; i++)
		total *= i;
	
	return total;
}


long long int comb(int n, int p) {
	long long int total = 1, fim, i;
	
	if (n == p)
		return 1;
	
	if (p > n)
		return 0;
	
	else if (p > n - p)
		fim = p;
	else 
		fim = n - p;
	
	for (i = n; i > fim; i--)
		total *= i;
	
	return total / fat(n - fim);
}
