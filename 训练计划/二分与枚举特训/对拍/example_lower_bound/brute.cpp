// 暴力: 线性扫描找第一个 a[i] >= x (显然正确, O(nq), 小数据足够)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    while (q--) {
        int x;
        cin >> x;
        int ans = n + 1;
        for (int i = 0; i < n; i++) {
            if (a[i] >= x) { ans = i + 1; break; }
        }
        cout << ans << '\n';
    }
    return 0;
}
