#include<bits/stdc++.h>
using i64 = long long;
const i64 MOD = 1e9 + 7;

int main(){

	
	
	int N,V;
	std::cin >> N >> V;

	std::vector<i64> dp(V + 1,0);
	std::vector<i64> cnt(V + 1,1);
	
	for(int i = 1;i <= N;i++){
		int tv = 1,tw = 2;
		std::cin >> tv >> tw;
		for(int j = V;j >= tv;j--){
			i64 take = dp[j - tv] + tw,n_take = dp[j];
			if(take > n_take){
				dp[j] = take;
				cnt[j] = cnt[j - tv];
			}
			else if(take == n_take){
				cnt[j] = (cnt[j - tv] + cnt[j]) % MOD;
			}
		}
	}
	std::cout << cnt[V] << "\n";
	return 0;
}