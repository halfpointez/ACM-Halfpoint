#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	vector<i64> b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i] - i;
	}
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	i64 ans = 0;

	for(int i = 0; i < b.size();) {
		i64 j = i;
		i64 tmp = 1;
		while (j < b.size() - 1 && b[j + 1] - b[j] == 1) {
			tmp++;
			j++;
		}
		ans = max(ans, tmp);
		i = j + 1;
	}

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}