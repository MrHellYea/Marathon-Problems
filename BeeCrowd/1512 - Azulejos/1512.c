#include <stdio.h>


int mmc(int, int);


int main() {
	int n, a, b, total;

	scanf("%i %i %i", &n, &a, &b);
	while (n != 0 || a != 0 || b != 0) {
		total = 0;

		total += (n / a) + (n / b) - (n / mmc(a, b));
		printf("%i\n", total);
		
		scanf("%i %i %i", &n, &a, &b);
	}

	return 0;
}


int mmc(int num1, int num2) {
	int resto, a, b;

    if (num1 > num2) {
		a = num1;
		b = num2;
	} else {
		a = num2;
		b = num1;
	}

    do {
        resto = a % b;

        a = b;
        b = resto;

    } while (resto != 0);

    return (num1 * num2) / a;
}
