#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

map<int, vector<int>> dict;
vector<int> looked;

int lookup(int v) {
    looked[v] = 1;

    for (auto current : dict[v]) {
        if (!looked[current]) {
            return lookup(current) + 1;
        }
    }
    
    return 1;
}

int main() {
    ibs; cti;
    int t;
    cin >> t;

    while (t--) {
        int n, x, y;
        cin >> n;

        dict.clear();
        looked.clear();
        looked.resize(n + 1, 0);

        bool check = false;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            dict[x].push_back(y);
            dict[y].push_back(x);

            if (x == y || dict[x].size() > 2 || dict[y].size() > 2) { check = true; }
        }

        if (check) {
            cout << "NO" << endl;
            continue;
        }

        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (!looked[i] and lookup(i) % 2) {
                cout << "NO" << endl;
                flag = true;
                break;
            }
        } if (flag) { continue; }

        cout << "YES" << endl;
    }
}
