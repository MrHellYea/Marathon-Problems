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
        tree.resize(lenVector+1);
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

    void print() {
        cout << "Fennwick: " << endl;
        for (int i = 1; i <= lenTree; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ibs; cti;
    int lenVector;
    int rounds;
    int value;
    char operation;
    int n1, n2;



    while (cin >> lenVector >> rounds) {
        string output;
        Fenwick *negativeFenTree = new Fenwick(lenVector);
        Fenwick *zeroFenTree = new Fenwick(lenVector);
        vector<int> originalVector(lenVector+1);

        fill(originalVector.begin(), originalVector.end(), 0);
        
        for (int i = 1; i <= lenVector; i++) {
            cin >> value;

            originalVector[i] = value;

            if (value < 0) {
                negativeFenTree->atualiza(i, 1);
            } else if (value == 0) {
                zeroFenTree->atualiza(i, 1);
            }
        }

        for (int i = 1; i <= rounds; i++) {
            cin >> operation >> n1 >> n2;

            if (operation == 'C') {
                if (originalVector[n1] < 0) {
                    negativeFenTree->atualiza(n1, -1);
                } else if (originalVector[n1] == 0) {
                    zeroFenTree->atualiza(n1, -1);
                }

                if (n2 < 0) {
                    negativeFenTree->atualiza(n1, 1);
                } else if (n2 == 0) {
                    zeroFenTree->atualiza(n1, 1);
                }

                originalVector[n1] = n2;
            } else {
                if (zeroFenTree->consulta(n1, n2) > 0) {
                    output.push_back('0');
                } else {
                    if (negativeFenTree->consulta(n1, n2) % 2 == 0) {
                        output.push_back('+');
                    } else {
                        output.push_back('-');
                    }
                }
            }
        }
        cout << output << endl;
    }

    return 0;
}