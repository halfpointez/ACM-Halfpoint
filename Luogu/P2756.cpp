#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n';
i64 n, m, timer = 0;
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
	cin >> m >> n;
	g.resize(n + 1);
	match_r.assign(n + 1, -1);
	vis.resize(n + 1, 0);
	while (1) {
		i64 u, v;
		cin >> u >> v;
		if(u == -1 && v == -1) {
			break;
		}
		g[u].push_back(v);
	}
	i64 ans = 0;
	for(int i = 1; i <= m; i++) {
		timer++;
		if(dfs(i)) ans++;
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		if(match_r[i] != -1) {
			cout << i << ' ' << match_r[i] << endl;
		}
	}
	

}