#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int n, ax, ay, bx, by, cx, cy;
vector<vector<int>> mat;
vector<pair<int, int>> directions = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0,  -1},          {0,  1},
    {1,  -1}, {1,  0}, {1,  1},
};

void lookup(int x, int y) {
    mat[x][y] = 2;

    for (auto dir : directions) {
        int auxX = x + dir.first, auxY = y + dir.second;
        if (auxY >= 0 and auxY < n and auxX >= 0 and auxX < n and !mat[auxX][auxY]) {
            lookup(auxX, auxY);
        }
    }
}

int main() {
    ibs; cti;
    // ifstream in("tests.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream out("result.txt");
    // cout.rdbuf(out.rdbuf());
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    ax--; ay--; bx--; by--; cx--; cy--; 
    mat = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        mat[i][ay] = 1;
    for (int i = 0; i < n; i++)
        mat[ax][i] = 1;
    for (int i = ax, j = ay; i < n and j < n; i++, j++)
        mat[i][j] = 1;
    for (int i = ax, j = ay; i >= 0 and j >= 0; i--, j--)
        mat[i][j] = 1;
    for (int i = ax, j = ay; i < n and j >= 0; i++, j--)
        mat[i][j] = 1;
    for (int i = ax, j = ay; i >= 0 and j < n; i--, j++)
        mat[i][j] = 1;

    lookup(bx, by);
    if (mat[cx][cy]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
