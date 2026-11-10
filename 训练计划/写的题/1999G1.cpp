#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 cacl(i64 x1, i64 x2) {
	i64 res;
	cout << "? " << x1 << ' ' << x2 << endl;
	cin >> res;
	return res;
}

void solve() {
	
	i64 l = 2, r = 999;
	while (l < r) {
		i64 x1 =  l + (r - l) / 3, x2 = l + 2 * (r - l) / 3;
		i64 f = cacl(x1, x2);
		if(f == x1 * x2) {
			l = x2 + 1;
		} else if(f == x1 * (x2 + 1)) {
			l = x1 + 1, r = x2;
		} else if(f == (x1 + 1) * (x2 + 1)) {
			r = x1;
		}
	}
	cout << "! " << l << endl;
}

int main() {
	i64 t;
	cin >> t;
	while (t--) {
		solve();
	}
	
	
}