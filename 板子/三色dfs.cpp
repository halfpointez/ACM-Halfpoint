#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<i64> get_path(vector<vector<i64>> &Node, vector<i64> &color, vector<i64> &Path, i64 node) {
	vector<i64> ans;
	for(int i = Path.size() - 1; i >= 0; i--) {
		ans.push_back(Path[i]);
		if(Path[i] == node) break;
	}
	return ans;
}

bool _3c_dfs(vector<vector<i64>> &Node, vector<i64> &color, vector<i64> &Path, i64 cur, vector<i64> &ans) {
	if(color[cur] == 0) color[cur] = 1;
	bool jud = 0;
	for(auto &i:Node[cur]) {
		if(color[i] == 2) continue;
		if(color[i] == 1) {
			jud = 1;
			continue;
		}
		if(color[i] == 0) {
			if(_3c_dfs(Node, color, Path, i, ans)) jud = 1;
		}
	}
	if(jud == 1) return 1;
	color[cur] = 2;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 n, m;
	cin >> n >> m;
	vector<vector<i64>> Node(n + 1);
	vector<i64> color(n + 1, 0); //0未访问 1在栈中 2已遍历完全
	vector<i64> Path;
	vector<i64> ans;
	for(int i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
	}
	
	
}