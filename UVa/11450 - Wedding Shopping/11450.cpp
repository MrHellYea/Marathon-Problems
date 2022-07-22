#include <bits/stdc++.h>

typedef long long int lli;
typedef unsigned long long int ulli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
	ibs; cti;
    // ifstream in("tests.txt");
    // cin.rdbuf(in.rdbuf());
    // ofstream out("result.txt");
    // cout.rdbuf(out.rdbuf());
	int t, M, C, K, model;
	cin >> t;

	while (t--) {
		cin >> M >> C;
		vector<vector<int>> objects(C);

		for (int i = 0; i < C; i++) {
			cin >> K;

			for (int j = 0; j < K; j++){
				cin >> model;
				objects[i].push_back(model);
			}
		}

		vector<vector<int>> mat(C + 1, vector<int>(M + 1, -1));
		for (int j = 0; j <= M; j++) {
			mat[0][j] = 0;
		}

		for (int i = 1; i <= C; i++) {
			for (int j = 1; j <= M; j++) {
				for (int k = 0; k < objects[i - 1].size(); k++){
					int value = objects[i - 1][k];

					if (j - value >= 0 and mat[i - 1][j - value] >= 0 and value + mat[i - 1][j - value] > mat[i][j]) {
						mat[i][j] = value + mat[i - 1][j - value];
					}
				}
			}
		}

		if (mat[C][M] == -1) {
			cout << "no solution" << endl;
		} else {
			cout << mat[C][M] << endl;
		}
	}

	return 0;
}
 