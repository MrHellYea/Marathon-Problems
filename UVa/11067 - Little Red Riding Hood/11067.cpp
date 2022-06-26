#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    ibs; cti;
    int w, h, n, x, y;
    
    while (cin >> w >> h, w + h > 0) {
        cin >> n;
        vector<vector<int>> matrix(w + 1, vector<int>(h + 1));
        matrix[0][0] = 1;
        while (n--) {
            cin >> x >> y;
            matrix[x][y] = -1;
        }

        for (int i = 0; i <= w; i++) {
            for(int j = 0; j <= h; j++) {
                if (i > 0 && matrix[i][j] != -1 && matrix[i - 1][j] != -1) { matrix[i][j] += matrix[i - 1][j]; }
                if (j > 0 && matrix[i][j] != -1 && matrix[i][j - 1] != -1) { matrix[i][j] += matrix[i][j - 1]; }
            }
        }

        if (matrix[w][h] == 1) {
            cout << "There is one path from Little Red Riding Hood's house to her grandmother's house." << endl;
        } else if (matrix[w][h] > 1) {
            cout << "There are " << matrix[w][h] << " paths from Little Red Riding Hood's house to her grandmother's house." << endl;
        } else {
            cout << "There is no path." << endl;
        }
    }

    return 0;
}
