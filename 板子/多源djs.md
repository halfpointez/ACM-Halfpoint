多源djs 和多源dfs几乎写法一致 思想也一致 值得注意的是 可以将点权转换为一个点 每个点都指向这个点0 路径权就为点权

例:
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1e18;
#define endl '\n'
int main() {
	i64 n, m;
	cin >> n >> m;
	vector<vector<pair<i64, i64>>> Node(n + 1);
	for(int i = 1; i <= m; i++) {
		i64 u, v, w;
		cin >> u >> v >> w;
		Node[u].push_back({2 * w, v});	
		Node[v].push_back({2 * w, u});
	}
	for(int i = 1; i <= n; i++) {
		i64 w; cin >> w;
		Node[0].push_back({w, i});
		Node[i].push_back({w, 0});
	}

	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>> pq;
	pq.push({0, 0});
	vector<bool> vis(n + 1, 0);
	vector<i64> dis(n + 1, INF);
	dis[0] = 0;
	while (!pq.empty()) {
		auto[w, cur] = pq.top();
		if(vis[cur]) {pq.pop(); continue;}
		vis[cur] = 1;
		for(auto [len, u]:Node[cur]) {
			if(dis[cur] + len < dis[u]) dis[u] = w + len;
			pq.push({dis[u], u});
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << dis[i] << ' '; 
	}
	


}