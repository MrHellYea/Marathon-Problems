#include <stdio.h>


long long int pow2(int, int);


int main() {
	int n;
	long long int total;
	scanf("%i", &n);
	while (n != 0) {
		total = (pow2(n, 4) + 6*pow2(n, 3)+ 11*pow2(n, 2) + 6*n) / 24; //fat(3 + n) / (24 * fat(n - 1));
	
		if (n >= 4)
			total += (pow2(n, 4) - 6*pow2(n, 3) + 11*pow2(n, 2) - 6*n) / 24;//fat(n) / (24 * fat(n - 4));

		printf("%lli\n", total % 1000007);
		scanf("%i", &n);
	}

	return 0;
}


long long int pow2(int base, int pot) {
	int i;
	long long int total = 1;
	
	for (i = 0; i < pot; i++)
		total *= base;
	
	return total;
}
