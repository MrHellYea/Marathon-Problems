#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    ibs; cti;
    string line, english, foreign;
    map<string, string> dict;

    while (getline(cin, line), line != "") {
        stringstream ss(line);
        ss >> english >> foreign;
        dict[foreign] = english;
    }

    while (getline(cin, line)) {
        if (dict.find(line) == dict.end()) {
            cout << "eh" << endl;
        } else {
            cout << dict[line] << endl;
        }
    }

    return 0;
}
