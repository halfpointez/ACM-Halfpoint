#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 n, t;
i64 query(i64 l,i64 r) { //back l-r zero_cnt
	i64 cnt_0, cnt_1;
	cout << "? " << l << ' ' << r << endl;
	cin >> cnt_1;
	cnt_0 = r - l + 1 - cnt_1;
	return cnt_0;
}

void solve() {
	i64 l = 1, r = n;
	i64 k; cin >> k;

	while (l < r) {
		i64 mid = l + ((r - l) >> 1);
		i64 sum = query(1, mid);
		if(sum < k) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << "! " << l << endl;
	
}

int main() {

	cin >> n >> t;
	while (t--) {
		solve();
	}
	
}