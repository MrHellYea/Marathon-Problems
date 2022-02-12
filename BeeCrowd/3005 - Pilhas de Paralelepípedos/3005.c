#include <stdio.h>
#include <stdlib.h>


int compare (const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}


int main() {
	int i, n, result, p1[3], p2[3];
	
	scanf("%i", &n);
	for (i = 0; i < n; i++) {
		result = 0;
		scanf("%i %i %i %i %i %i", &p1[0], &p1[1], &p1[2], &p2[0], &p2[1], &p2[2]);
		qsort(p1, 3, sizeof(int), compare);
		qsort(p2, 3, sizeof(int), compare);
		
		if (p2[1] > p1[0] && p2[2] > p1[1])
			result = 1;
		if (p1[1] > p2[0] && p1[2] > p2[1]) {
			if (result)
				result = 3;
			else
				result = 2;
		}
		
		printf("%i\n", result);
	}
	
	return 0;
}
