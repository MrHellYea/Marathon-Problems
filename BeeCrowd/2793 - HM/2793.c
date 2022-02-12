#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long int parts(char *);

long long int power(int, int);


int main() {
	char *string = malloc(sizeof(char) * 10000007);
	
	scanf("%s", string);
	
	long long int ps = parts(string);
	
	printf("%lli\n", power(2, ps - 1));
	
	return 0;
}


long long int parts(char *string) {
	long long int ps[3] = {0, 0, 0}, i;

	for (i = 0; i < strlen(string); i++) {
		if (string[i] == 77) 
			ps[0]++;
		else 
			ps[1]++;
		
		if (ps[0] == ps[1])
			ps[2]++;
	}
	
	return ps[2] % 1000000007;
}


long long int power(int n, int k) {	
	long long int x;
	
	if (k == 0)
		return 1;
	else if (k % 2 != 0)
		return (power(n, k - 1) % 1000000007 * n % 1000000007) % 1000000007;
	else {
		x = power(n, k / 2) % 1000000007;
		return (x % 1000000007 * x % 1000000007) % 1000000007;
	}
}
