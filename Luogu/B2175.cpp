#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<i64> a(n);
    vector<pair<i64, int>> b(m);   // (值, 原下标)

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    // 按 (值, 下标) 排序
    sort(b.begin(), b.end());

    vector<int> lis;   // 贪心维护 LIS，存的是 B 中的下标

    for (int i = 0; i < n; i++) {
        // 找到 b 中所有值等于 a[i] 的区间 [lo, hi)
        auto lo = lower_bound(b.begin(), b.end(),
                              make_pair(a[i], INT_MIN));
        auto hi = upper_bound(b.begin(), b.end(),
                              make_pair(a[i], INT_MAX));

        for (auto it = hi; it != lo; ) {
            --it;
            int p = it->second;

            auto ptr = lower_bound(lis.begin(), lis.end(), p);
            if (ptr == lis.end()) lis.push_back(p);
            else *ptr = p;
        }
    }

    cout << lis.size() << endl;
    return 0;
}