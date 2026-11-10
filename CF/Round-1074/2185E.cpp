#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<i64> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    sort(b.begin(), b.end());

    const i64 INF = 4e18;
    vector<i64> L(n, INF), R(n, INF);
    for (int i = 0; i < n; i++) {
      i64 x = a[i];
      int pos = lower_bound(b.begin(), b.end(), x) - b.begin();
      if (pos > 0) L[i] = x - b[pos - 1];
      if (pos < m) R[i] = b[pos] - x;
    }

    string s;
    cin >> s;

    vector<vector<int>> events(2 * k + 1);
    for (int i = 0; i < n; i++) {
      if (L[i] != INF && L[i] <= k) events[(-L[i]) + k].push_back(i);
      if (R[i] != INF && R[i] <= k) events[R[i] + k].push_back(i);
    }

    vector<bool> dead(n, false);
    int cur = 0, ans = 0;

    // 初始检查（基本无事件，保留无妨）
    for (int id : events[k]) {
      if (!dead[id]) {
        dead[id] = true;
        ans++;
      }
    }

    for (char c : s) {
      if (c == 'L')
        --cur;
      else
        ++cur;
      int idx = cur + k;
      if (!events[idx].empty()) {
        for (int id : events[idx]) {
          if (!dead[id]) {
            dead[id] = true;
            ++ans;
          }
        }
      }
      cout << n - ans << ' ';
    }
    cout << '\n';
  }
}

int main() {
  solve();
  return 0;
}