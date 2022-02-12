#include <stdio.h>
#include <math.h>


double area(double, double, double);


int main() {
	double l1, l2, l3;
	
	while (scanf("%lf %lf %lf", &l1, &l2, &l3) != EOF) {
		printf("%.3lf\n", area(l1, l2, l3));
	}
	
	return 0;
}


double area(double l1, double l2, double l3) {
	double p = (l1 + l2 + l3) / 2;
	double result = 4.0 / 3 * sqrt(p * (p - l1) * (p - l2) * (p - l3));
	
	if (result > 0) 
		return result;
	
	return -1;
}
