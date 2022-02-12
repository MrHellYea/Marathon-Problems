#include <iostream>

#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)

using namespace std;
const int N = 3e5 + 10;

int n, segmentArray[4 * N], a[N], m, l, r, w;

int query(int L, int R, int position=1, int start=1, int end=n) {
    if (L > R) {
        return 0;
    }

    if (L == start && R == end) {
        return segmentArray[position];
    }

    int middle = (start + end) / 2;
    int leftChildPosition = 2 * position;
    int rightChildPosition = 2 * position + 1;
    int x, y;

    x = query(L, min(middle, R), leftChildPosition, start, middle);
    y = query(max(L, middle + 1), R, rightChildPosition, middle + 1, end);

    if (x == 0 && y == 0) {
        return segmentArray[position];
    }

    return max(x, y);
}

void update(int L, int R, int value, int pos=1, int start=1, int end=n) {
    if (L > end || R < start || end < start) {
        return;
    }
    
    if (segmentArray[pos] != 0) {
        return;
    }

    if (L <= start && end <= R) {
        segmentArray[pos] = value;
        return;
    }

    int middle = (start + end) / 2;
    int leftChildPosition = 2 * pos;
    int rightChildPosition = 2 * pos + 1;

    update(L, R, value, leftChildPosition, start, middle);
    update(L, R, value, rightChildPosition, middle + 1, end);
}

int main() {
    ibs; cti;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> l >> r >> w;

        update(l, w - 1, w);
        update(w + 1, r, w);
    }

    for (int i = 1; i <= n; ++i) {
        cout << query(i, i) << " ";
    } cout << "\n";

    return 0;
}