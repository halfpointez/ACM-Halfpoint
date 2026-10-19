#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = n - 4;
    vector<i64> v(m + 1);
    for (int x = 1; x <= m; x++) v[x] = a[x] + a[x + 2] - a[x + 4];
    map<i64, i64> cnt;
    for (int x = 1; x <= m; x++) cnt[v[x]]++;

    i64 ans = 0;
    for (auto &i : cnt) {
        ans += (i64)i.second * (i.second - 1) / 2;
    }
    for (int x = 1; x <= m; x++) {
        if (x + 2 <= m && v[x] == v[x + 2]) ans--;
        if (x + 4 <= m && v[x] == v[x + 4]) ans--;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}