#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

class Fenwick {
    vector<lli> tree;
    lli lenTree;

    lli g(lli i) { return i & -i; }

    public:
    Fenwick(lli lenVector) {
        this->lenTree = lenVector;
        tree.resize(lenVector + 1);

        for (lli i = 1; i <= lenTree; i++) {
            this->atualiza(i, 1);
        }
    }

    void atualiza(lli a, lli valor) {
        while (a <= lenTree) {
            tree[a] += valor;
            a += g(a);
        }
    }

    lli consulta(lli a) {
        lli soma = 0;
        while (a > 0) {
            soma += tree[a];
            a -= g(a);
        }
        return soma;
    }
      
    lli consulta(lli a, lli b) {
        return consulta(b) - consulta(a - 1);
    }
};

int main() {
    lli n, value, soma;

    while(scanf("%lld", &n) != EOF) {
        Fenwick *fenTree = new Fenwick(n);
        soma = 0;
        for (lli i = 1; i <= n; i++) {
            scanf("%lld", &value);
            soma += fenTree->consulta(value + 1, n);
            fenTree->atualiza(value, -1);
        }
        printf("%lld\n", soma);
    }
    
    return 0;
}