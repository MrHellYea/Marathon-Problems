#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int n, q;
vector<vector<int>> adj(100001);
    
int parent[100001];
int level[100001];
int dp[100001][20];
    
void dfs(int x) {
    for(auto j:adj[x]) {
        if(parent[j] == -1) {
            parent[j] = x;
            level[j] = level[x] + 1;
            dfs(j);
        }
    }
}
    
void init() {
    for(int i = 1; i <= n; i++) {
        dp[i][0] = parent[i];
    }
    
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}
    
int lca(int p, int q) {
    if(level[p] > level[q]) swap(p, q);

    for(int i = 19; i >= 0; i--) {
        while(dp[q][i] && level[dp[q][i]] >= level[p]) {
            q = dp[q][i];
        }
    }
    
    if(p == q) return p;
    
    for(int i = 0; i <= 19; i++) {
        while(dp[p][i] != dp[q][i]) {
            p = dp[p][i];
            q = dp[q][i];
        }
    }
    
    return dp[p][0];
}

int dist(int x, int y) {
    int l = lca(x, y);
    return level[x] + level[y] - 2 * level[l] + 1;
}
    
int calc(int s, int f, int t) {
    return (dist(s, f) + dist(f, t) - dist(s, t) + 1) / 2;
}
    
int main() {
    ibs; cti;
    int a, b, c, p;
    memset(parent, -1, sizeof parent);

    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    
    }
    
    parent[0] = parent[1] = 0;
    dfs(1);
    init();
    
    for(int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        cout << max(calc(a, b, c), max(calc(b, a, c), calc(a, c, b))) << endl;
    }
    
    return 0;
}