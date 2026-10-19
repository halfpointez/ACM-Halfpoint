#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
int main() {
	int n;
	cin >> n;
	i64 ans = 0;
	vector<i64> a(n + 1);

	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++) {
		if((i64)((i) * (n - i + 1)) & 1) {
			ans ^= a[i];
		}
	}
	cout << ans;
}