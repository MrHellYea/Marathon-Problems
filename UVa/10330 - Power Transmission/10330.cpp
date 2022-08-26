#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int n;
int F[250][250];
int previous[250];

int bfs(int src, int sink) {
	queue<int> fila;
	
	for (int i = 0; i < 2*n; i++) {
		previous[i] = -2;
	}

	fila.push(src);
	previous[src] = -1;

	while (!fila.empty()) {
		int u = fila.front();
		fila.pop();

		if (u == sink) {
			int cf = INT_MAX;
			for (int i = sink; previous[i] != -1; i = previous[i]) {
				cf = min(cf, F[previous[i]][i]);
			}
			return cf;
		}

		for (int i = 0; i < 2*n; i++) {
			if (previous[i] == -2 && F[u][i] > 0) {
				fila.push(i);
				previous[i] = u;
			}
		}
	}
	return 0;
}

int maxFlow(int src, int sink) {
	int cf;
	int tot = 0;

	while (cf = bfs(src, sink)) {
		tot += cf;
		
		for (int i = sink; previous[i] != -1; i = previous[i]) {
			F[previous[i]][i] -= cf;
			F[i][previous[i]] += cf;
		}
	}

	return tot;
}

int main(){
	ibs;
	cti;

	while (cin >> n) {
		n += 2;

		memset(F, 0, sizeof(F));

		F[0][n] = INT_MAX;
		F[n-1][2*n-1] = INT_MAX;

		for (int i = 1; i < n-1; i++) {
			int cost;
			cin >> cost;
			F[i][i+n] = cost;
		}

		int m;
		cin >> m;

		while (m-- > 0) {
			int i, j, cost;
			cin >> i >> j >> cost;
			F[i+n][j] += cost;
		}

		int b, d;
		cin >> b >> d;

		while(b-- > 0) {
			int node;
			cin >> node;
			F[n][node] = INT_MAX;
		}

		while (d-- > 0) {
			int node;
			cin >> node;
			F[node+n][n-1] = INT_MAX;
		}
		
		cout << maxFlow(0, 2*n-1) << endl;
	}
}
