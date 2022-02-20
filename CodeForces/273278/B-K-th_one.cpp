#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);

using namespace std;

vector<int> seg;
void update(int pos, int begin, int end, int index, int value=-1);
int binarySearch(int pos, int begin, int end, int k);

int main() {
    ibs; cti;
    int n, m;
    int i, k, num;

    cin >> n >> m;
    seg.resize(4*n);

    for (int i = 1; i <= n; i++) {
        cin >> num;
        update(1, 1, n, i, num);
    }
    
    while (m--) {
        cin >> num;

        if (num == 1) {
            cin >> i;
            update(1, 1, n, i + 1);
        } else {
            cin >> k;
            cout << binarySearch(1, 1, n, k+1) << "\n";
        }
    }

    return 0;
}

void update(int pos, int begin, int end, int index, int value) {
    if (index < begin || index > end) return;

    if (begin == end) {
        if (value != -1) {
            seg[pos] = value;
        } else {
            seg[pos] = (seg[pos] + 1) % 2;
        }
        return;
    }

    int middle = (begin + end) / 2;
    int l = 2 * pos;
    int r = 2 * pos + 1;

    update(l, begin, middle, index, value);
    update(r, middle+1, end, index, value);

    seg[pos] = seg[l] + seg[r];
}

int binarySearch(int pos, int begin, int end, int k) {
    if (seg[pos] < k) return -1;
    if (begin == end) return begin-1;

    int middle = (begin+end)/2;
    int tmp = binarySearch(2*pos, begin, middle, k);
    if (tmp != -1) return tmp;

    return binarySearch(2*pos+1, middle+1, end, k-seg[2*pos]);
}
