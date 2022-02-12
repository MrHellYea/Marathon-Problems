#include <stdio.h>


int convert(char[]);


int main() {
	char string[112];
	
	scanf("%s", string);
	
	printf("%i\n", convert(string) % 3);

	return 0;
}


int convert(char string[]) {
	int i, total = 0;
	
	for (i = 0; string[i] != '\0'; i++)
		total += string[i] - 48;
	
	return total;
}
