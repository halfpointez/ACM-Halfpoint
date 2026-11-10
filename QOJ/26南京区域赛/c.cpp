#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	i64 n, m, k;
	cin >> n >> m >> k;
	bool ok = 1;
	i64 U = 0, D = 0, L = 0, R = 0;
	for(int i = 1; i <= k; i++) {
		i64 x, y, h;
		cin >> x >> y >> h;
		if (n > 1 && x != 1 && x != n) ok = false;
		if (m > 1 && y != 1 && y != m) ok = false;
		if(x == 1) U++; 
		if(x == n) D++;
		if(y == 1) L++;
		if(y == m) R++;
	}
	if(!ok) {cout << -1 << '\n'; return;} 
	i64 row = abs(U - D), col = abs(L - R);
	cout << max(row, col) << '\n';
	return;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
}