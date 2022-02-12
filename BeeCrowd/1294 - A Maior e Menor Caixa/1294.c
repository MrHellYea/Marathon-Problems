#include <stdio.h>
#include <math.h>


int main() {
	double l, w, r1, r2, a = 12, b, c, max, min;

	while (scanf("%lf %lf", &l, &w) == 2) {
		b = -4 * (l + w);
		c = l * w;
		r1 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / 24;
		r2 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / 24;
		
		if (r2 > r1)
			max = r1;
		else
			max = r2;
		
		if (l == w) {
			if (max == r1)
				min = r2;
			else
				min = r1;
		} else {
			if (l > w)
				min = w;
			else
				min = l;
			min /= 2;
		}
		
		printf("%.3lf 0.000 %.3lf\n", max, min);
	}

	return 0;
}
