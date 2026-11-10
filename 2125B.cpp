#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}
void solve() {
	i64 a, b, k, sa, sb, gcd_ab;
	cin >> a >> b >> k;
	gcd_ab = gcd(a, b);
	sa = a / gcd_ab;
	sb = b / gcd_ab;
	if(k >= sa && k >= sb) {
		cout << 1 << '\n';
		return;
	}
	cout << 2 << '\n';
	return;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
}