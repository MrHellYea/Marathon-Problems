#include <stdio.h>


int scsm(int*, int, int);


int main() {
	int i, n, custo, receitas[50];
	
	while (scanf("%i", &n) != EOF) {
		scanf("%i", &custo);
	
		for (i = 0; i < n; i++)
			scanf("%i", &receitas[i]);
		
		printf("%i\n", scsm(receitas, n, custo));
	}

	return 0;
}


int scsm(int *vet, int n, int custo) {
	int i, sm = 0, im = 0, fm = 0, ss = 0, is = 0, fs = 0;
	
	for (i = 0; i < n; i++) {
		if (ss + vet[i] - custo >= 0) {
			ss += vet[i] - custo;
			fs = i;
			if (is = 0)
				is = i;
			if (ss > sm) {
				sm = ss;
				im = is;
				fm = fs;
			}
		} else {
			ss = 0;
			is = 0;
			fs = 0;
		}
	}
	
	return sm;
}
