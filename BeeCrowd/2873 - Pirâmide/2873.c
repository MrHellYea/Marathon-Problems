#include <stdio.h>

int main() {
    double a, b, c, d;
    
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    while (a + b + c + d > 0)  {
        printf("%.5lf\n", (a / 2 + b) * c / d);
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	}
	
    return 0;
}
