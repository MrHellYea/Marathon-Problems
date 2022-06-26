#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    ibs; cti;
    int t, x, y;
    string sline;

    getline(cin, sline);
    t = stoi(sline);
    getline(cin, sline);
    while (t--) {
        vector<vector<int>> matrix;

        y = 0;
        while (getline(cin, sline)) {
            if (sline.empty()) { break; }

            x = 0;
            vector<int> line;
            for (char c : sline) {
                if (!y) {
                    line.push_back(c - '0');
                } else {
                    line.push_back((c - '0') * (matrix[y - 1][x] + 1));
                }
                x++;
            } matrix.push_back(line); y++;
        }

        int answer = 0, area, index, aux, left, right;
        for (vector<int> line : matrix) {
            index = 0; area = 0;
            for (int i : line) {
                aux = index;
                while (aux > 0) {
                    if (line[aux - 1] < i) {
                        break;
                    } aux--;
                } left = aux;

                aux = index;
                while (aux < line.size() - 1) {
                    if (line[aux + 1] < i) {
                        break;
                    } aux++;
                } right = aux;
                area = i * (right - left + 1);

                if (area > answer) { answer = area; }
                index++;
            }
        }
    
        cout << answer << endl;
        if (t > 0) { cout << endl; }
    }

    return 0;
}
