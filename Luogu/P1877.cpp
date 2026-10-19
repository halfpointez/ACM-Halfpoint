#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
	int n, bgin, MAX;
	cin >> n >> bgin >> MAX;
	vector<bool> dp(MAX + 1, 0);
	vector<int> c(n);

	for(int i = 0; i < n; i++) cin >> c[i];

	dp[bgin] = 1;

	for(int i = 0; i < n; i++) {
		vector<bool> ndp(MAX + 1, 0);
		for(int j = MAX; j >= 0; j--) {
			int cur1 = j + c[i], cur2 = j - c[i];
			if(cur1 <= MAX) ndp[j] = ndp[j] | dp[cur1];  
			if(cur2 >= 0) ndp[j] = ndp[j] | dp[cur2];
		}
		dp = ndp;
	}

	i64 ans = -1;

	for(int i = 0; i <= MAX; i++) {
		if(dp[i]) ans = i;
	}

	cout << ans;
}