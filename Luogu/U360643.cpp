#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
int main() {
	int n;
	cin >> n;
	int MAXN = (1 << 16) + 1;
	vector<int> dp(MAXN + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		int tmp;
		cin >> tmp;
		for(int j = MAXN; j >= 0 ; j--) {
			if(j - tmp < 0) continue;
			else dp[j] = dp[j] ^ dp[j - tmp];  
		}
	}
	i64 ans = 0;
	for(int i = 0; i <= MAXN; i++) {
		if(dp[i]) ans ^= i; 
	}

	cout << ans;
}