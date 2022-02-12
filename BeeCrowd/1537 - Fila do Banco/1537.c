#include <stdio.h>\


long long int fat(int);


int main() {
	int n;
	long int casos;
	
	scanf("%i", &n);
	while (n != 0) {
		casos = fat(n);
		
		printf("%li\n", casos);
		scanf("%i", &n);
	}

	return 0;
}


long long int fat(int n) {
	int i;
	long long int total = 1;
	
	for (i = 4; i <= n; i++)
		total = (total * i) % 1000000009;
	
	return total;
}
