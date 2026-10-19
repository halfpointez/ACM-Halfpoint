#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	int ans = n;
	vector<int> a(n);
	for(auto &i:a) cin >> i;
	sort(a.begin(), a.end());
	int MAXN = a.back();
	vector<bool> dp(MAXN + 1, 0);
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		if(dp[a[i]]) {ans -= 1; continue;}
		for(int j = 1; j <= MAXN; j++) {
			if(j - a[i] < 0) continue; 
			dp[j] = dp[j] || dp[j - a[i]];
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
}