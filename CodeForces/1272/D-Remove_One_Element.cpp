#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    int n, element, ans = 1;
    cin >> n;
    
    vector<int> a(n, 1), r = a, l = a;

    for (int i = 0; i < n; i++) {
        cin >> element;
        a[i] = element;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] > a[i]) { r[i] = r[i + 1] + 1; }
        ans = max(ans, r[i]);
    }

    for (int i = 1; i < n; i++) {
        if (a[i-1] < a[i]) { l[i] = l[i-1] + 1; }
        ans = max(ans, l[i]);
    }

    for (int i = 0; i < n-2; i++) {
        if (a[i] < a[i+2]) { ans = max(ans, l[i] + r[i+2]); }
    }

    cout << ans << endl;

    return 0;
}
