#include <bits/stdc++.h>

using namespace std;

#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

const int MAX_BOLTS = 5001;
const int MAX_NUTS = 5001;

int bolts, nuts;
vector<int> fits[MAX_BOLTS];
int pre[MAX_BOLTS + MAX_NUTS];
int exposto[MAX_BOLTS + MAX_NUTS];

int n, v1, v2, nempmax, nempmaxa, nemp = 0;

int CamAument(int v);

int main() {
    ibs;
    cti;
    int cases, caseno;
    int result = 0;
    int isMatched;

    cin >> cases;

    for (caseno = 1; caseno <= cases; caseno++) {
        cin >> bolts >> nuts;

        n = bolts + nuts + 1;
        v1 = bolts;

        for (int i = 0; i <= n; i++) {
            pre[i] = 0;
            exposto[i] = 0;
            fits[i].clear();
        }

        for (int i = 1; i <= bolts; i++) {
            fits[0].push_back(i);

            for (int j = 1; j <= nuts; j++) {
                cin >> isMatched;

                if (isMatched) {
                    fits[i].push_back(j + bolts);
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

        cout << "Case " << caseno << ": a maximum of " << nempmax << " nuts and bolts can be fitted together" << endl;
        
        nemp = 0;
        nempmax = 0;
        nempmaxa = 0;
    }
    return 0;
}

int CamAument(int v){
    if (v > v1 && exposto[v]) {
		return 1;
	}

    pre[v]=1;

	for (int j = 0; j < fits[v].size(); j++) {
        int w = fits[v][j];
        if (!pre[w]) {
			if (CamAument(w))  {
			    exposto[w] = 0;
				fits[v].erase(fits[v].begin()+j);
				fits[w].push_back(v);
			    return 1;	 				
			}
		}
    }

    return 0;
}
