#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    ibs; cti;
    int n, left, right, aux_l, aux_r;

    while (cin >> n, n != 0) {
        vector<int> me(20001), md(20001);

        for (int i = 0; i < n; i++) {
            cin >> left >> right;

            if (!i) {
                me[0] = 2 * right - left - 1;
                md[0] = right - 1;
           } else {
                me[i] = min(
                    me[i - 1] + abs(aux_l - right) + right - left,
                    md[i - 1] + abs(aux_r - right) + right - left
                );
                md[i] = min(
                    me[i - 1] + abs(aux_l - left) + right - left,
                    md[i - 1] + abs(aux_r - left) + right - left
                );
           }

           if (i != n - 1) { aux_l = left; aux_r = right; }
        }

        if (n == 1) { cout << right - 1 << endl; continue; }
        cout << min(
            me[n - 2] + abs(aux_l - left) + n - left,
            md[n - 2] + abs(aux_r - left) + n - left
        ) + n - 1 << endl;
    }

    return 0;
}
