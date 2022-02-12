#include <stdio.h>
#include <math.h>


int check_prime(long long int);


int main() {
	long long int x;
	int n, i;
	
	scanf("%i", &n);
	for (i = 0; i < n; i++) {
		scanf("%lli", &x);
		
		if (x > 1) {
			if (check_prime(x))
				printf("Prime\n");
			else
				printf("Not Prime\n");
		}
	}
	
	return 0;
}


int check_prime(long long int n) {
	int i;
	
	if (n % 2 == 0 && n > 2)
		return 0;
	
	for (i = 3; i < ceil(sqrt(n)); i += 2) {
		if (n % i == 0)
			return 0;
	}	
		
	return 1;
}
