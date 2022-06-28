#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int k;

int rec(int L, int R, vector<vector<int>> *dp) {
    if (R <= L) { return 0; }
    if (R - L == 1) { return (k + L) * 2; }
    if (R - L == 2) { return (k + L + 1) * 3; }
    if ((*dp)[L][R] != -1) { return (*dp)[L][R]; }

    (*dp)[L][R] = INT_MAX;
    for(int i = L; i <= R; i++) {
        int temp = (R - L + 1) * (k + i) + rec(L, i - 1, dp) + rec(i + 1, R, dp);
        (*dp)[L][R] = min((*dp)[L][R], temp);
    }

    return (*dp)[L][R];
}

int main() {
    ibs; cti;
    int t, n, cases = 1;
    cin >> t;

    while (t--) {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        cin >> n >> k;
        cout << "Case " << cases++ << ": " << rec(1, n, &dp) << endl;
    }

    return 0;
}
