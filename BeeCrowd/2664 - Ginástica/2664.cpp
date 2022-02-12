#include <iostream>
#include <vector>

using namespace std;

int matf(int, int, int); 


int main() {
	int t, m, n;
	
	scanf("%i %i %i", &t, &m, &n);
	
	printf("%i\n", matf(t, m, n));
	
    return 0;
}


int matf(int t, int m, int n) {
	int i, j, sum = 0;
	vector<vector<int>> mat;
	
	for (i = 0; i <= n - m; i++) {
		mat.push_back(vector<int>());
		mat[i].push_back(1);
		for (j = 0; j < t; j++)
			mat[i].push_back(0);
	}

	for (j = 1; j < t; j++) {
		for (i = 0; i <= n - m; i++) {
			if (!i) {
				mat[i][j] = mat[i + 1][j - 1] % 1000000007;
			} else if (i == n - m) {
				mat[i][j] = mat[i - 1][j - 1] % 1000000007;
			} else {
				mat[i][j] = (mat[i + 1][j - 1] % 1000000007) + (mat[i - 1][j - 1] % 1000000007);
			}
		}
	}
	
	for (i = 0; i <= n - m; i++)
		sum = sum % 1000000007 + mat[i][t - 1] % 1000000007;
	
	return sum % 1000000007;
}
