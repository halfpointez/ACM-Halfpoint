#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
	i64 n, M, T;
	cin >> n >> M >> T;
	vector<vector<i64>> dp(M + 1, vector<i64>(T + 1, 0));
	
	for(int i = 1; i <= n; i++) {
		i64 m, t;
		cin >> m >> t;
		for(int j = M; j >= m; j--) {
			for(int k = T; k >= t; k--) {
				dp[j][k] = max(dp[j][k], dp[j - m][k - t] + 1);
			}
		}
	}

	cout << dp[M][T];





	

}