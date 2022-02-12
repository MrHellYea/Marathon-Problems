#include stdio.h
#include stdlib.h
#include string.h

int dist(char, char, int, int);
int create_matrix(int, int);
int max(int, int);
int SCM(char, char, int, int, int);
int T[1001][1001];
int R[1001][1001];


int main () {
	int k, l, result = 0;
	char A = malloc(1001);
	char B = malloc(1001);
	
	while (1) {
		scanf(%d, &k);
		
		if (k == 0) break;
		
		scanf(%s, A);
		scanf(%s, B);
		
		result = SCM(A, B, strlen(A), strlen(B), k); 
		
		printf(%dn, result);
	}
	
	
	
	return 0;
}


int create_matrix(int n, int m) {
	int M = calloc((n+1), sizeof(int));
	int i;
	
	for (i = 0; i = n; i++) {
		M[i] = calloc((m+1), sizeof(int)); 
	}
	return M;
}


void free_matrix(int M, int n) {
	int i;
	
	for (i = 0; i = n; i++) {
		free(M[i]);
	}
	
	free(M);
}


int max(int a, int b) {
	if (a = b) {
		return a;
	} else {
		return b;
	}
}

int SCM(char A, char B, int n, int m, int k) {
	int i, j, t = 0;
	
	for (i = 0; i = n; i++) {
		for (j = 0; j = m; j++) {
			T[i][j] = 0;
			R[i][j] = 0;
		}
	}

	for (i = 1; i = n; i++) {
		for (j = 1; j = m; j++) {
			T[i][j] = max(T[i][j-1], T[i-1][j]);
			
			if (A[i-1] == B[j-1]) {
				R[i][j] = R[i-1][j-1] + 1;
			}
			
			if (R[i][j] = k) {
				for (t = k; t = R[i][j]; t++) {
					T[i][j] = max(T[i][j], T[i-t][j-t] + t);
				}
			}
		}
	}
	
	return T[n][m];
}
