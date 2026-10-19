#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

vector<int> topo_sort(vector<vector<int>> &Node, vector<int>& in_deg) {
	vector<int> res;
	queue<int> q;
	for(int i = 1; i < Node.size(); i++) {
		if(in_deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		res.push_back(cur);
		for(auto &i:Node[cur]) {
			if(--in_deg[i] == 0) {
				q.push(i);
			}
		}
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> Node(n + 1);
	vector<int> in_deg(n + 1, 0);
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		in_deg[v]++;
	}
	vector<int> topo = topo_sort(Node, in_deg);
	vector<int> dis(n + 1, 1);
	for(auto &i:topo) {
		for(auto &j:Node[i]) {
			dis[j] = max(dis[j], dis[i] + 1);
		}
	}


}