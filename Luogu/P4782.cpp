#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
const i64 INF = 1e18;
i64 n, m;
vector<vector<i64>> Node;
vector<i64> dfn, low, root, scc, scc_w;
vector<bool> instk;
stack<i64> S;
i64 tim = 0, cnt = 0;

void tarjan(i64 u) {
	dfn[u] = low[u] = ++ tim;
	S.push(u);
	instk[u] = 1;
	for(auto &v:Node[u]) {
		if(dfn[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(dfn[u] == low[u]) {
		cnt++;
		while (1) {
			i64 v = S.top(); S.pop();
			scc[v] = cnt;
			instk[v] = 0;
			root[v] = u;
			if(v == u) break;
		}
	}

}

void _2SAT() {
	vector<bool> ans(2 * n + 1, 0);
	cin >> n >> m;
	Node.resize(2 * n + 1); // 0 到 n - 1 是0 n到2n是1
	scc.assign(2 * n + 1, 0);
	dfn.assign(2 * n + 1, 0);
	low.assign(2 * n + 1, 0);
	root.assign(2 * n + 1, 0);
	instk.assign(2 * n + 1, 0);

	for(int k = 0; k < m; k++) {
		i64 i, a, j, b;
		cin >> i >> a >> j >> b;
		i64 x = i, y = j, nx = x + n, ny = y + n;
		if(a == 1) {x = i + n; nx = i;}
		if(b == 1) {y = j + n; ny = j;}
		Node[nx].push_back(y);
		Node[ny].push_back(x); 
	}
	
	for(int i = 0; i <= 2 * n; i++) {
		if(dfn[i] == 0) {
			tarjan(i);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(scc[i] == scc[i + n]) {cout << "IMPOSSIBLE"; return;}
	}
	cout << "POSSIBLE" << endl;
	for(int i = 1; i <= n; i++) {
		if(scc[i] > scc[i + n]) cout << 1 << ' ';
		else cout << 0 << ' ';
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	_2SAT();


}