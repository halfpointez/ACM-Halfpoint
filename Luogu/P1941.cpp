#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1e9;
#define endl '\n'
i64 n, m, k;
vector<vector<i64>> dp;
vector<vector<pair<i64, i64>>> up;
vector<pair<i64, i64>> range;
vector<bool> has_pipe;
i64 pass_cnt = 0;

void dp_func() {
    for(int i = 1; i <= m; i++) {
        dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        auto [j_min, j_max] = range[i];
        for(int j = j_min; j <= j_max; j++) {
            if(j == m) {
                for(auto arr : up[i - 1]) {
                    auto [h, cnt] = arr;
                    for(int k = j - h; k <= m; k++) {
                        if(k <= 0) continue;
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + cnt);
                    }
                }
            }
            for(auto arr : up[i - 1]) {
                auto [h, cnt] = arr;
                if(j - h <= 0 || j - h > m) continue;
                dp[i][j] = min(dp[i][j], dp[i - 1][j - h] + cnt);
            }
        }
        // 检查可达性
        bool reachable = false;
        for(int j = 1; j <= m; j++) {
            if(dp[i][j] < INF) {
                reachable = true;
                break;
            }
        }
        if(!reachable) {
            cout << 0 << endl << pass_cnt << endl;
            exit(0);
        }
        if(has_pipe[i]) {
            pass_cnt++;
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    dp.resize(n + 1, vector<i64>(m + 1, INF));
    up.resize(n + 1);
    range.resize(n + 1);
    has_pipe.assign(n + 1, false);
    range[n] = {1, m};
    for(int i = 0; i < n; i++) {
        range[i] = {1, m};
        i64 x, y;
        cin >> x >> y;
        up[i].push_back({-y, 0});
        i64 sum = x, cnt = 1;
        while(1) {
            up[i].push_back({sum, cnt});
            if(sum >= m) break;
            cnt++;
            sum += x;
        }
    }
    for(int i = 0; i < k; i++) {
        i64 p, l, h;
        cin >> p >> l >> h;
        range[p] = {l + 1, h - 1};
        has_pipe[p] = true;
    }

    dp_func();

    i64 ans = INF;
    for(int i = 1; i <= m; i++) {
        ans = min(ans, dp[n][i]);
    }
    if(ans < INF) {
        cout << 1 << endl << ans << endl;
    } else {
        cout << 0 << endl << pass_cnt << endl;
    }
}

int main() {
    solve();
}