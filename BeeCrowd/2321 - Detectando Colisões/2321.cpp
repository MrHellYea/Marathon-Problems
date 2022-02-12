#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct {
	int x, y;
} ponto;


typedef struct {
	ponto p, q;
	int d;
} segmento;


typedef struct {
	ponto p1, p2;
} retangulo;


int max(int, int);
int min(int, int);
int Intercepta_Ret(retangulo, retangulo);  
int ret_inter(retangulo, retangulo);

int main () {
	retangulo r[2];

	cin >> r[0].p1.x >> r[0].p1.y >> r[0].p2.x >> r[0].p2.y;
	cin >> r[1].p1.x >> r[1].p1.y >> r[1].p2.x >> r[1].p2.y;
	
	if (Intercepta_Ret(r[0], r[1])) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}
	

	return 0;
}


int Intercepta_Ret(retangulo r1, retangulo r2) {
	if ((max(r1.p1.x, r1.p2.x) >= min(r2.p1.x, r2.p2.x)) &&
	(max(r2.p1.x, r2.p2.x) >= min(r1.p1.x, r1.p2.x)) && 
	(max(r1.p1.y, r1.p2.y) >= min(r2.p1.y, r2.p2.y)) && 
	(max(r2.p1.y, r2.p2.y) >= min(r1.p1.y, r1.p2.y))) {
		return 1;
	} else {
		return 0;
	}
}


int ret_inter(retangulo r1, retangulo r2) {
	retangulo ret;
	
	ret.p1.x = max(r1.p1.x, r2.p1.x);
	ret.p1.y = min(r1.p2.x, r2.p2.x);
	ret.p2.x = min(r1.p2.y, r2.p2.y);
	ret.p2.y = max(r1.p1.y, r2.p1.y);
	
	return abs(ret.p2.x - ret.p1.x) * abs(ret.p2.y - ret.p1.y);
}


int max(int a, int b) {
	if (a >= b) {
		return a;
	} else {
		return b;
	}
}


int min(int a, int b) {
	if (a <= b) {
		return a;
	} else {
		return b;
	}
}
