#include <stdio.h>
#include <math.h>


double pit(int, int);


int main() {
	int l, c, r1, r2;
	char result;
	
	scanf("%i %i %i %i", &l, &c, &r1, &r2);
	while (l + c + r1 + r2 > 0) {		
		if (r1 * 2 <= l && r1 * 2 <= c && r2 * 2 <= l && r2 * 2 <= c) {			
			if (r1 + r2 <= pit(l - r1 - r2, c - r1 - r2))
				result = 'S';
			else
				result = 'N';
		} else
			result = 'N';
		
		printf("%c\n", result);
		scanf("%i %i %i %i", &l, &c, &r1, &r2);
	}
	
	return 0;
}


double pit(int s1, int s2) {
	return sqrt(pow(s1, 2) + pow(s2, 2));
}
