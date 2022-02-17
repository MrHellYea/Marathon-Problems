#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);

using namespace std;

vector<int> seg;
void update(int pos, int begin, int end, int index, int value);
int binarySearch(int pos, int begin, int end, int least);

int main() {
    ibs; cti;
    int n, m, num;
    int i, v, x;

    cin >> n >> m;
    seg.resize(4*n);

    for (int i = 1; i <= n; i++) {
        cin >> num;
        update(1, 1, n, i, num);
    }
    
    while (m--) {
        cin >> num;

        if (num == 1) {
            cin >> i >> v;
            update(1, 1, n, i + 1, v);
        } else {
            cin >> x;
            cout << binarySearch(1, 1, n, x) << "\n";
        }
    }

    return 0;
}

void update(int pos, int begin, int end, int index, int value) {
    if (index < begin || index > end) return;

    if (begin == end) {
        seg[pos] = value;
        return;
    }

    int middle = (begin + end) / 2;
    int l = 2 * pos;
    int r = 2 * pos + 1;

    update(l, begin, middle, index, value);
    update(r, middle+1, end, index, value);

    seg[pos] = max(seg[l], seg[r]);
}

int binarySearch(int pos, int begin, int end, int least) {
    if (seg[pos] < least) return -1;
    if (begin == end) return begin-1;

    int middle = (begin + end)/2;
    int l = 2 * pos;
    int r = 2 * pos + 1;

    int temporary = binarySearch(l, begin, middle, least);
    if (temporary != -1) return temporary;

    return binarySearch(r, middle+1, end, least);
}
