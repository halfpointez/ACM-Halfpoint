#include <bits/stdc++.h>
using namespace std;

// 自定义字典序比较两个 deque<int>
bool cmpDeque(const deque<int>& a, const deque<int>& b) {
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<deque<int>> a;
        a.reserve(n);

        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            deque<int> dq;
            for (int j = 0; j < k; ++j) {
                int x;
                cin >> x;
                dq.push_back(x);
            }
            a.push_back(move(dq));
        }

        // 按长度降序排序（与 Python 的 key=lambda x: -len(x) 一致）
        sort(a.begin(), a.end(), [](const deque<int>& x, const deque<int>& y) {
            return x.size() > y.size();
        });

        vector<int> ans;
        ans.reserve(200000);  // 预估容量

        while (!a.empty()) {
            // 找到字典序最小的 deque（min(a)）
            auto it = min_element(a.begin(), a.end(), cmpDeque);
            deque<int> cur = *it;   // 拷贝一份，因为原 deque 后续会被修改

            // ans += cur
            ans.insert(ans.end(), cur.begin(), cur.end());

            // 弹出末尾长度 <= cur.size() 的 deque
            while (!a.empty() && a.back().size() <= cur.size()) {
                a.pop_back();
            }

            // 对剩余的每个 deque 执行 popleft() 共 cur.size() 次
            for (auto& dq : a) {
                for (size_t j = 0; j < cur.size(); ++j) {
                    if (!dq.empty()) dq.pop_front();
                }
            }
        }

        // 输出 ans
        for (size_t i = 0; i < ans.size(); ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}