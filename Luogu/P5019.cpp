#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;

int main() {
	i64 n;
	cin >> n;
	vector<i64> a(n + 1, 0);
	i64 ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) {
		ans += max(0LL, a[i] - a[i - 1]);
	}
	cout << ans;
}