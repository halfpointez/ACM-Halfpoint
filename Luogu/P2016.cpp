#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<vector<i64>> Node; 
vector<bool> node_vis;
vector<vector<i64>> dp; //0为不选, 1为选
int n;

void dfs(i64 u, i64 p) {
	dp[u][1] += 1;
	for(auto &v:Node[u]) {
		if(v == p) continue;
		dfs(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][0], dp[v][1]);
	}
	
}


int main() {
	cin >> n;
	Node.resize(n + 1);
	node_vis.resize(n + 1, 0);
	dp.resize(n + 1, vector<i64>(2, 0));
	i64 edge_id = 0;
	i64 ans = 0;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		int k;
		cin >> k;
		while (k--) {
			int v;
			cin >> v;
			Node[t].push_back(v);
			Node[v].push_back(t);
			edge_id++;
		}
	} 
	dfs(1, -1);
	cout << min(dp[1][0], dp[1][1]);
}