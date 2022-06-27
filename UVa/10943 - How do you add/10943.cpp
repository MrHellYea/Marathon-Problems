#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;
int N = 100;

int main() {
    ibs; cti;
    int n, k;
    vector<vector<int>> table(N+1, vector<int>(N+1));
    for (int i = 0; i < N+1; i++) {
        table[0][i] = 1;
        table[i][0] = 1;
    }

    for (int k = 1; k < N+1; k++) {
        for (int n = 1; n < N+1; n++) {
            table[k][n] = (table[k-1][n] + table[k][n-1])%1000000;
        }
    }

    while (cin >> n >> k, n + k > 0) {
        cout << table[k-1][n] << endl;
    }

    return 0;
}
