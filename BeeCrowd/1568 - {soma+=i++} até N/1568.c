#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int *crivo(int);


int *tabela_primos(int, int*);


int fatora(long long int, int*, int*);


int divs(int*, int);


int main() {
	long long int n;
	int num_fats, total;

	int *vet = crivo(ceil(sqrt(900000000000001)));
	int *tabela = tabela_primos(ceil(sqrt(900000000000001)), vet);
	
	while (scanf("%lli", &n) != EOF) {
		int *fats = malloc(sizeof(int) * 50);
		
		if (n == 0)
			total = 0;
		else {
			num_fats = fatora(n, tabela, fats);
			total = divs(fats, num_fats);
		}
		
		printf("%i\n", ++total);
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


int fatora(long long int n, int *tabela, int *fats) {
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
	
	return nf;
}


int divs(int *fats, int num_fats) {
	int *vet = malloc(sizeof(int) * 1000);
	int num_divs = 1, i, j, k, num_divs_aux, total = 0;
	fats[0] = 1;
	vet[1] = 1;
	
	for (i = 1; i <= num_fats; i++) {
		if (fats[i] == fats[i - 1])
			k *= fats[i];
		else {
			k = fats[i];
			num_divs_aux = num_divs;
		}
		
		for (j = 1 ; j <= num_divs_aux; j++) {
			if (k * vet[j] % 2 != 0)
				total++;
			
			num_divs++;
			vet[num_divs] = k * vet[j];
		}
	}
	
	return total;
}
