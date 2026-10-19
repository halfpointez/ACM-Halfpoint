#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;
#define endl '\n'

bool check(i128 mid, vector<i64> &a, vector<i64> &c, i64 n, i64 h) {
	i128 damage = 0;
	for(int i = 0; i < n; i++) {
		damage += (i128)a[i] * ((mid + c[i] - 1) / c[i]);
	}
	
	if(damage < h) {
		return 1;
	} return 0;
}

void solve() {
	int t;
	cin >> t;
	while (t--) {
		i64 h, n;
		cin >> h >> n;
		vector<i64> a(n), c(n);
		for(auto &i:a) cin >> i;
		for(auto &i:c) cin >> i;
		i64 l = 1, r = 1e18;
		while (l < r) {
			i64 mid = l + (r - l >> 1);
			if(check(mid, a, c, n ,h)) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		cout << l << endl;
	}
	
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}