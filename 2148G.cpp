#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 MAXN = 2e5 + 1;  // 需要求因数的大小范围
vector<vector<i64>> yin(MAXN + 1);

void sieve() {
  for (int i = 2; i <= MAXN; i++) {
    for (int j = i; j <= MAXN; j += i) {
      yin[j].push_back(i);
    }
  }
}

int main() {
  sieve();
  int t;
  cin >> t;
  vector<i64> cp(2e5 + 1, 0);
  vector<i64> vis(2e5 + 1, 0);

  while (t--) {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto& i : a) cin >> i;

    vector<i64> has;
    i64 ans = 0;
    vector<i64> fullnum;
    for (int i = 0; i < n; i++) {
      vector<i64> cur;
      map<i64, i64> VIS;
      for (auto& j : yin[a[i]]) {
        if (!vis[j]) {
          vis[j] = 1;
          has.push_back(j);
        }
        cp[j]++;
        if (cp[j] <= i)
          ans = max(ans, cp[j]);
        else {
          if (!VIS[j]) {
            cur.push_back(j);
            VIS[j] = 0;
          }
        }
      }

      for (auto& k : fullnum) {
        if (cp[k] != i + 1)
          ans = max(cp[k], ans);
        else if (!VIS[k])
          cur.push_back(k);
      }
      fullnum = cur;
      cout << ans << ' ';
    }

    for (auto& i : has) {
      vis[i] = 0, cp[i] = 0;
    }
    cout << endl;
  }
}