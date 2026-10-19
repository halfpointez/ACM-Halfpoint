#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> edge(n + 1, 0); 

    for (int i = 0; i < n; i++) {
        int d = b[i];
        if (d <= 0) continue;

        int L = i - d + 1;
        int R = i + d - 1;
        L = max(L, 0);
        R = min(R, n - 1);

        if (L <= R) {
            edge[L]++;
            edge[R + 1]--;
        }
    }

    vector<int> f(n, 0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += edge[i];
        f[i] = (cur > 0);
    }

    bool jud = 1;

    for (int i = 0; i < n && 1; i++) {
        int d = b[i];
        if (d == -1) continue;

        if (d == 0) {
            if (f[i]) jud = 0;
        } else {
            bool p = 0;
            if (i - d >= 0 && !f[i - d]) p = 1;
            if (i + d < n && !f[i + d]) p = 1;
            if (!p) jud = 0;
        }
    }

    if (!jud) {
        cout << -1 << endl;
        return;
    }

    string ans;
    ans.reserve(n);

    for (int i = 0; i < n; i++) {
        if(f[i]) {
            ans.push_back('0');
        } else ans.push_back('1');
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
    return 0;
}