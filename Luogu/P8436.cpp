#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;

i64 n, m, timer;
vector<vector<pair<i64, i64>>> Node;
vector<i64> low, dfn;
stack<i64> S;
vector<vector<i64>> ans;


void tarjan(i64 u, i64 p_id) {
	dfn[u] = low[u] = ++timer;
	S.push(u);
	for(auto [v, id]:Node[u]) {
		if(id == p_id) continue;
		if(dfn[v] == 0) {
			tarjan(v, id);
			low[u] = min(low[u], low[v]);
		} else if(dfn[v] < dfn[u]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(dfn[u] == low[u]) {
		vector<i64> tmp;
		while (1) {
			i64 cur = S.top();
			S.pop();
			tmp.push_back(cur);
			if(cur == u) break;
		}
		ans.push_back(tmp);
	}


	

}


int main() {
	cin >> n >> m;
	Node.resize(n + 1);
	low.assign(n + 1, 0);
	dfn.assign(n + 1, 0);
	for(int i = 1; i <= m; i++) {
		i64 u, v;
		
		cin >> u >> v;
		if(u == v) continue;
		Node[u].push_back({v, i});
		Node[v].push_back({u, i});
	}

	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) tarjan(i, -1);
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