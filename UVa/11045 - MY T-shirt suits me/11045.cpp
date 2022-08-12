#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

const int MAX = 36 * 30 + 1;

vector<pair<int, int>> neighbours(30);
vector<vector<int>> C;
vector<vector<int>> CC;
vector<vector<int>> F;
vector<bool> V;

int max_;
int vertices = 0;

map<string, int> shirts = {
    {"XXL", 2},
    {"XL", 3},
    {"L", 4},
    {"M", 5},
    {"S", 6},
    {"XS", 7}
};

void build(int n, int m) {
    vertices = n + m + 2;

    C = vector<vector<int>>(MAX, vector<int>(MAX, 0));
    CC = vector<vector<int>>(MAX, vector<int>(MAX, 0));
    F = vector<vector<int>>(MAX, vector<int>(MAX, 0));

    for (int i = 2; i <= n + 1; i++) { CC[1][i] = n / 6; }
    for (int i = n + 2; i <= vertices - 1; i++) { CC[i][vertices] =  1; }

    for (int i = 2; i <= n + 1; i++) {
        for (int j = n + 2; j <= vertices - 1; j++) {
            if (neighbours[j - n - 2 + 1].first == i || neighbours[j - n - 2 + 1].second == i) {
                CC[i][j] = 1;
            }
        }
    }
}

int MFDFS(int s, int e, int min_) {
    int f;
    V[s] = true;

    if (s == e) { return min_; }

    for (int i = 1; i <= vertices; i++) {
        if (!V[i] && C[s][i] > 0) {
            if (f = MFDFS(i, e, min(min_, C[s][i]))) {
                C[s][i] -= f;
                C[i][s] += f;

                F[s][i] += f;
                F[i][s] -= f;

                return f;
            }
        }
    }

    return 0;
}

int main() {
    ibs; cti;
    // ifstream in("tests.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream out("result.txt");
    // cout.rdbuf(out.rdbuf());
    int t, n, m, f;
    string n1, n2;

    cin >> t;
    while (t--) {
        cin >> n >> m;

        for (int j = 1; j <= m; j++) {
            cin >> n1 >> n2;
            neighbours[j].first = shirts[n1];
            neighbours[j].second = shirts[n2];
        }

        build(n, m);

        for (int j = 1; j <= vertices; j++) {
            for (int k = 1; k <= vertices; k++) {
                C[j][k] = CC[j][k];
            }
        }

        max_ = 0;
        V = vector<bool>(MAX, false);
        while (f = MFDFS(1, vertices, INT_MAX)) {
            max_ += f;
            V = vector<bool>(MAX, false);
        }

        if (max_ == m) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
