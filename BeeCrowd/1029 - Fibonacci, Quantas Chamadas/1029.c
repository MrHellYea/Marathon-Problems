#include <stdio.h>\


int fib(int);


int num_calls;


int main() {
	int i, casos, x;
	
	scanf("%i", &casos);
	for (i = 0; i < casos; i++) {
		int result;
		num_calls = 0;
		scanf("%i", &x);
		
		result = fib(x);
		
		printf("fib(%i) = %i calls = %i\n", x, num_calls, result);
	}
	
	return 0;
}


int fib(int n) {
	if (n == 1) 
		return 1;
	if (n == 0) 
		return 0;	
	else {
		num_calls += 2;
		return fib(n - 1) + fib(n - 2);
	}
}
