#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define endl '\n'

int main() {
	i64 H, T;
	cin >> H >> T;
	i64 n;
	cin >> n;
	vector<vector<i64>> dp(H + 1, vector<i64>(T + 1));
	for(int i = 1; i <= n; i++) {
		i64 h, t, kal;
		cin >> h >> t >> kal;
		for(int j = H; j >= h; j--) {
			for(int k = T; k >= t; k--) {
				dp[j][k] = max(dp[j - h][k - t] + kal, dp[j][k]);
			}
		}
	}
	cout << dp[H][T];

}