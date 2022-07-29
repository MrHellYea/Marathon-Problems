#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

struct Item {
    int weight;
    int value;

    Item() {}

    Item(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};

int main() {
    ifstream in("tests.txt");
    cin.rdbuf(in.rdbuf());
    ofstream out("result.txt");
    cout.rdbuf(out.rdbuf());
    int t, w, n, d, v;
    int weight;
    bool first = false;

    vector<Item> backpack(31);

    while (cin >> t >> w) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> d >> v;
            weight = 3 * w * d;
            backpack[i] = Item(weight, v);
        }

        vector<int> dp(1001);
        vector<vector<bool>> solved(1001, vector<bool>(31, false));
        vector<int> counter(1001, 0);

        dp[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = t; j >= backpack[i].weight; j--) {
                if (dp[j] < dp[j - backpack[i].weight] + backpack[i].value) {
                    dp[j] = dp[j - backpack[i].weight] + backpack[i].value;
                    counter[j] = counter[j - backpack[i].weight] + 1;
                    solved[j][i] = true;
                }
            }
        }

        if (first) {
            cout << endl;
        } first = true;
        cout << dp[t] << endl;
        cout << counter[t] << endl;

        for (int i = 0, j = t; i < n; i++) {
            if (solved[j][i]) {
                cout << backpack[i].weight / w / 3 << " " << backpack[i].value << endl;
                j -= backpack[i].weight;
            }
        }
    }

    return 0;
}
