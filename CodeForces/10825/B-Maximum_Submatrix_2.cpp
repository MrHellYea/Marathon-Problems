#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main () {
    ibs; cti;
    // ifstream in("tests.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream out("result.txt");
    // cout.rdbuf(out.rdbuf());
    char c;
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> mat(m, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            mat[j][i] = c - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 2; j >= 0; j--) {
            if (mat[j][i]) { 
                mat[j][i] += mat[j + 1][i];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        sort(mat[i].begin(), mat[i].end());

        for (int j = 0; j < n; j++) {
            ans = max(ans, mat[i][j] * (n - j));
        }
    } cout << ans << endl;

    return 0;
}