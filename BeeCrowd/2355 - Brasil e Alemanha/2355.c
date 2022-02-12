#include <stdio.h>
#include <math.h>


int main() {
	int n, br;
	double al;
	
	scanf("%ld", &n);
	while (n != 0)
	{
		br = n / 90;
		al = ceil((n / 90.0) * 7);
		
		printf("Brasil %i x Alemanha %.0f\n", br, al);
		scanf("%ld", &n);
	}

	return 0;
}
