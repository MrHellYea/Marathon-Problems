#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;
int dp[101][101][11][11];
int flimit, hlimit;

int calc(int f, int h, int k1, int k2) {
    if (!(f + h)) { return 1; }

    if (dp[f][h][k1][k2] != -1) { 
        return dp[f][h][k1][k2]; }

    int x = 0, y = 0;
    if (f and k1) { x = calc(f - 1, h, k1 - 1, hlimit); }
    if (h and k2) { y = calc(f, h - 1, flimit, k2 - 1); }

    return dp[f][h][k1][k2] = (x + y) % 100000000;
}


int main() {
    // ibs; cti;
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> flimit >> hlimit;
    memset(dp, -1, sizeof(dp));

    cout << calc(n1, n2, flimit, hlimit) << endl;

    return 0;
}
