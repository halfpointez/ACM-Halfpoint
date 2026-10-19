#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1e9;
#define endl '\n'
i64 N, P;
vector<vector<i64>> Node;
vector<vector<i64>> dp; //dp[i][j] 以当前结点为根 想要使得与该结点的联通块的数量为j 最少需要割几刀
vector<i64> sz;
void dfs(i64 u, i64 p) {
	dp[u][0] = 1;
	dp[u][1] = 0;
	sz[u] = 1;
	for(auto &v:Node[u]) {
		if(v == p) continue;
		dfs(v, u);
		i64 i_max = min(P, sz[u] + sz[v]);
		for(int i = i_max; i >= 1; i--) {
			dp[u][i] += 1;
			i64 j_max = min((i64)i - 1, sz[v]);
			for(int j = 1; j <= j_max; j++) {
				dp[u][i] = min(dp[u][i], dp[u][i - j] + dp[v][j]);
			}
		}
		sz[u] += sz[v];
	}
}

int main() {
	
	cin >> N >> P;
	Node.resize(N + 1);
	sz.resize(N + 1);
	dp.resize(N + 1, vector<i64>(P + 1, INF));
	
	for(int i = 1; i <= N - 1; i++) {
		i64 I, J;
		cin >> I >> J;
		Node[I].push_back(J);
		Node[J].push_back(I);
	}
	dfs(1, -1);
	i64 ans = 1e9;
	for(int i = 1; i <= N; i++) {
		if(i == 1) ans = min(dp[i][P], ans);
		else ans = min(dp[i][P] + 1, ans);
		
	}

	cout << ans;





}