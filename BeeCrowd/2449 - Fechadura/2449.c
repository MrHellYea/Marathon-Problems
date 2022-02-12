#include <stdio.h>

int main() {
	int m, current, aux = 0, moves = 0;
	scanf("%*i %i", &m);
	
	while (scanf("%i", &current) == 1) {
		current += aux;

		if (current >= m) {
			moves += current - m;
			aux = m - current;
		} else if (m > current) {
			moves += m - current;
			aux = m - current;
		}
	}
	
	printf("%i\n", moves);
	
	return 0;
}
