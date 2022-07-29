#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;
const int N = 200001;
vector<vector<int>> edges(N);
vector<int> colors(N), degrees(N);
int ans = 0;

void lookup(int u=1, int father=0) {
    int num = 1;
    for (auto v : edges[u]) {
        if (v == father) { continue; }
        while (num == colors[u] || num == colors[father]) { num++; }
        colors[v] = num++;
    }

    for (auto v : edges[u]) {
        if (v == father) { continue; }
        lookup(v, u);
    }
}

int main() {
    ibs; cti;
    int n, x, y;
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        degrees[x]++, degrees[y]++;
        ans = max({ans, degrees[x], degrees[y]});
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    colors[1] = 1;
    lookup();

    cout << ++ans << endl;
    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    } cout << endl;

    return 0;
}
