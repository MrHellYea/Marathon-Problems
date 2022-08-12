#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

const int MAX = 220;

vector<vector<int>> CC(MAX, vector<int>(MAX));
vector<vector<int>> F(MAX, vector<int>(MAX));
vector<int> before(MAX);
vector<int> after(MAX);
vector<bool> V;

int max_;
int vertices = 0;

int MFDFS(int s, int e, int min_) {
    int f;
    V[s] = true;

    if (s == e) { return min_; }

    for (int i = 1; i <= vertices; i++) {
        if (!V[i] && CC[s][i] > 0) {
            if (f = MFDFS(i, e, min(min_, CC[s][i]))) {
                CC[s][i] -= f;
                CC[i][s] += f;

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
    int n, m, p, q, f;
    int nbefore = 0, nafter = 0;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> before[i];
        nbefore += before[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> after[i];
        nafter += after[i];
    }

    vertices = 2 * n + 2;
    for (int i = 1; i <= vertices; i++) {
        for (int j = 1; j <= vertices; j++) {
            CC[i][j] = 0;
            F[i][j] = 0;
        }
    }

    for (int i = 2; i <= n + 1; i++) {
        CC[1][i] = before[i - 1];
        CC[i][i+n] = 100;
    }

    for (int i = n+2; i <= vertices - 1; i++) {
        CC[i][vertices] =  after[i - n - 1];
    }

    for (int i = 1; i <= m; i++) {
        cin >> p >> q;
        CC[p + 1][n + q + 1] = 100;
        CC[q + 1][n + p + 1] = 100;
    }

    max_ = 0;
    V = vector<bool>(MAX, false);
    while (f = MFDFS(1, vertices, 100)) {
        max_ += f;
        V = vector<bool>(MAX, false);
    }

    if (max_ != nbefore || max_ != nafter) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        for (int i = 2; i <= n + 1; i++) {
            for (int j = n + 2; j <= vertices - 1; j++) { cout << F[i][j] << " "; }
            cout << endl;
        }
    }

    return 0;
}
