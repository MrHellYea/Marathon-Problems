#include <stdio.h>


struct nemsei {
	int d;
	int x;
	int y;
};


struct nemsei MDCE(int, int);


int InvMod(int, int);


long long int tcr(int[], int[]);


int main() {
	int per_bag[3], left[3], i, j = 1;
	
	while (scanf("%i %i", &left[0], &per_bag[0]) == 2) {
		for (i = 1; i < 3; i++)
			scanf("%i %i", &left[i], &per_bag[i]);

		printf("Caso #%i: %lli laranja(s)\n", j++, tcr(left, per_bag));
	}
	
	return 0;
}


struct nemsei MDCE(int a, int b) {
	struct nemsei temp;
	int aux_x, aux_y;
	
	if (b == 0) {
		temp.d = a;
		temp.x = 1;
		temp.y = 0;
		
		return temp;
	} else {
		temp = MDCE(b, a % b);
		aux_x = temp.x;
		aux_y = temp.y;
		temp.x = aux_y;
		temp.y = aux_x - (a / b) * aux_y;
		
		return temp;
	}	
}


int InvMod(int b, int n) {
	struct nemsei temp;
	
	temp = MDCE(b, n);
	
	return (temp.x + n) % n;
}


long long int tcr(int resto[], int mochila[]) {
	long long int ns[3], total = 0, answer;
	int i, n = 1, xs[3];
	
	for (i = 0; i < 3; i++)
		n *= mochila[i];
	
	for (i = 0; i < 3; i++)
		ns[i] = n / mochila[i];
	
	for (i = 0; i < 3; i++)
		xs[i] = InvMod(ns[i], mochila[i]);
	
	for (i = 0; i < 3; i++)
		total += resto[i] * xs[i] * ns[i];

	answer = total % n;
	
	if (answer == 0)
		return n;
	
	return answer;
}
