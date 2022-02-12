#include <vector>
#include <algorithm>

using namespace std;

struct ponto {
	int x, y;
};

int pit(struct ponto p1, struct ponto p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

bool comparatorx(struct ponto p1, struct ponto p2) {
    return (p1.x < p2.x);
}

bool comparatory(struct ponto p1, struct ponto p2) {
    return (p1.y < p2.y);
}

bool comparatorang(struct ponto, struct ponto);

bool is_colinear(struct ponto, struct ponto, struct ponto, struct ponto);

int sentidoPercurso(struct ponto, struct ponto, struct ponto);

void grahamScan(vector<struct ponto>, vector<struct ponto>*);

bool onSegment(struct ponto, struct ponto, struct ponto);

bool insidePolygon(vector<struct ponto>, struct ponto);


int main() {
	int i;
	struct ponto estudante;
	vector<struct ponto> policiais(4);
	
	for (i = 0; i < 4; i++)
		cin >> policiais[i].x >> policiais[i].y;
	cin >> estudante.x >> estudante.y;
	
	if (is_colinear(policiais[0], policiais[1], policiais[2], policiais[3])) {
		cout << " O>\n<| \n/ >\n";
	}
	else {
		vector<struct ponto> S;
		
		grahamScan(policiais, &S);

		if (insidePolygon(S, estudante))
			cout << "\\O/\n | \n/ \\" << endl;
		else
			cout << " O>\n<| \n/ >\n";
	}

	return 0;
}


bool comparatorang(struct ponto p1, struct ponto p2) {
	if (sentidoPercurso({0, 0}, p1, p2) == 1 || (sentidoPercurso({0, 0}, p1, p2) == 0 && pit(p1, {0, 0}) < pit(p2, {0, 0}))) 
		return 1;
	else
		return 0;
}

bool is_colinear(struct ponto p1, struct ponto p2, struct ponto p3, struct ponto p4) {
	if (sentidoPercurso(p1, p2, p3) == 0 && sentidoPercurso(p2, p3, p4) == 0)
		return 1;
	else 
		return 0;
}

int sentidoPercurso(struct ponto p1, struct ponto p2, struct ponto p3) {
	int s = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	
	if (s > 0)
		return 1;
	else if (s < 0)
		return -1;
	else
		return 0;
}

void grahamScan(vector<struct ponto> p, vector<struct ponto> *S) {
	int i = 0;
	
	sort(p.begin(), p.end(), comparatory);
	
	while (p[i].y == p[0].y)
		i++;
	sort(p.begin(), p.begin() + i, comparatorx);
	sort(p.begin() + 1, p.end(), comparatorang);
	
	S->push_back(p[0]);
	
	for (i = 1; i < 4; i++) {
		if (S->size() < 2)
			S->push_back(p[i]);
		else {
			while (S->size() > 1 && (sentidoPercurso((*S)[S->size() - 2], (*S)[S->size() - 1], p[i]) != 1))
				S->pop_back();
			S->push_back(p[i]);
		}
	}
	S->push_back(p[0]);
}

bool onSegment(struct ponto q, struct ponto p1, struct ponto p2) {
	return sentidoPercurso(q, p1, p2) == 0 && q.x >= min(p1.x, p2.x) && q.x <= max(p1.x, p2.x) &&
		q.y >= min(p1.y, p2.y) && q.y <= max(p1.y, p2.y);
}

bool insidePolygon(vector<struct ponto> P, struct ponto q) {
	int i, taux, t = sentidoPercurso(q, P[P.size() - 2], P[P.size() - 1]);

	if (!t)
		return onSegment(q, P[P.size() - 2], P[P.size() - 1]);
	
	for (i = 1; i <= P.size() - 2; i++) {
		taux = sentidoPercurso(q, P[i - 1], P[i]);
		
		if (!taux)
			return onSegment(q, P[i - 1], P[i]);
		else if (taux != t)
			return 0;
	}
	
	return 1;
}
