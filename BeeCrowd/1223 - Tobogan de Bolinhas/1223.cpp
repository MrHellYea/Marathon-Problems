#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


struct aleta {
	int xi, yi, xf, yf;
};


struct reta {
	double a, b, c;
};


struct reta PontosParaReta(int, int, int, int);


double DistPontoReta(int, int, struct reta);


double dist(int, int, int, int);


int main () {
	int i, n, l, h;
	double min, hole;
	struct aleta aletas[1000];
	struct reta r;
	
	while (cin >> n) {
		cin >> l >> h;
		min = 10000;
		for (i = 0; i < n; i++) {
			cin >> aletas[i].yi >> aletas[i].xf >> aletas[i].yf;
		
			if ((i + 1) % 2 == 0) {
				aletas[i].xi = l;
				
				hole = dist(aletas[i].xf, aletas[i].yf, 0, aletas[i].yf);
				if (hole < min)
					min = hole;
				
				if (aletas[i - 1].xf >= aletas[i].xf) {
					r = PontosParaReta(aletas[i].xf, aletas[i].yf, aletas[i].xi, aletas[i].yi);
					hole = DistPontoReta(aletas[i - 1].xf, aletas[i - 1].yf, r);
				} else
					hole = dist(aletas[i - 1].xf, aletas[i - 1].yf, aletas[i].xf, aletas[i].yf);
				
				if (hole < min)
					min = hole;
			} else {
				aletas[i].xi = 0;
				
				hole = dist(aletas[i].xf, aletas[i].yf, l, aletas[i].yf);
				if (hole < min)
					min = hole;
				
				if (i > 0) {
					if (aletas[i - 1].xf <= aletas[i].xf) {
						r = PontosParaReta(aletas[i].xi, aletas[i].yi, aletas[i].xf, aletas[i].yf);
						hole = DistPontoReta(aletas[i - 1].xf, aletas[i - 1].yf, r);
					} else
						hole = dist(aletas[i - 1].xf, aletas[i - 1].yf, aletas[i].xf, aletas[i].yf);	
						
					if (hole < min)
						min = hole;
				}
			}
		}
		
		cout << fixed << setprecision(2) << min << endl;
	}

	return 0;
}


struct reta PontosParaReta(int x1, int y1, int x2, int y2) {
	struct reta r;
	
	if (x1 == x2) {
		r.a = 1;
		r.b = 0;
		r.c = -x1;
	} else {
		r.b = 1;
		r.a = -(y1 - y2) * 1.0 / (x1 - x2);
		r.c = -(r.a * x1) - (r.b * y1);
	}
	
	return r;
}


double DistPontoReta(int x, int y, struct reta r) {
	double a2 = -1.0 / r.a, c2 = -a2 * x - y, xr = -(r.c - c2) / (r.a - a2), yr = -c2 - a2 * (xr);

	return sqrt(pow(xr - x, 2) + pow(yr - y, 2));
}


double dist(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
