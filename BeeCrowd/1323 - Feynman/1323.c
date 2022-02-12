#include <stdio.h>
#include <math.h>


int pow2(int, int);


int main() {
	int n, i, total;
	
	scanf("%i", &n);
	while (n != 0) {
		total = 1;
		
		for (i = 2; i <= n; i++)
			total += pow2(i, 2);
	
		printf("%i\n", total);
		scanf("%i", &n);
	}

	return 0;
}


int pow2(int base, int pot) {
	int total = 1, i;
	
	for (i = 0; i < pot; i++)
		total *= base;
	
	return total;
}
