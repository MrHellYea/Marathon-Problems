#include <iostream>
#include <vector>
	
using namespace std;
	
	
int main() {
	int i, j, k, T, N, K, S, C2, M, counter;
	long long int C1;
	vector<int> A(10000000);
	scanf("%i", &T);
	
	for (i = 0; i < T; i++) {
		for (j = 0; j < 10000000; j++)
			A[j] = 0;
		
		scanf("%i %i %i %lli %i %i", &N, &K, &S, &C1, &C2, &M);
			
		for (j = 0; j < N; j++) {
			A[S]++;
			S = (C1 * S + C2) % M;
		}
		
		counter = 0;
		for (j = 0; j < 10000000 && counter < K; j++) {
			for (k = 0; k < A[j] && counter < K; k++) {
				printf("%i ", j);
				counter++;
			}
		}
		printf("\n");
	}
	
	return 0;
}