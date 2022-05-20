#include <bits/stdc++.h>

typedef long long int lli;
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
    string s;
    int t;
    cin >> t;

    while (t--) {
        cin >> s;
        int n = s.length();
        map<string, int> Map;
        vector<int> suffix(n);

        string sub;
        for (int i = n - 1; i >= 0; i--) {
            sub = s[i] + sub;
            Map[sub] = i;
        }   

        string last;
        vector<int> LCP(n);
        int j = 0, max = 0, pos = 0, count;
        for (auto x : Map) {
            if (last.empty()) {
                LCP[j] = 0;
            } else {
                count = 0;
                while (last[count] == x.first[count]) { count++; }
                LCP[j] = count;
            }
            
            if (LCP[j] > max) {
                max = LCP[j];
                pos = x.second;
            }

            last = x.first;
            suffix[j] = x.second;
            j++;
        }

        string result = s.substr(pos, max);
        int occurrences = 0;
        pos = 0;
        while ((pos = s.find(result, pos)) != string::npos) { occurrences++; pos++; }

        if (result.empty())
            cout << "No repetitions found!" << endl;
        else
            cout << result << " " << occurrences << endl;
    }

    return 0;
}
