#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const i64 MOD = 1e9 + 7;


int main() {
	int N, V;
	cin >> N >> V;
	vector<i64> v(N + 1, 0), w(N + 1, 0);

	for(int i = 1; i <= N; i++) {
		cin >> v[i] >> w[i];
	}

	vector<i64> dp(V + 1, 0); //当背包容量为V时候能得的最大价值
	vector<i64> cnt(V + 1, 1); //当背包容量为V时候能得的最大价值的方案数

	for(int i = 1; i <= N; i++) {
		for(int j = V; j >= v[i]; j--) {
			i64 take = dp[j - v[i]] + w[i], n_take = dp[j];
			if(take > n_take) {
				dp[j] = take;
				cnt[j] = cnt[j - v[i]];
			} else if(take == n_take) cnt[j] = (cnt[j - v[i]] + cnt[j]) % MOD;
		}
	}

	cout << cnt[V] % MOD;

	


}