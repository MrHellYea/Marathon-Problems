#include <stdio.h>
#include <math.h>


double area(int);


int main() {
	int i, c, n;

	scanf("%i", &c);
	
	for (i = 0; i < c; i++) {
		scanf("%i", &n);
		
		printf("%.3lf\n", area(n));
	}

	return 0;
}


double area(int n) {
	return (5 * n * ((n / 2.0) / tan(36 * M_PI / 180))) / 2;
}
