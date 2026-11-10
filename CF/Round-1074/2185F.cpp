#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;
#define endl '\n'

i128 calc(i128 k, i128 n, i128 a, i128 b) {
  i128 d = a - 1;
  i128 m = n - k;
  i128 c = k * d;

  i128 s1 = k + d * k * (k + 1) / 2;

  i128 poison;
  if (m <= c) {
    poison = m * c - m * (m - 1) / 2;
  } else {
    poison = c * (c + 1) / 2;
  }

  return s1 + m * b + poison;
}

i128 f(i128 n, i128 a, i128 b) {
  const i64 LIMIT = 55000;
  i128 best = 0;
  i128 upper = min(n, (i128)LIMIT);

  for (i128 k = 0; k <= upper; k++) {
    best = max(best, calc(k, n, a, b));
  }

  return best;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  i64 x, a, b;
  cin >> x >> a >> b;

  i64 l = 1, r = x;
  while (l < r) {
    i64 mid = (l+ r) / 2;
    if (f(mid, a, b) >= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << l << endl;
  return 0;
}