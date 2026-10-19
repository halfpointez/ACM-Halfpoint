#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        i64 n, x, m;
        cin >> n >> x >> m;
        i64 L = x, R = x;         
        for (int i = 0; i < m; i++) {
            i64 l, r;
            cin >> l >> r;
            if (l <= R && L <= r) { 
                L = min(L, l);
                R = max(R, r);
            }
        }
        cout << R - L + 1 << '\n';
    }
    return 0;
}