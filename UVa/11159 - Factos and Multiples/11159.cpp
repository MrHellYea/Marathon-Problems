#include <bits/stdc++.h>

using namespace std;

#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

const int MAXN = 501;
const int MAXM = 501;

int exposto[MAXN + MAXM];
int pre[MAXN + MAXM];
vector<int> G[MAXN];
vector<int> factors;
vector<int> products;

int factor, product, N;
int n, m, v1, v2, nempmax, nempmaxa, nemp = 0;

int CamAument(int v);

int main() {
    ibs;
    cti;

    int caseno, t;

    cin >> t;

    for (int caseno = 1; caseno <= t; caseno++) {
        cin >> N;

        factors.clear();
        factors.resize(N+1);

        for (int i = 1; i <= N; i++) {
            cin >> factor;
            factors[i] = factor;
        }

        cin >> m;

        products.clear();
        products.resize(m+1);

        for (int i = 1; i <= m; i++) {
            cin >> product;
            products[i] = product;
        }

        n = N + m + 1;
        v1 = N;

        for (int i = 0; i <= n; i++) {
            pre[i] = 0;
            exposto[i] = 0;
            G[i].clear();
        }

        for (int i = 1; i <= N; i++) {
            G[0].push_back(i);

            for (int j = 1; j <= m; j++) {
                if (products[j] == 0 && factors[i] == 0) {
                    G[i].push_back(j + N);
                } else if (factors[i] != 0) {
                    if (products[j] % factors[i] == 0) {
                        G[i].push_back(j + N);
                    }
                }
            }
        }


        memset(pre, 0, sizeof(pre));  

        for (int i = 0; i <= n; i++) {
            exposto[i] = 1;
        }

        while (true) {                   
			while (nemp = CamAument(0))
		    	nempmax += nemp;
			if (nempmaxa == nempmax)
				break;
			nempmaxa = nempmax;
			memset(pre, 0, sizeof(pre)); 
		}

        cout << "Case " << caseno << ": " << nempmax << endl;

        nempmax = 0;
        nemp = 0;
        nempmaxa = 0;
    } 

    return 0;
}

int CamAument(int v) {
    if (v > v1 && exposto[v]) {
		return 1;
	}

    pre[v]=1;

	for (int j = 0; j < G[v].size(); j++) {
        int w = G[v][j];
        if (!pre[w]) {
			if (CamAument(w))  {
			    exposto[w] = 0;
				G[v].erase(G[v].begin()+j);
				G[w].push_back(v);
			    return 1;	 				
			}
		}
    }

    return 0;
}
