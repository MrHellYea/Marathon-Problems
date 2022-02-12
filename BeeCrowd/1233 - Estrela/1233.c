#include <stdio.h>
#include <stdlib.h>
#include <math.h>


long long int pow2(long long int, long long int);


long long int *crivo(long long int);


long long int *tabela_primos(long long int, long long int*);


long long int fatora(long long int, long long int*, long long int*);


long long int euler(long long int*, long long int);


int main() {
	long long int n, num_fats, co_primes;

	long long int *vet = crivo(ceil(sqrt(2147483647)));
	long long int *tabela = tabela_primos(ceil(sqrt(2147483647)), vet);
	
	while (scanf("%lli", &n) == 1) {
		long long int *fats = malloc(sizeof(long long int) * 50);
		
		num_fats = fatora(n, tabela, fats);
		co_primes = euler(fats, num_fats);
		
		printf("%lli\n", co_primes / 2);
		//free(fats);
	}

	return 0;
}


long long int pow2(long long int base, long long int pot) {
	long long int total = 1, i;
	
	for (i = 0; i < pot; i++)
		total *= base;
	
	return total;
}


long long int *crivo(long long int n) {
	long long int *vet = malloc(sizeof(long long int) * (n + 1));
	long long int i, t, d;
	
	vet[0] = 0;
	
	for (i = 1; i <= n; i++) {
		vet[i] = i + 1;
		
		if (i % 2 != 0)
			vet[i] = 2;
	}
	
	for (i = 3; i <= ceil(sqrt(n)); i++) {
		if (vet[i - 1] == i) {
			t = i * i;
			d = i + i;
			
			while (t <= n) {
				if (vet[t - 1] == t)
					vet[t - 1] = i;
				t += d;
			}
		}
	}
	
	return vet;
}


long long int *tabela_primos(long long int n, long long int *crivo) {
	long long int np = 0;
	int i;
	
	long long int *vet = malloc(sizeof(long long int) * (n + 1));
	
	for (i = 2; i <= n; i++) {
		if (crivo[i - 1] == i)
			vet[++np] = i;
	}
	
	vet[0] = np;
	
	return vet;
}


long long int fatora(long long int n, long long int *tabela, long long int *fats) {
	long long int nf = 0, i, np = tabela[0];

	for (i = 1; i <= np; i++) {
		while (n % tabela[i] == 0) {
			fats[++nf] = tabela[i];
			n /= tabela[i];
		}
		if (n == 1)
			break;
	}
	
	if (n != 1) 
		fats[++nf] = n;
	
	fats[0] = nf;
	
	return nf;
}


long long int euler(long long int *fats, long long int nf) {
	long long int total = 1, aux = 1, i;
	
	for (i = 1; i <= nf; i++) {
		if (fats[i + 1] == fats[i])
			aux++;
		else {
			total *= pow2(fats[i], aux) - pow2(fats[i], aux - 1);
			aux = 1;
		}
	}

	return total;
}
