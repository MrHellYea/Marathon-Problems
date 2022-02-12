#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct ponto {
	int x, y;
};

bool comparator(struct ponto p1, struct ponto p2) {
    return (p1.x < p2.x);
}


int main() {
	int i, j, n, cont = 0;
	double max_top, min_bottom;
	
	cin >> n;
	
	vector <struct ponto> postes(n);
		
	for (i = 0; i < n; i++)
		cin >> postes[i].x >> postes[i].y;
		
	sort(postes.begin(), postes.end(), comparator);
	
	for (i = 0; i < n - 1; i++) {
		max_top = 100000001;
		min_bottom = -100000001;
		
		for (j = i + 1; j < n; j++) {
			if (postes[j].y > postes[i].y && postes[j].y < max_top) {
				max_top = postes[j].y;
				cont++;
			} else if (postes[j].y < postes[i].y && postes[j].y > min_bottom) {
				min_bottom = postes[j].y;
				cont++;
			}
		}
	}
		
	cout << cont << endl;
		
	return 0;
}
