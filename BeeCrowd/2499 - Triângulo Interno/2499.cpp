#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main () {
	long long int s, n, m, c1, c2, c3, aux, total;

	cin >> s >> n >> m;
	while (s + n + m > 0) {
		cin >> c1 >> c2 >> c3;
		
		if (c2 > c3) {
			aux = c3;
			c3 = c2;
			c2 = aux;
		}
		
		total = (s * c1 * (c3 - c2)) / (n * m + n + m + 1);
		
		cout << total << endl;
		cin >> s >> n >> m;
	}

	return 0;
}
