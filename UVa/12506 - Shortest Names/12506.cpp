#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;
string name;
int sum;

class node {
    public:
    int value;
    map<char, node*> dict;

    node(){}

    node(int val) {
        this->value = val;
    }

    void add_value(int index) {
        if (index >= name.length()) { return; }
        if (dict.find(name[index]) == dict.end()) {
            node *new_node = new node(1);
            dict[name[index]] = new_node;
            (*new_node).add_value(index+1);
        } else {
            node *next_node = dict[name[index]];
            next_node->value++;
            next_node->add_value(index+1);
        }
    }

    void counter(int level) {
        int count = 0;

        for (auto i = dict.begin(); i != dict.end(); i++) {
            if (i->second->value == 1) { count++; }
        }

        sum += (level + 1) * count;

        for (auto i = dict.begin(); i != dict.end(); i++) {
            if (i->second->value > 1) { i->second->counter(level+1); }
        }
    }

    void print_tree() {
        for (auto i = dict.begin(); i != dict.end(); i++) {
            cout << i->first << " " << i->second->value << endl;
            i->second->print_tree();
        }
    }
};

int main() {
    // ibs; cti;
    int t, n;

    cin >> t;
    for (int i = 0; i < t; i++) {
        node *root = new node(0);
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> name;
            (*root).add_value(0);
        }
        // (*root).print_tree();
        sum = 0;
        (*root).counter(0);
        cout << sum << endl;
    }
    

    return 0;
}
