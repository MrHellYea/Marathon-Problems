#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main() {
	int i, c, n, l, b, B, H, flag;
	double hi, hf, hx, bx, lx;

	scanf("%i", &c);
	
	for (i = 0; i < c; i++) {
		scanf("%i %i %lli %i %i", &n, &l, &b, &B, &H);
		hi = 0;
		hf = H;
		flag = 0;
		
		while (flag == 0) {
			hx = (hf + hi) / 2;
			bx = b + (B - b) * hx / H;
			lx = n * M_PI * hx * (b * b + b * bx + bx * bx) / 3;
			
			if (fabs(lx - l) < 0.00001)
				flag = 1;
			else if (l < lx)
				hf = hx;
			else 
				hi = hx;
		}
		
		printf("%.2lf\n", hx); 
	}
	
    return 0;
}
