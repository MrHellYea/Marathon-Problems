#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int compare(const void*, const void*);


int *crivo(int);


int *tabela_primos(int, int*);


int fatora(int, int*, int*);


int divs(int*, int, int*);


int mmc(long long int, long long int);


int main() {
	int t, a, b, num_fats, total, i, flag;
	long long int aux;

	int *vet = crivo(ceil(sqrt(1000000)));
	int *tabela = tabela_primos(ceil(sqrt(1000000)), vet);
	int *fats = malloc(sizeof(int) * 50);
	int *divs_vet = malloc(sizeof(int) * 1000);
	
	
	scanf("%i %i %i", &t, &a, &b);
	while (t + a + b > 0) {
		num_fats = fatora(t, tabela, fats);
		total = divs(fats, num_fats, divs_vet);
		
		flag = 0;
		aux = mmc(a, b);
		qsort(divs_vet, total, sizeof(int), compare);
		for (i = 1; i <= total; i++) {
			if (mmc(aux, divs_vet[i]) == t) {
				if (!flag)
					printf("%i", divs_vet[i]);
				else 
					printf(" %i", divs_vet[i]);
				flag = 1;
			}
		} printf("\n");
		scanf("%i %i %i", &t, &a, &b);
	}

	return 0;
}


int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
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


int fatora(int n, int *tabela, int *fats) {
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


int divs(int *fats, int num_fats, int *vet) {
	int num_divs = 1, i, j, k, num_divs_aux, total = 0;
	fats[0] = 1;
	vet[1] = 1;
	vet[0] = 0;
	
	for (i = 1; i <= num_fats; i++) {
		if (fats[i] == fats[i - 1])
			k *= fats[i];
		else {
			k = fats[i];
			num_divs_aux = num_divs;
		}
		
		for (j = 1 ; j <= num_divs_aux; j++) {
			num_divs++;
			vet[num_divs] = k * vet[j];
		}
	}
	
	return num_divs;
}


int mmc(long long int a, long long int b) {
	int resto, a_aux = a, b_aux = b;

    do {
        resto = a_aux % b_aux;

        a_aux = b_aux;
        b_aux = resto;

    } while (resto != 0);

    return (a * b) / a_aux;
}
