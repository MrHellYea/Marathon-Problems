#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

vector<int> cubes[100010];

int main() {
    ibs; cti;
    int n, m, k, num, L, R, cut;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> num;
        cubes[num].push_back(i + 1);
    }

    int MAX = 0;
    for (int i = 1; i <= m; i++) {
        L = 0, R = 0, cut = 0;
        while (R >= L and R < cubes[i].size()) {
            if (cut > k) {
                cut -= cubes[i][L + 1] - cubes[i][L++] - 1;
            } else {
                if (R + 1 <= n) { cut += cubes[i][R + 1] - cubes[i][R] - 1; }
                MAX = max(MAX, 1 - L + R++);
            }
        }
    } cout << MAX << endl;

    return 0;
}
