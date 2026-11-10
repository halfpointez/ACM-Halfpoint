#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

i64 cacl(i64 x, vector<i64> &a, vector<i64> &b) {
	i64 res = 0;
	for(auto &i:a) {
		res += max(0LL, x - i);
	}
	for(auto &i:b) {
		res += max(0LL, i - x);
	}
	return res;
}

int main() {
	i64 n, m;
	cin >> n >> m;
	vector<i64> a(n);
	vector<i64> b(m);
	for(auto &i:a) cin >> i;
	for(auto &i:b) cin >> i;
	i64 l = 0, r = 1e9;
	while (r - l > 3) {
		i64 x1 = l + 1 * (r - l) / 3;
		i64 x2 = l + 2 * (r - l) / 3;
		i64 f1 = cacl(x1, a, b);
		i64 f2 = cacl(x2, a, b);
		if(f1 > f2) l = x1;	
		else r = x2;
	}
	i64 ans = 1e18;
	for(int x = l; x <= r; x++) {
		ans = min(cacl(x, a, b), ans);
	}
	cout << ans;
	
}