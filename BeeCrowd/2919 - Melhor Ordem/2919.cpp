#include <stdio.h>


int binary_search(int*, int, int);


int scm(int*, int);


int main() {
	int i, n, vet[500001];
	
	while(scanf("%i", &n) != EOF) {
		for (i = 1; i <= n; i++)
			scanf("%i", &vet[i]);
		
		printf("%i\n", scm(vet, n));
	}
	
	return 0;
}


int binary_search(int *vet, int size, int element) {
	int start = 0, end = size - 1;
	
	while (start <= end) {		
		if (vet[((start + end) / 2)] == element)
			return ((start + end) / 2);
		else if (vet[((start + end) / 2)] > element)
			end = ((start + end) / 2) - 1;
		else
			start = ((start + end) / 2) + 1;
	}
	
	return end + 1;
}


int scm(int *vet, int size) {
	int i, j, k = 1, t[size];
	t[1] = vet[1];
	
	for (i = 2; i <= size; i++) {
		if (vet[i] > t[k]) {
			k++;
			t[k] = vet[i];
		} else {
			j = binary_search(t, k, vet[i]);
			t[j] = vet[i];
		}
	}
	
	return k;
}
