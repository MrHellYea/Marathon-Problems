#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

const int MAX = 100 * 100 + 2;

pair<float, float> gophers[101];
pair<float, float> holes[101];
vector<vector<int>> C(MAX, vector<int>(MAX));
vector<vector<int>> F(MAX, vector<int>(MAX));
vector<bool> V;

int max_;
int vertices = 0;

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

double pit(int i, int j) {
    return sqrt(
        (gophers[i].first - holes[j].first ) * (gophers[i].first - holes[j].first) + \
        (gophers[i].second - holes[j].second) * (gophers[i].second - holes[j].second)
    );
}

int main() {
    ibs; cti;
    // ifstream in("tests.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream out("result.txt");
    // cout.rdbuf(out.rdbuf());
    int n, m, time, vel;

    while (cin >> n >> m >> time >> vel) {
        vertices = n + m + 2;

        for (int i = 1; i <= n; i++) { cin >> gophers[i].first >> gophers[i].second; }
        for (int i = 1; i <= m; i++) { cin >> holes[i].first >> holes[i].second; }

        for (int i = 1; i <= vertices; i++) {
            for (int j = 1; j <= vertices; j++) {                
                C[i][j] = 0;
                F[i][j] = 0;
            }
        }

        for (int i = 2; i <= n + 1; i++) { C[1][i] = 1; }
        for (int i = n + 2; i <= vertices - 1; i++) { C[i][vertices] = 1; }

        for (int i = 2; i <= n + 1; i++) {
            for (int j = n + 2; j <= vertices - 1; j++) {
                C[i][j] = time * vel >= pit(i-1, j-n-1) ? 1 : 0;
            }
        }
      
        max_ = 0;
        V = vector<bool>(MAX, false);
        while (int flow = MFDFS(1, vertices, INT_MAX)) {
            max_ += flow;
            V = vector<bool>(MAX, false);
        }

        cout << n - max_ << endl;
    }

    return 0;
}
