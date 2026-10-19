#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const i64 INF = (1LL << 31) - 1;//题目要求的上线 依据题目更改

bool bellman_ford(vector<vector<pair<i64, i64>>> &Node, vector<i64> &dis, vector<i64> &pre_node, int n) {
	bool stop = 0;
	for(int i = 0; i < n - 1; i++) {
		if(stop) return 0;
		stop = 1;
		for(int j = 1; j <= n; j++) {
			if (dis[j] == INF) continue;
			for(auto &i:Node[j]) {
				auto [u, w] = i;
				if(dis[j] + w < dis[u]) {
					dis[u] = dis[j] + w;
					pre_node[u] = j;
					stop = 0;
				}
			}
		}
	}

	//再进行一次测试 看看最后还变不变 还变就代表有负权环
	stop = 1;
	for(int j = 1; j <= n; j++) {
		if (dis[j] == INF) continue;
		for(auto &i:Node[j]) {
			auto [u, w] = i;
			if(dis[j] + w < dis[u]) {
				stop = 0;
			}
		}
	}
	if(!stop) {
		return 1;
	}
	return 0;
	
}

vector<i64> get_path(vector<i64> &pre_node, i64 start, i64 end) {
    vector<i64> res;
    if (end < 1 || end >= (i64)pre_node.size()) return res;

    i64 cur = end;
    while (cur != -1) {
        res.push_back(cur);
        if (cur == start) {                 // 关键：遇到 start 就停
            reverse(res.begin(), res.end());
            return res;
        }
        cur = pre_node[cur];
    }
    // 走到 -1 还没遇到 start，说明不可达
    cout << "不可达" << endl;
    return {};
}

int main() {
	int T;
	cin >> T;
	while (T--) {

		i64 n, m;
		cin >> n >> m;
		vector<vector<pair<i64, i64>>> Node(n + 1);
		vector<i64> pre_node(n + 1, -1);
		vector<i64> dis(n + 1, INF);
		dis[1] = 0;
		for(int i = 1; i <= m; i++) {
			i64 u, v, w;
			cin >> u >> v >> w;
			if(w >= 0) Node[v].push_back({u, w});
			Node[u].push_back({v, w});
			
		}
		
		if(bellman_ford(Node, dis, pre_node ,n)) {
			cout << "YES" << endl;
		} else cout << "NO" << endl;

		
	}
	

}	