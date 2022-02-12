#include <iostream>
#include <cmath>

using namespace std;

int factorize(int, int*);


int main() {
	int i, n, j, k = 0, is_prime;
	int answers[10001], primes[1300];
	
	for (j = 2; j <= 10000; j++) {
		is_prime = true;
		for (i = 2; i <= sqrt(j); i++) {
			if (j % i == 0) {
				i = j;
				is_prime = false;
			}
		}

		if (is_prime) 
			primes[k++] = j;
	}
	
	answers[0] = 1;
	for (i = 1; i <= 10000; i++) 
		answers[i] = factorize(i, primes);
	
	while (scanf("%i", &n) == 1) {
		if (n >= 0 && answers[n])
			printf("YES\n");	
		else
			printf("NO\n");
	}

    return 0;
}


int factorize(int n, int* vet) {
	int div = 2, counter = 0, index = 0;
	
	while (n != 1) {
		if (n % div == 0) {
			n /= div;
			counter++;
		} else {
			div = vet[index++];
			counter = 0;
		}
		
		if (counter > 0 && (div % 4) - 3 == 0 && n % div != 0) {
			if (!(counter % 2 == 0))
				return 0;
		}
	}
	
	return 1;
}
