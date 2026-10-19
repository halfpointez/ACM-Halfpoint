#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<i64> happy;
vector<vector<i64>> Node; 
vector<bool> has_p;
vector<vector<i64>> dp;

void dfs(i64 u, i64 p) {
	dp[u][1] = happy[u];
	for(auto v:Node[u]) {
		if(v == p) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][1], dp[v][0]); 
		dp[u][1] += dp[v][0];
	}
	
}

void solve() {
	int n;
	cin >> n;
	happy.resize(n + 1);
	Node.resize(n + 1);
	has_p.resize(n + 1, 0);
	dp.resize(n + 1, vector<i64>(2, 0)); //1选该结点 0不选该结点

	for(int i = 1; i <= n; i++) {
		cin >> happy[i];
	}

	for(int i = 1; i <= n - 1; i++) {
		i64 l, k;
		cin >> l >> k;
		Node[l].push_back(k);
		Node[k].push_back(l);
		has_p[l] = 1;
	}




	for(int i = 1; i <= n; i++) {
		if(!has_p[i]) {
			dfs(i, -1);
			cout << max(dp[i][0], dp[i][1]) << endl;
			break;
		}
	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();		
}