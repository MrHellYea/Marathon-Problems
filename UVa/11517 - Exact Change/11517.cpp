#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    ibs; cti;
    // ifstream in("tests.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream out("result.txt");
    // cout.rdbuf(out.rdbuf());
    int t, price, n;
    cin >> t;

    while (t--) {
        cin >> price >> n;
        vector<int> coins(n + 1);
        vector<vector<int>> mat(n + 1, vector<int>(10001, -1));
        mat[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> coins[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j >= 1; j--) {
                for (int k = coins[i]; k <= 10000; k++) {
                    if (mat[j][k] == -1 and mat[j - 1][k - coins[i]] >= 0) {
                        mat[j][k] = i;
                    }
                }
            }
        }

        pair<int, int> ans;
        for (int i = price; i <= 10000; i++) {
            for (int j = 1; j <= n; j++) {
                if (mat[j][i] != -1) {
                    ans.first = i;
                    ans.second = j;
                    i = 10001;
                    break;
                }
            }
        } cout << ans.first << " " << ans.second << endl;
    } 

    return 0;
}
