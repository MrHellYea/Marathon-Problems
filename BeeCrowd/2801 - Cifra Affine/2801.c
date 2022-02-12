#include <stdio.h>


struct nemsei {
	long long int d, x, y;
};


struct nemsei MDCE(long long int, long long int);


long long int InvMod(long long int, long long int);


int main() {
	int n, t, a, b, i;

	scanf("%i", &n);
	
	int vet[n];

	for (i = 0; i < n; i++)
		scanf("%i", &vet[i]);
	
	scanf("%i %i %i", &t, &a, &b);

	if (MDCE(a, t).d == 1) {
		for (i = 0; i < n; i++)
			vet[i] = ((((((vet[i] % t) - (b % t)) % t) * InvMod(a, t)) % t) + t) % t;
		
		printf("%i", vet[0]);
		for (i = 1; i < n; i++)
			printf(" %i", vet[i]);
		printf("\n");
	} else 
		printf("DECIFRAGEM AMBIGUA\n");
	
	return 0;
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


long long int InvMod(long long int b, long long int n) {
	struct nemsei temp;
	
	temp = MDCE(b, n);
	
	return (temp.x + n) % n;
}
