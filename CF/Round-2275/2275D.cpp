#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;
#define endl '\n'

struct Lab {
    i64 a, b, c, s, w;
};

void solve() {
    i64 n, k;
    cin >> n >> k;
    vector<Lab> v(n);
    i64 lim = (1LL << 62), mn = (1LL << 62);

    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c;
        v[i].s = v[i].a + v[i].b + v[i].c;
        mn = min(mn, v[i].s);
        if (v[i].a == v[i].b && v[i].b == v[i].c) {
            lim = min(lim, v[i].s);
            v[i].w = -1;
        } else if (v[i].a <= v[i].b && v[i].b <= v[i].c) {
            v[i].w = 2 * (min(v[i].b - v[i].a, v[i].c - v[i].b) + 1);
        } else {
            v[i].w = 0;
        }
    }

    vector<Lab> u;
    for (auto &x : v)
        if (x.w != -1 && x.s < lim) u.push_back(x);

    if (u.empty()) {
        cout << min(mn, lim) << endl;
        return;
    }

    sort(u.begin(), u.end(), [](const Lab &x, const Lab &y) {
        return x.s < y.s;
    });

    i64 used = u[0].w, cnt = 1, cur = u[0].s;
    if (used > k) {
        cout << min(mn, lim) << endl;
        return;
    }

    bool ok = false;
    for (size_t i = 1; i < u.size(); i++) {
        i64 ns = u[i].s, w = u[i].w;
        if (ns == cur) {
            if ((i128)used + w > k) {
                cout << min(cur, lim) << endl;
                ok = true;
                break;
            }
            used += w;
            cnt++;
        } else {
            i128 need = (i128)(ns - cur) * cnt + w;
            if ((i128)used + need <= k) {
                used += (i64)need;
                cur = ns;
                cnt++;
            } else {
                i64 rem = k - used;
                i64 d = min(ns - cur, rem / cnt);
                cur += d;
                cout << min(cur, lim) << endl;
                ok = true;
                break;
            }
        }
    }

    if (!ok) {
        cur += (k - used) / cnt;
        cout << min(cur, lim) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}