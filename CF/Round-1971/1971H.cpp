#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 n;
vector<vector<i64>> Node;
vector<i64> dfn, low, scc;
stack<i64> S;
vector<i64> instk;
i64 tim = 0, cnt = 0;

int get_node(int x) { //获取当前矩阵位置为1的对应结点
	if(x < 0) return abs(x);
	return x + n;
}

int ne(int x) {
	if(x <= n) return x + n;
	return x - n;
}  //获得反结点

void tarjan(i64 u) {
	dfn[u] = low[u] = ++tim;
	S.push(u);
	instk[u] = 1;
	for(auto &v:Node[u]) {
		if(!dfn[v]) {
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
			if(v == u) break;
		}
	}
}

void solve() {
	cin >> n;
	tim = 0, cnt = 0;
	
	vector<vector<i64>> axis(3, vector<i64>(n));
	Node.assign(2 * n + 1, vector<i64>({}));
	instk.assign(2 * n + 1, 0);
	dfn.assign(2 * n + 1, 0);
	low.assign(2 * n + 1, 0);
	scc.assign(2 * n + 1, 0);
	if(!S.empty()) S.pop();
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < n; j++) {
			cin >> axis[i][j];
		}
	}

	for(int i = 0; i < n; i++) {
		int x = get_node(axis[0][i]), y = get_node(axis[1][i]), z = get_node(axis[2][i]);
		int nx = ne(x), ny = ne(y), nz = ne(z);
		Node[nx].push_back(y);
		Node[ny].push_back(x);
		Node[nx].push_back(z);
		Node[nz].push_back(x);
		Node[ny].push_back(z);
		Node[nz].push_back(y);
	}

	for(int i = 1; i <= 2 * n; i++) {
		if(!dfn[i]) tarjan(i);
	}	

	for(int i = 1; i <= n; i++) {
		if(scc[i] == scc[i + n]) {cout << "NO" << endl; return;}
	}

	cout << "YES" << endl;
	

}


int main() {
	i64 t;
	cin >> t;
	while (t--) {
		solve();
	}
	 
}