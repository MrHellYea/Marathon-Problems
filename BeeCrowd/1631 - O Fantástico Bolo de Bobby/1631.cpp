#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


struct ponto {
	double x, y;
};


struct reta {
	double a, b, c;
};


struct reta PontosParaReta(struct ponto, struct ponto);


double DistPontoReta(struct ponto, struct reta);


double Laplace(struct ponto, struct ponto, struct ponto);


int main () {
	int i, j, k, n;
	double dist_esq, dist_dir, min;
	struct ponto pontos[100];
	struct reta r;
	
	cin >> n;
	while (n) {
		min = 100;
		
		for (i = 0; i < n; i++)
			cin >> pontos[i].x >> pontos[i].y;
		
		for (i = 0; i < n - 1; i++) {
			for (j = i + 1; j < n; j++) {
				r = PontosParaReta(pontos[i], pontos[j]);
				dist_esq = 0;
				dist_dir = 0;
				for (k = 0; k < n; k++) {
					if (k != i && k != j) {
						if (pontos[i].y == pontos[j].y) {
							if (pontos[k].y > pontos[i].y)
								dist_esq += pontos[k].y - pontos[i].y;
							else
								dist_dir += pontos[i].y - pontos[k].y;
						} else if (pontos[i].x == pontos[j].x) {
							if (pontos[k].x < pontos[i].x)
								dist_esq += pontos[i].x - pontos[k].x;
							else
								dist_dir += pontos[k].x - pontos[i].x;
						} else {
							if (Laplace(pontos[i], pontos[j], pontos[k]) > 0)
								dist_esq += DistPontoReta(pontos[k], r);
							else
								dist_dir += DistPontoReta(pontos[k], r);
						}
					}
				}
				if (fabs(dist_esq - dist_dir) < min)
					min = fabs(dist_esq - dist_dir);
			}
		}
		
		cout << fixed << setprecision(3) << min << endl;
		cin >> n;
	}

	return 0;
}


struct reta PontosParaReta(struct ponto p1, struct ponto p2) {
	struct reta r;
	
	if (p1.x == p2.x) {
		r.a = 1;
		r.b = 0;
		r.c = -p1.x;
	} else {
		r.b = 1;
		r.a = -(p1.y - p2.y) / (p1.x - p2.x);
		r.c = -(r.a * p1.x) - (r.b * p1.y);
	}
	
	return r;
}


double DistPontoReta(struct ponto p, struct reta r) {
	double a2 = -1.0 / r.a, c2 = -a2 * p.x - p.y, x = -(r.c - c2) / (r.a - a2), y = -c2 - a2 * (x);
	
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}


double Laplace(struct ponto p1, struct ponto p2, struct ponto p3) {
	return 0.5 * (p1.x * (p2.y - p3.y) - p2.x * (p1.y - p3.y) + p3.x * (p1.y - p2.y));
}
