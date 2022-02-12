#include <stdio.h>


long long int pow2(int, long long int);


int main() {
	long long int r;
	
	scanf("%lli", &r);
		
	printf("%lli\n", pow2(3, r));
	
	return 0;
}


long long int pow2(int base, long long int pot) {	
	long long int x;
	
	if (pot == 0)
		return 1;
	else if (pot % 2 != 0)
		return (pow2(base % 2147483647, pot - 1) % 2147483647 * base % 2147483647) % 2147483647;
	else {
		x = pow2(base % 2147483647, pot / 2) % 2147483647;
		return (x % 2147483647 * x % 2147483647) % 2147483647;
	}
}
