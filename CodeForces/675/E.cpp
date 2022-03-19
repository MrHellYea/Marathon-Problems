#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

vector<vector<int>> sparseTable;

void buildSparseTable(vector<int> &values) {
    int numOfValues = (int) values.size();

    int max_log = 32 - __builtin_clz(numOfValues);
    sparseTable.resize(numOfValues, vector<int>(max_log));
    
    for(int i = 0; i < numOfValues; i++) {
        sparseTable[i][0] = i;
    }
    
    for(int j = 1; j <= max_log; j++)
        for(int i = 0; i <= numOfValues - (1 << j); i++)
            if (values[sparseTable[i][j-1]] > values[sparseTable[i + (1 << (j - 1))][j-1]]) {
                sparseTable[i][j] = sparseTable[i][j-1];
            } else {
                sparseTable[i][j] = sparseTable[i + (1 << (j - 1))][j-1];
            }
}

int getRMQ(vector<int> &values, int left, int right) {
    int lg = 32 - __builtin_clz(right - left + 1) - 1;
    if (values[sparseTable[left][lg]] > values[sparseTable[right - (1 << lg) + 1][lg]]) {
        return sparseTable[left][lg];
    } else {
        return sparseTable[right - (1 << lg) + 1][lg];
    }
}

int main() {
    int n;
    int element;
    int m;
    lli amount = 0;
    int maximumValue;

    vector<int> values;

    cin >> n;

    for (int i = 0; i <= n-2; i++) {
        cin >> element;
        element--;
        values.push_back(element);
    }

    vector<lli> dp(n, 0);

    values.push_back(n-1);

    buildSparseTable(values);

    dp[n-1] = 0;

    for (int i = n-2; i >= 0; i--) {
        m = getRMQ(values, i+1, values[i]);
        dp[i] = dp[m] - (values[i] - m) + n - i - 1;
        amount += dp[i];
    }

    cout << amount << endl;

    return 0; 
}
