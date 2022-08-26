#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;

#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int n, t;
double d;
double x[105], y[105];

int C[205][205];
int F[205][205];
int previous[205];

int bfs (int source, int sink) {
	queue<int> fila;
	fila.push(source);
	
	for (int i = 0; i < 2*n; i++) {
		previous[i] = -2;
	}

	previous[source] = -1;

	while (!fila.empty()) {
		int x = fila.front();
		fila.pop();

		if (x == sink) {
			int cf = INT_MAX;

			for (int i = sink; previous[i] != -1; i = previous[i]) {
				cf = min(cf, F[previous[i]][i]);
			}

			return cf;
		}

		for (int i = 0; i < 2*n; i++) {
			if (previous[i] == -2 && F[x][i] ){
				previous[i] = x;
				fila.push(i);
			}
		}
	}
	return 0;
}

int maxFlow(int source, int sink) {
	memcpy (F, C, sizeof(F));
	int cf;
	int tot = 0;

	while (cf = bfs(source, sink)) {
		tot += cf;
		for (int i = sink; previous[i] != -1; i = previous[i]) {
			F[previous[i]][i] -= cf;
			F[i][previous[i]] += cf;
		}
	}

	return tot;
}

int main() {
	cin >> t;

	while (t--) {
		cin >> n >> d;
		n++;
		memset(C, 0, sizeof(C));

		int penguins = 0;

		for (int i = 1; i < n; i++) {
			int num, m;

			cin >> x[i] >> y[i] >> num >> m;

			C[i][i+n] = m;
			C[n][i] = num;
			penguins += num;
		}

		for (int i = 1; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				double h = hypot(x[i] - x[j], y[i] - y[j]);
				if(h <= d + 1e-7) {
					C[i+n][j] = INT_MAX;
					C[j+n][i] = INT_MAX;
				}
			}
		}

		C[0][n] = INT_MAX;
		bool found = false;

		for (int i = 1; i < n; i++) {
			if (maxFlow(0, i) == penguins) {
				if (!found) {
					found = true;
				} else {
					cout << " ";
				}
				cout << i-1;
			}
		}

		if (!found) {
			cout << -1;
		}
		cout << endl;
	}
}