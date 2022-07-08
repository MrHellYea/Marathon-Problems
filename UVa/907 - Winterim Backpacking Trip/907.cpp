#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;
vector<int> dp;

bool possible(int middle, int n, int k) {
    int current = 0, divs = 0;

    for (int i = 0; i <= n; i++) {
        if (dp[i] > middle) {
            return false;
        } else if (current + dp[i] > middle) {
            current = dp[i];
            divs++;
        } else {
            current += dp[i];
        }
    }

    if (current) { divs++; }

    return divs <= k + 1;
}

int main() {
    ibs; cti;
    int n, k, sum, l1, l2;

    while (cin >> n >> k) {
        dp.resize(n + 1);

        for (int i = 0; i <= n; i++) { cin >> dp[i]; }
        sum = accumulate(dp.begin(), dp.end(), 0);

        if (k == 0) {
            cout << sum << endl;
            continue;
        }

        l1 = max(sum / (n + 1), *max_element(dp.begin(), dp.end()));
        l2 = sum;

        while (l1 <= l2) {
            int mid = (l1 + l2) / 2;
            if (possible(mid, n, k)) { l2 = mid - 1; }
            else { l1 = mid + 1; }
        }

        dp.clear();
        cout << ++l2 << endl;
    }

    return 0;
}
