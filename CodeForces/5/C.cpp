#include <bits/stdc++.h>

using namespace std;

#define endl '\n';

vector<vector<int>> sparseTable;

void buildSparseTable(vector<int> &values) {
    int numOfValues = (int) values.size();

    int max_log = 32 - __builtin_clz(numOfValues);
    sparseTable.resize(numOfValues, vector<int>(max_log));
    
    for (int i = 0; i < numOfValues; i++) {
        sparseTable[i][0] = values[i];
    }
    
    for (int j = 1; j <= max_log; j++)
        for (int i = 0; i <= numOfValues - (1 << j); i++)
            sparseTable[i][j] = max(sparseTable[i][j-1], sparseTable[i + (1 << (j - 1))][j - 1]);
}

int getRMQ(int left, int right) {
    int lg = 32 - __builtin_clz(right - left + 1) - 1;
    return max(sparseTable[left][lg], sparseTable[right - (1 << lg) + 1][lg]);
}

int main() {
    string parenthesis;
    int result = 0;
    int amount = 1;

    cin >> parenthesis;

    int n = (int)parenthesis.size();

    vector<int> longest(n, 0);

    for (int i = 1; i < n; i++) {
        if (parenthesis[i] == ')' && i - longest[i-1] - 1 >= 0 && parenthesis[i - longest[i-1] - 1] == '(') {
            if (i - longest[i-1] - 2 >= 0) {
                longest[i] = longest[i-1] + 2 + longest[i - longest[i-1] - 2];
            } else {
                longest[i] = longest[i-1] + 2;
            }
        }
    }

    buildSparseTable(longest);

    result = getRMQ(0, n-1);

    if (result == 0) {
        cout << result << " " << amount << endl;
    } else {
        amount = count(longest.begin(), longest.end(), result);
        cout << result << " " << amount << endl;
    }

    return 0; 
}