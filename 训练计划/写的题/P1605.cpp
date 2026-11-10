#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
    i64 n;
    cin >> n;

    int L = 0;
    while ((1LL << (L + 1)) <= n) L++;

    i64 X;
    if (n % 4 == 0) X = n;
    else if (n % 4 == 1) X = 1;
    else if (n % 4 == 2) X = n + 1;
    else X = 0;

    i64 Y = 1LL << L;
    for (int j = L; j >= 1; j--) {
        int xj = (X >> j) & 1;
        int yj = (Y >> j) & 1;
        if ((1 ^ xj ^ yj) == 1) Y |= (1LL << (j - 1));
        else Y &= ~(1LL << (j - 1));
    }

    vector<int> d(n + 1, 0);
    for (int j = 0; j <= L; j++) {
        if ((Y >> j) & 1) {
            i64 pos = 1LL << j;
            if (pos <= n) d[pos] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << d[i] << (i == n ? '\n' : ' ');
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int noTsts;
    cin >> noTsts;
    while (noTsts--) {
        solve();
    }
    return 0;
}