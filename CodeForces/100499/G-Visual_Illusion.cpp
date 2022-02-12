#include <iostream>
#include <vector>
#include <cmath> 
	
using namespace std;
	
	
int main() {
	int i, j, k, T, n, aux;
	
	cin >> T;
	
	for (i = 0; i < T; i++) {
		cin >> n;
		vector<vector<char>> mat(2 * n + 1, vector<char> (2 * n + 1));
		
		for (j = -n; j <= n; j++) {
			for (k = -n; k <= n; k++) {
				aux = fabs(j) + fabs(k);
				if (aux % 3 == 0)
					cout << 'b';
				else
					cout << 'w';
			}
			cout << endl;
		}
	}
	
	return 0;
}