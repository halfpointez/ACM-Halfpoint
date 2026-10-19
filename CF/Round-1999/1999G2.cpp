#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 query(i64 a, i64 b) {
	i64 res;
	cout << "? " << a << ' ' << b << endl;
	cin >> res;
	return res;
}

void ans(i64 x) {
	cout << "! " << x << endl;
}

void solve() {
	i64 lp = 1, rp = 1000;
	while (lp < rp) {
		i64 l = lp + (rp - lp) / 3, r = lp + (rp - lp) / 3 * 2;
		i64 ask = query(l, r);
		if((l + 1) * (r + 1) == ask) {
			lp = lp, rp = l;
		} else if(l * (r + 1) == ask) {
			lp = l + 1, rp = r;
		} else if(l * r == ask) {
			lp = r + 1, rp = rp;
		}
	}
	ans(lp);

}

int main() {
	i64 T;
	cin >> T;
	while (T--) {
		solve();
	}

}