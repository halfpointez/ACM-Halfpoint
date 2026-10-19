#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const i64 INF = -1e18 + 5;

i64 n;
i64 ans = INF;
vector<i64> a;
vector<i64> sum; //当前完全子树的愉悦和
vector<i64> best; //当前结点所有的子树的最大的愉悦值
vector<vector<i64>> Node;


void dfs(i64 u, i64 p) {
	i64 MAX_NUM1 = INF, MAX_NUM2 = INF;
	sum[u] += a[u];
	for(auto v:Node[u]) {
		if(p == v) continue;
		dfs(v, u);
		sum[u] += sum[v];
		best[u] = max(best[u], best[v]);
		if(best[v] > MAX_NUM1) {
			MAX_NUM2 = MAX_NUM1;
			MAX_NUM1 = best[v];
		} else if (best[v] > MAX_NUM2){
			MAX_NUM2 = best[v];
		}
	}	
	best[u] = max(best[u], sum[u]);

	if(MAX_NUM1 != INF && MAX_NUM2 != INF) {
		ans = max(MAX_NUM1 + MAX_NUM2, ans);
	}
}


void solve() {
	cin >> n;
	a.resize(n + 1, 0);
	sum.resize(n + 1, 0);
	best.resize(n + 1, INF);
	Node.resize(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}		

	for(int i = 1; i < n; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}

	dfs(1, -1);

	if(ans != INF) {
		cout << ans;
		return;
	}
	
	cout << "Impossible";
	return;

}

int main() {
	solve();
}