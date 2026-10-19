#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define endl '\n'
i64 n, m, ans, timer = 0;
vector<i64> dfn;
vector<vector<pair<i64, i64>>> Node;
vector<i64> low;
vector<bool> is_cut, is_bridge; 

void tarjan(i64 u, i64 edge_id) {
	dfn[u] = low[u] = ++timer;
	i64 child = 0;
	for(auto [v, id]:Node[u]) {
		if(id == edge_id) continue;
		if(!dfn[v]) {
			child++;
			tarjan(v, id);
			low[u] = min(low[u], low[v]);
			if(edge_id != -1 && low[v] > dfn[u]) {
				is_bridge[id] = 1;
			}
			if(edge_id != -1 && low[v] >= dfn[u]) {
				is_cut[u] = 1;
			}
		} else {
			low[u] = min(low[u], dfn[v]);
		}
	}	
	if (edge_id == -1 && child > 1) {
        is_cut[u] = true;
    }
}

int main() {

	cin >> n >> m;
	Node.resize(n + 1); //节点， 边编号
	dfn.assign(n + 1, 0);
	low.assign(n + 1, 0);
	is_cut.assign(n + 1, 0);
	is_bridge.assign(m + 1, 0);
	for(i64 i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back({v, i});
		Node[v].push_back({u, i});
	}
	for(i64 i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i, -1); 
	}

	for(int i = 1; i <= n; i++) {
		if(is_cut[i]) ans++;
	}
	cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		if(is_cut[i]) cout << i << ' ';
	}
}