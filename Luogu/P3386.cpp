#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

i64 n, m, e, timer = 0;
vector<vector<i64>> g;
vector<i64> match_r;
vector<i64> vis;

bool dfs(i64 u) {
	for(auto &v:g[u]) {
		if(vis[v] == timer) continue;
		vis[v] = timer;
		if(match_r[v] == -1 || dfs(match_r[v])) {
			match_r[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {

	cin >> n >> m >> e;
	g.resize(n + 1);
	match_r.assign(m + 1, -1);
	vis.assign(m + 1, 0);

	for(int i = 1; i <= e; i++) {
		i64 u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	i64 ans = 0;
	for(i64 i = 1; i <= n; i++) {
		timer++;
		if(dfs(i)) ans++;
	}
	cout << ans << endl;
}