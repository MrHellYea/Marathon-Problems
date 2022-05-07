#include <bits/stdc++.h>
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    ibs; cti;
    string word;
    set<string> words;

    while (cin >> word) {
        string transformedWord = "";

        for (int i = 0; i < word.length(); i++) {
            char character = tolower(word[i]);

            if (character >= 'a' && character <= 'z') {
                transformedWord += character;
            } else if (transformedWord != "") {
                words.insert(transformedWord);
                transformedWord = "";
            }
        }

        if (transformedWord != "") {
            words.insert(transformedWord);
        }
    }

    for (auto i = words.begin(); i != words.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}
