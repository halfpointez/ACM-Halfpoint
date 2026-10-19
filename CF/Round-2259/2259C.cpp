#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> pre(n + 2, -1), nxt(n + 2, -1);
    for (int i = 1; i <= n; i++) {
        pre[i] = (a[i] == 1) ? i : pre[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        nxt[i] = (a[i] == 1) ? i : nxt[i + 1];
    }

    int best_len = 0, best_L = -1, best_R = -1;

    auto update = [&](int L, int R) {
        if (L > R) swap(L, R);
        int len = R - L + 1;
        if (len > best_len) {
            best_len = len;
            best_L = L;
            best_R = R;
        }
    };


    bool has_one = false;
    int first_neg = -1, last_neg = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) has_one = true;
        if (a[i] == -1) {
            if (first_neg == -1) first_neg = i;
            last_neg = i;
        }
    }
    if (!has_one) {
        if (first_neg != -1 && last_neg != -1 && first_neg != last_neg) {
            update(first_neg, last_neg);         
        } else if (first_neg != -1) {
            update(first_neg, first_neg);         
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            if (pre[i] != -1 && nxt[i] != -1 && pre[i] != nxt[i])
                update(pre[i], nxt[i]);
        } else if (a[i] == -1) {
            if (pre[i] != -1) update(pre[i], i);
            if (nxt[i] != -1) update(i, nxt[i]);
            if (pre[i] != -1 && nxt[i] != -1) update(pre[i], nxt[i]);
        } else { // a[i] == 0
            if (pre[i] != -1 && nxt[i] != -1) update(pre[i], nxt[i]);
        }
    }

    if (best_len == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0) {
                best_len = 1;
                best_L = best_R = i;
                break;
            }
        }
    }

    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) ans[i] = 1;
    }
    if (best_len >= 1) {
        ans[best_L] = 1;
        ans[best_R] = 1;
        for (int i = best_L + 1; i < best_R; i++) ans[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}