#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> courses; // {总耗时, 截止时间}
    int maxT = 0;

    for (int i = 0; i < n; ++i) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        int p = a + b + c;
        if (p <= t) {
            courses.emplace_back(p, t);
            maxT = max(maxT, t);
        }
    }

    // 按截止时间升序排序
    sort(courses.begin(), courses.end(), [](auto &x, auto &y) {
        return x.second < y.second;
    });

    const int NEG = -1e9;
    vector<int> dp(maxT + 1, NEG);
    dp[0] = 0;

    for (auto [p, t] : courses) {
        for (int j = t; j >= p; --j) {
            if (dp[j - p] != NEG) {
                dp[j] = max(dp[j], dp[j - p] + 1);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= maxT; ++j) {
        ans = max(ans, dp[j]);
    }

    cout << ans << '\n';
    return 0;
}