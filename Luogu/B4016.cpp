#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> Node;

pair<int, int> bfs(int x) { //返回最远点和距离
	vector<int> dis(n + 1, -1);
	deque<int> dq;
	int u = x;
	dq.push_back(x);
	dis[x] = 0;
	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		if (dis[cur] > dis[u]) u = cur;
		for (auto &i : Node[cur]) {
			if (dis[i] != -1) continue;
			dis[i] = dis[cur] + 1;
			dq.push_back(i);
		}
	}
	return {u, dis[u]};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	Node.assign(n + 1, {});
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}

	if (n == 1) { cout << 0 << endl; return 0; }
	
	auto [u, _] = bfs(1);
	auto [v, dis] = bfs(u);
	cout << dis << endl;
}

