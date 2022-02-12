#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);

using namespace std;

void refresh(int, int, int);
void update(int, int, int, int, int, lli);
lli query(int, int, int, int, int);

typedef struct {
    lli sum;
    lli lzSum;
} Node;

vector<Node> seg;

int main() {
    // ibs; cti;
    int n, m;
    int op, l, r;
    lli v;

    cin >> n >> m;
    seg.resize(4 * n);

    while (m--) {
        cin >> op;

        if (op == 1) {
            cin >> l >> r >> v;
            update(1, 1, n, l + 1, r, v);    
        } else {
            cin >> l >> r;
            cout << query(1, 1, n, l + 1, r) << "\n"; 
        }
    }

    return 0;
}

void refresh(int pos, int start, int end) {
    if (seg[pos].lzSum == 0) return;

    lli num = seg[pos].lzSum;
    seg[pos].lzSum = 0;
    seg[pos].sum += (end - start + 1) * num;

    if (start == end) return;

    int l = 2 * pos;
    int r = 2 * pos + 1;
    seg[l].lzSum += num;
    seg[r].lzSum += num;
}

void update(int pos, int start, int end, int p, int q, lli val) {
    refresh(pos, start, end);

    if(q < start or p > end) return; 

    if (p <= start and end <= q) {
        seg[pos].lzSum += val;
        refresh(pos, start, end);
        return;
    }

    int m = (start + end) / 2;
    int l = 2 * pos;
    int r = 2 * pos + 1;

    update(l, start, m, p, q, val);
    update(r, m + 1, end, p, q, val);

    seg[pos].sum = seg[l].sum + seg[r].sum;
}

lli query(int pos, int start, int end, int l, int r) {
    refresh(pos, start, end);
    if (r < start || l > end) return INT_MAX;
    if (l <= start && end <= r) return seg[pos].sum;

    int middle = (start + end) / 2;

    return min(
        query(2 * pos, start, middle, l, r),
        query(2 * pos + 1, middle + 1, end, l, r)
    );
}
