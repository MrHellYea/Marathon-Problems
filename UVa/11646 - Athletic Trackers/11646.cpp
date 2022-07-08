#include <bits/stdc++.h>

typedef long long int lli;
#define ibs ios_base::sync_with_stdio(false);
#define cti cin.tie(NULL);
#define endl "\n"

using namespace std;

int main() {
    ibs; cti;
    double a, b;
    double ratio, radius;
    double angle, arc;
    double length, width;
    int cases = 1;

    while (scanf("%lf : %lf", &a, &b) == 2) {
        double min = 0;
        double max = 400;

        while (abs(max - min) > 1e-10) {
            ratio = b / a;
            length = (min + max) / 2;
            width = ratio * length;
            radius = sqrt(pow(length / 2, 2) + pow(width / 2, 2));
            angle = atan(width / length) * 180 / M_PI;
            arc = 4 * M_PI * radius * angle / 360;

            if (2 * (arc + length) > 400) {
                max = length;
            } else {
                min = length;
            }
        }

        cout << "Case " << cases++ << ": ";
        cout << fixed << setprecision(10) << length << " " << width << endl;
    }

    return 0;
}
