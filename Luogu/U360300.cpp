#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
int main() {
	int n;
	cin >> n;
	i64 sum = 0;
	i64 cnt = 1;
	vector<i64> a(n + 1);

	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++) {
		sum += (i64)(i) * (n - i + 1) * a[i];
	}
	cout << sum;
}

