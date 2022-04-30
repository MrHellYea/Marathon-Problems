#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

class Fenwick {
    vector<int> tree;
    int lenTree;

    int g(int i) {
        return i & -i;
    }

    public:
    Fenwick(int lenVector) {
        this->lenTree = lenVector;
        tree.resize(lenVector);
    }

    void atualiza(int a, int valor) {
        while (a <= lenTree) {
            tree[a] += valor;
            a += g(a);
        }
    }

    int consulta(int a) {
        int soma = 0;
        while (a > 0) {
            soma += tree[a];
            a -= g(a);
        }
        return soma;
    }
      
    int consulta(int a, int b) {
        return consulta(b) - consulta(a - 1);
    }
};

int main() {
    ibs; cti;
    int lenVector;
    int value;

    cin >> lenVector;

    Fenwick *fenTree = new Fenwick(lenVector);

    for(int i = 1; i <= lenVector; i++) {
        cin >> value;
        fenTree->atualiza(i, value);
    }
    
    char query;
    int i;

    while(cin >> query >> i) {
       if(query == 'a') {
           fenTree->atualiza(i, -fenTree->consulta(i, i));
       } else {
           cout << fenTree->consulta(i - 1) << endl;
       }
    }
    
    return 0;
}