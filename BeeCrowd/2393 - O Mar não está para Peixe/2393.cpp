#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;


int main () {
	int i, j, k, n, xi, xf, yi, yf, area = 0;
	int redes[100][100];

	cin >> n;	
	
	for (j = 0; j < 100; j++) {
		for (k = 0; k < 100; k++)
			redes[j][k] = 0;
	}
	
	for (i = 0; i < n; i++) {
		cin >> xi >> xf >> yi >> yf;
		
		for (j = yi - 1; j < yf - 1; j++) {
			for (k = xi - 1; k < xf - 1; k++)  {
				if (!(redes[j][k])) {
					redes[j][k] = 1;
					area++;
				}
			}	
		}
	}

	cout << area << endl;

	return 0;
}
