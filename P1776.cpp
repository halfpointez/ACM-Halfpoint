#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	i64 n, W;
	cin >> n >> W;
	vector<i64> v, w;
	for(int i = 1; i <= n; i++) {
		i64 v_tmp, w_tmp, m;
		cin >> v_tmp >> w_tmp >> m;
		i64 cnt = 1;
		while (1) {
			i64 v_sum, w_sum;
			if(m - cnt < 0) {
				v_sum = m * v_tmp, w_sum = m * w_tmp;
				v.push_back(v_sum);
				w.push_back(w_sum);
				break;
			}
			v_sum = cnt * v_tmp, w_sum = cnt * w_tmp;
			v.push_back(v_sum);
			w.push_back(w_sum);
			m -= cnt;
			cnt *= 2;
		}
	}

	vector<i64> dp(W + 1, 0);
	dp[0] = 0;
	for(int i = 0; i < v.size(); i++) {
		for(int j = W; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	cout << dp[W];
}