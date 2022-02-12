#include <stdio.h>


int main() {
	int n, i, p, r, changes, found;
	
	while (scanf("%i", &n) != EOF) {
		changes = 0;
		found = 0;
		for (i = 1; i < n; i++) {
			scanf("%i %i", &p, &r);
			if (p == n) {
				if (r == 0)
					changes++;
				found = 1;
			} else if (found == 1 && r == 1)
				changes++;
		}
		printf("%i\n", changes);
	}

	return 0;
}
