#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double distAB(int xa, int ya, int xi, int yi) {
    return sqrt(((yi - ya) * (yi - ya)) + ((xi - xa) * (xi - xa)));
}


int BuscaBin(double*, double, double, double);


int scm(double*, double*, int);


void quicksort(double*, double*, int, int);


int main() {
	int i, n, xa, xb, xi, yi;
	double a, b, c;
	
	scanf("%i %i %i", &n, &xa, &xb);
	
	double *angs_a = malloc(sizeof(double) * (n + 1));
	double *angs_b = malloc(sizeof(double) * (n + 1));
	
	for (i = 1; i <= n; i++) {
		scanf("%i %i", &xi, &yi);
		a = distAB(xb, 0, xi, yi);
		b = distAB(xa, 0, xi, yi);
		c = xb - xa;
		angs_a[i] = acos((b * b + c * c - a * a) / (2 * b * c));
		angs_b[i] = acos((a * a + c * c - b * b) / (2 * a * c));
	}

	quicksort(angs_a, angs_b, 1, n);

	printf("%i\n", scm(angs_b, angs_a, n));

	return 0;
}


int BuscaBin(double *T, double ini, double fim, double x) { 
    int m;
    if (ini > fim)
        return ini;
    else {
        m = (ini + fim) / 2;
        if(T[m] < x) {
            return BuscaBin(T, m + 1, fim, x);
        }
        else{
            return BuscaBin(T, ini, m - 1, x);
        }
    }
}


int scm(double *vet, double *vet2, int size) {
	int i, k = 1, j;
	double t[size], o[size];
	t[1] = vet[1];
	o[1] = 1;
	
	for (i = 2; i <= size; i++) {
		if (vet[i] > t[k] || vet2[i] == vet2[i - 1]) {
			k++;
			t[k] = vet[i];
			o[i] = k;
		} else {
			j = BuscaBin(t, 1, k, vet[i]);
			t[j] = vet[i];
			o[i] = j;
		}
	}
	
	return k;
}


void quicksort(double *vet, double *vet2, int first, int last) {
	int i, j, pivot;
	double temp;

	if (first < last) {
		pivot = first;
		i = first;
		j = last;

		while (i < j) {
			while (vet[i] <= vet[pivot] && i < last)
				i++;
			while (vet[j] > vet[pivot])
				j--;
			if (i < j) {
				temp = vet[i];
				vet[i] = vet[j];
				vet[j] = temp;
				
				temp = vet2[i];
				vet2[i] = vet2[j];
				vet2[j] = temp;
			}
		}

		temp = vet[pivot];
		vet[pivot] = vet[j];
		vet[j] = temp;
		temp = vet2[pivot];
		vet2[pivot] = vet2[j];
		vet2[j] = temp;
		quicksort(vet, vet2, first, j - 1);
		quicksort(vet, vet2, j + 1, last);
   }
}
