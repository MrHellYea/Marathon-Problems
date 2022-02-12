#include <stdio.h>
#include <math.h>


int main() {
	int w, h;
	double r, r2, v, v2, max;
	
	scanf("%i %i", &w, &h);
	while (w + h > 0) {
		r = w  / (2 * M_PI);
		
		if (w / 2.0 < h / (2 + 2 * M_PI))
			r2 = w / 2.0;
		else
			r2 = h / (2 + 2 * M_PI);
		
		v = M_PI * pow(r, 2) * (h - 2 * r);
		v2 = M_PI * pow(r2, 2) * w;
		
		
		if (v >= v2)
			max = v;
		else 
			max = v2;
		
		printf("%.3lf\n", max);
		scanf("%i %i", &w, &h);
	}
	
	return 0;
}
