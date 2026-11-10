#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
  int n;
  cin >> n;
  vector<i64> a(n);
  for (auto& i : a) cin >> i;
  i64 ans = 0;
  i64 l = 0, r = n - 1, l_max = a[0], r_max = a[n - 1];
  while (l <= r) {
	if(l_max < r_max) {
		ans += l_max - a[l];
		l++;
		l_max = max(a[l], l_max);
	} else {
		ans += r_max - a[r];
		r--;
		r_max = max(a[r], r_max);
	}
  }
  
  cout << ans << endl;
}