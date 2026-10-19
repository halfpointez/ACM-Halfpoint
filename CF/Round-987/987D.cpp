#include <bits/stdc++.h>

using i64 = long long;
const i64 INF = 1e18;
#define endl '\n';
using namespace std;

void h_BFS(i64 n, vector<vector<i64>> &Node, vector<vector<i64>> &Good, deque<i64> &q, i64 good_now) {
	vector<bool> vis(n + 1, 0);
	vector<i64> dis(n + 1, INF);
	for(auto &i:q) {
		vis[i] = 1;
		dis[i] = 0;
	}
	
	while (!q.empty()) {
		i64 cur = q.front();
		q.pop_front();
		for(auto &i:Node[cur]) {
			if(vis[i]) continue;
			vis[i] = 1;
			dis[i] = dis[cur] + 1;
			q.push_back(i);
		}
	}

	for(int i = 1; i <= n; i++) {
		Good[i].push_back(dis[i]);
	}
	
}

int main() {
	i64 n, m, k, s;
	cin >> n >> m >> k >> s;
	vector<i64> a(n + 1);
	vector<vector<i64>> Node(n + 1);
	vector<vector<i64>> Good(n + 1);
	vector<deque<i64>> q(k + 1);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		q[a[i]].push_back(i);
	}

	for(int i =1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}

	for(int i = 1; i <= k; i++) {
		h_BFS(n ,Node, Good, q[i], i);
	}

	for(int i = 1; i <= n; i++) {
		sort(Good[i].begin(), Good[i].end());
		i64 ans = 0 ;
		for(int j = 0; j < s; j++) {
			ans += Good[i][j];
		}
		cout << ans << ' ';
	}

	
	
}