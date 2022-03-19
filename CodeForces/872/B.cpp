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
        sparseTable[i][0] = values[i];
    }
    
    for(int j = 1; j <= max_log; j++)
        for(int i = 0; i <= numOfValues - (1 << j); i++)
            sparseTable[i][j] = max(sparseTable[i][j-1], sparseTable[i + (1 << (j - 1))][j - 1]);
}

int getRMQ(int left, int right) {
    int lg = 32 - __builtin_clz(right - left + 1) - 1;
    return max(sparseTable[left][lg], sparseTable[right - (1 << lg) + 1][lg]);
}

int main() {
    ibs; cti;
    int n, k;
    int element;
    int queries;
    vector<int> values;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> element;
        values.push_back(element);
    }

    buildSparseTable(values);

    if (k == 1) {
        cout << *min_element(values.begin(), values.end()) << endl;
    } else if (k == 2) { 
        cout << max(values[0], values[n-1]) << endl;
    } else {
        cout << getRMQ(0, n-1) << endl;   
    }

   return 0; 
}