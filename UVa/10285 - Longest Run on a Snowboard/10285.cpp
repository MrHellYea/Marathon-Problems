#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;
int r, c;
vector<vector<int>> dp;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int calc(int i, int j, vector<vector<int>> mat) {
    if (dp[i][j] != -1) { return dp[i][j]; }

    dp[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + directions[k].first, y = j + directions[k].second;
        
        if ((x >= 0 and x < r) and (y >= 0 and y < c) and ((mat[i][j] > mat[x][y]))) {
            dp[i][j] = max(dp[i][j], calc(x, y, mat) + 1);
        }
    }

    return dp[i][j];
}

int main() {
    ibs; cti;
    string name;
    int n;
    cin >> n;

    while (n--) {
        cin >> name >> r >> c;
        vector<vector<int>> mat(r, vector<int>(c));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> mat[i][j];
            }
        }

        int ans = 0;
        dp = vector<vector<int>>(r, vector<int>(c, -1));
        for (int i = 0; i < r ; i++) {
            for (int j = 0; j < c; j++) {
                ans = max(ans, calc(i, j, mat));
            }
        } cout << name << ": " << ans << endl;
    }

    return 0;
}
