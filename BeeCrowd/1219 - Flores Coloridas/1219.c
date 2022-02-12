#include <stdio.h>
#include <math.h>


void areas(int, int, int, double*, double*, double*);


int main() {
	int a, b, c;
	double a1, a2, a3;
	
	while (scanf("%i %i %i", &a, &b, &c) != EOF) {
		areas(a, b, c, &a1, &a2, &a3);
		printf("%.4lf %.4lf %.4lf\n", a1, a2, a3);
	}
	
	return 0;
}


void areas(int a, int b, int c, double *a1, double *a2, double *a3) {
	double p = (a + b + c) / 2.0;
	double tri = sqrt(p * (p - a) * (p - b) * (p - c));
	
	*a1 = M_PI * pow(a * b * c / (4 * tri), 2) - tri;
	*a3 = M_PI * pow(tri / p, 2);
	*a2 = tri - *a3;
}
