// 示例题: n 个数升序, q 次询问 x
// 输出第一个 a[i] >= x 的下标 (1-based); 不存在则输出 n+1
// 说明: 这里先用 std::lower_bound 展示对拍流程 —— 段 1 把手写版换进来对拍
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
        int pos = int(lower_bound(a.begin(), a.end(), x) - a.begin()); // 0-based
        cout << pos + 1 << '\n'; // 找不到时 pos==n → 输出 n+1
    }
    return 0;
}
