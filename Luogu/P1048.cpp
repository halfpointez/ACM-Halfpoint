#include <bits/stdc++.h>
using namespace std;
int main() {
	int T, M;
	cin >> T >> M;
	vector<int> time(M + 1, 0), value(M + 1, 0);
	for(int i = 1; i <= M; i++) {
		cin >> time[i] >> value[i];
	}
	vector<int> dp(T + 1, 0);
	for(int i = 1; i <= M; i++) { //当前考虑的是第i个元素
		for(int j = T; j >= 0; j--) {//从j到更新背包大小 j即当前背包大小
			if(j - time[i] < 0) continue;
			else dp[j] = max(dp[j], dp[j - time[i]] + value[i]); 
		}
	}
	cout << dp[T];
}