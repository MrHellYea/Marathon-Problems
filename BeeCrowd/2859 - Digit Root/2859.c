#include <stdio.h>
#include <string.h>
#include <stdlib.h>


long long int pow2(int, int);


long long int eleva(char[], char[]);


int main() {
	char *b = malloc(100001), *e = malloc(100001);
	
	scanf("%s %s", b, e);
	
	printf("%lli\n", eleva(b, e));
	
	return 0;
}


long long int pow2(int base, int pot) {
	long long int total = 1, i;
	
	for (i = 0; i < pot; i++)
		total *= base;
	
	total %= 9;

	if (!total)
		total = 9;

	
	return total;
}


long long int eleva(char base[], char pot[]) {
	long long int aux = 1;
	int i, base_i = base[0] - 48;
	
	for (i = 1; base[i] != '\0'; i++)
		base_i = (base_i + (base[i] - 48)) % 9;

	for (i = 0; i < strlen(pot) - 1; i++) {
		aux = (aux * pow2(pow2(base_i, pot[i] - 48), 10)) % 9;
		
		if (!aux)
			aux = 9;
	}

	aux = (aux * pow2(base_i, pot[strlen(pot) - 1] - 48)) % 9;

	if (!aux)
		aux = 9;
		
	return aux;
}
