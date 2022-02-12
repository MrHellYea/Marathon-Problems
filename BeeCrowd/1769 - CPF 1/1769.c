#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	char str, string[24];
	int b1, b2, i, j;

	while (scanf("%s", string) != EOF) {
		i = 1;
		j = 0;
		b1 = b2 = 0;

		while (string[j] != '-') {
			if (string[j] != '.') {
				str = string[j];
				b1 += (str - '0') * i;
				b2 += (str - '0') * (10 - i);
				i++;
			}
			j++;
		}
	
		(b1 % 11) == 10 ? (b1 = 0) : (b1 = b1 % 11);
		(b2 % 11) == 10 ? (b2 = 0) : (b2 = b2 % 11);

		if (b1 == string[j + 1] - '0' && b2 == string[j + 2] - '0')
			printf("CPF valido\n");
		else 
			printf("CPF invalido\n");
	}
	
	return 0;
}
