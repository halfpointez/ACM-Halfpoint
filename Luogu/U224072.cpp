#include <bits/stdc++.h>
using namespace std;


int main() {
	int N, V;
	cin >> N >> V;

	vector<vector<int>> dp(N + 2, vector<int>(V + 2, 0));
	vector<int> ans;
	vector<int> v(N + 1, 0), w(N + 1, 0);
	for(int i = 1; i <= N; i++) {
		cin >> v[i] >> w[i];
	}

	for(int i = N; i >= 1; i--) {
		for(int j = 0; j <= V; j++) {
			dp[i][j] = dp[i + 1][j];              // 不选
    		if (j >= v[i]) {
        		dp[i][j] = max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);  // 选
    		}
		}		
	}
	int MAX = dp[1][V];
	int bag = V;
	for(int i = 1; i <= N; i++) {
		if(bag - v[i] < 0) continue;
		if(w[i] + dp[i + 1][bag - v[i]] == MAX) {
			ans.push_back(i);
			bag -= v[i];
			MAX -= w[i]; 
		} 
	}
	
	for (int x : ans) cout << x << " ";


}