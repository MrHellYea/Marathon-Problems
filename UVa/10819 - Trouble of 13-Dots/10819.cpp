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
    int m, n, limit;

    while (cin >> m >> n) {
        vector<pair<int, int>> items(n);

        for (int i = 0; i < n; i++) {
            cin >> items[i].first >> items[i].second;
        }

        limit = m > 1800 ? m + 200 : m;
        vector<int> dp(limit + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = limit - items[i].first; j >= 0; j--) {
                if (dp[j] != -1) {
                    dp[j + items[i].first] = max(dp[j] + items[i].second, dp[j + items[i].first]);
                }
            }
        }

        int favour = 0;
        if (m > 1800 and m < 2001) {
            favour = *max_element(dp.begin(), dp.begin() + m);

            for (int i = 2001; i <= limit; i++) {
                favour = max(favour, dp[i]);
            }
        } else {
            favour = *max_element(dp.begin(), dp.end());
        }

        cout << favour << endl;
    }

    return 0;
}