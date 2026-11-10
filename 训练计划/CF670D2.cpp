#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<i64> a;
vector<i64> b;
i64 n, k;
bool check(i64 X) {
	i64 tmp = k;
	for(int i = 1; i <= n; i++) {
		i64 need = a[i] * X;
		if(need > b[i]) {
			tmp -= (need - b[i]);
			if(tmp < 0) return 0;
		}
 	}
	return 1;
}

int main() {
	
	cin >> n >> k;
	a.resize(n + 1), b.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	i64 l = 0, r = 1e14;
	for (int i = 1; i <= n; i++)
	r = min(r, (b[i] + k) / a[i]);
	while (l < r) {
		i64 mid = l + ((r - l + 1) >> 1);
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	
}