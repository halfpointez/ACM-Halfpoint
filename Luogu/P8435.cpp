#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 n, m, tim = 0, x = 0;
vector<i64> dfn, low;
stack<array<i64, 3>> S;
vector<vector<pair<i64, i64>>> Node;
vector<vector<i64>> ans;
 
void tarjan(i64 u, i64 p_edge) {
	dfn[u] = low[u] = ++tim;
	for(auto [v, id] : Node[u]) {
		if(id == p_edge) continue;
		if(!dfn[v]) {
			S.push({u, v, id});
			tarjan(v, id);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) {
				x++;
				vector<i64> tmp;
				while (1) {
					auto[a, b, eid] = S.top();
					S.pop();
					tmp.push_back(a);
					tmp.push_back(b);
					if(eid == id) break;
				}
				sort(tmp.begin(), tmp.end());
				tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end() );
				ans.push_back(tmp);
			}
		} else if(dfn[v] < dfn[u]) {//回边
			S.push({u, v, id});
			low[u] = min(low[u], dfn[v]);
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	Node.resize(n + 1);
	dfn.resize(n + 1, 0);
	low.resize(n + 1, 0);

	for(int i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		if (u == v) continue; // 忽略自环，最后孤立点逻辑会处理只有自环的点 按照题目要求决定放不放
		Node[u].push_back({v, i});
		Node[v].push_back({u, i});
	}

	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			if(Node[i].empty()) {
				ans.push_back({i});
			} else tarjan(i, -1);
		} 
	}

	cout << ans.size() << endl;
	for(auto &i:ans) {
		cout << i.size() << ' ';
		for(auto &j:i) {
			cout << j << ' ';
		}
		cout << endl;
	}

}