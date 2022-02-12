#include <stdio.h>
#include <math.h>
#include <stdlib.h>


long long int pow2(long long int, long long int, int);


int *crivo(int);


int *tabela_primos(int, int*);


void fatora(int, int*, int*);


struct nemsei {
	long long int d, x, y;
};


struct nemsei MDCE(long long int, long long int);


long long int InvMod(int, int);


int main() {
	int n, e, c, phi;
	long long int d;
	
	scanf("%i %i %i", &n, &e, &c);
	
	int *vet = crivo(ceil(sqrt(n)));
	int *tabela = tabela_primos(ceil(sqrt(n)), vet);
	int *fats = malloc(sizeof(int) * 50);
	
	fatora(n, tabela, fats);
	
	phi = (fats[1] - 1) * (fats[2] - 1);
	
	d = InvMod(e, phi);
	
	printf("%i\n", pow2(c, d, n) % n);
	
	return 0;
}


long long int pow2(long long int base, long long int pot, int mod) {	
	long long int x;
	
	if (pot == 0)
		return 1;
	else if (pot % 2 != 0)
		return (pow2(base % mod, pot - 1, mod) % mod * base % mod) % mod;
	else {
		x = pow2(base % mod, pot / 2, mod) % mod;
		return (x % mod * x % mod) % mod;
	}
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


void fatora(int n, int *tabela, int *fats) {
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


struct nemsei MDCE(long long int a, long long int b) {
	struct nemsei temp;
	long long int aux_x, aux_y;
	
	if (b == 0) {
		temp.d = a;
		temp.x = 1;
		temp.y = 0;
		
		return temp;
	} else {
		temp = MDCE(b, a % b);
		aux_x = temp.x;
		aux_y = temp.y;
		temp.x = aux_y;
		temp.y = aux_x - (a / b) * aux_y;
		
		return temp;
	}	
}


long long int InvMod(int b, int n) {
	struct nemsei temp;
	
	temp = MDCE(b, n);
	
	return (temp.x + n) % n;
}
