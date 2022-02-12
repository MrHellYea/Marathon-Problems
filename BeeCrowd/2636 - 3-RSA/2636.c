#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int *crivo(int);


int *tabela_primos(int, int*);


void fatora(long long int, int*, int*);


int main() { 
	long long int n;
	int *vet = crivo(1000000); 
	int *tabela = tabela_primos(1000000, vet);
	int *fats = malloc(sizeof(int) * 50);
	
	scanf("%lli", &n);
	while (n != 0) {
		fatora(n, tabela, fats);
		
		printf("%lli = %i x %i x %i\n", n, fats[1], fats[2], fats[3]);
		scanf("%lli", &n);
	}

	return 0;
}
 

int *crivo(int n) {
	int *vet = malloc(sizeof(int) * (n + 1));
	int i, t, d;
	
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


int *tabela_primos(int n, int *crivo) {
	int np = 0;
	int i;
	
	int *vet = malloc(sizeof(int) * (n + 1));
	
	for (i = 2; i <= n; i++) {
		if (crivo[i - 1] == i)
			vet[++np] = i;
	}
	
	vet[0] = np;
	
	return vet;
}


void fatora(long long int n, int *tabela, int *fats) {
	int nf = 0, i, np = tabela[0];

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
}
