#include <bits/stdc++.h>

#include <iomanip>
using namespace std;
#define endl '\n'
using i64 = long long;
using f64 = double;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  cout << fixed << setprecision(12);

  while (t--) {
    i64 m, r, c;
    cin >> m >> r >> c;

    f64 ans;
    if (c <= m) {
      ans = 1.0L;
    } else {
      i64 k = (c - m + (m + r) - 1) / (m + r);

      i64 n1 = (k + 1) * m;
      i64 d1 = n1 + k * r;
      f64 v1 = (f64)n1 / d1;

      i64 n2 = k * m;
      i64 d2 = c;
      f64 v2 = (f64)n2 / d2;

      ans = max(v1, v2);
    }

    cout << ans << endl;
  }
}