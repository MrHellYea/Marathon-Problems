#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

const int N = 11;
const int M = 101;
lli dp[N][M][M];

int main() {
    ibs; cti;
    lli best, explode, withstand;
    int t, k, m;

    for (int i = 0; i < M; i++) {
        for (int j = i; j < M; j++) {
            if (i == j) { dp[0][i][j] = 0; }
            else { dp[0][i][j] = dp[0][j][i] = INT_MAX; }
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            for (int k = 0; k + j < M; k++){
                best = INT_MAX;
                for (int m = k + 1; m <= k + j; m++){
                    explode = dp[i - 1][k][m - 1];
                    withstand = dp[i][m][k + j];
                    best = min(best, max(explode, withstand) + m);
                } dp[i][k][k+j] = best;
            }
        }
    }

    cin >> t;
    while (t--) {
        cin >> k >> m;
        cout << dp[k][0][m] << endl;
    }

    return 0;
}
