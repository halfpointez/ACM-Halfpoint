#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve() {
	int n, k;
	cin >> n >> k;
	vector<i64> a(n);
	for(auto &i:a) cin >> i;
	if(k >= 2) {
		cout << "YES" << '\n';
		return;
	}
	for(int i = 1; i < n; i++) {
		if(a[i] < a[i - 1]) {
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
	return;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
}