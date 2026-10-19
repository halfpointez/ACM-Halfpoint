有向无环图 且不管正负 可以使用拓扑序 + dp求最短路
但是对于有环图 我们无法确认当前的拓扑序 就只能用最笨的方法 对每个边都进行遍历n - 1次数 
原因是第 k 轮后，可以确定所有“最多 k 条边”的最短路径。

比如存在下列的图 a -> b -> c -> d 如果最坏的情况 我们从c-d b-c a-b的顺序遍历 每次都只能获得长度为次数的边的松弛更新 所以最坏情况需要n - 1的次数
bellman-ford本质就是一个不确定拓扑序顺序的暴力遍历每条边 和 拓扑序 + dp求最短路类似

bellma-ford 记录两个数组 一个是距离数组 起点距离为0 其他为正无穷 还有前驱节点数组 用来回溯路径

每一轮都要遍历全部 E 条边。

因此总操作次数为 (V - 1) × E，即 O(V·E)。

补充说明：

如果图是稠密图，E 接近 V²，那么复杂度约为 O(V³)。

如果图是稀疏图，E 接近 V，那么复杂度约为 O(V²)。

对于beelman-ford 存在以下几种情况
1.提前发现距离数组已经不变化了 就可以直接停止了
2.对于最后一次还在变 再跑一次 如果不变了 就可以认为有解 如果还在变小 就认为存在负权的环 一直在这个环上跑能一直变小 这样是认为无解的

下面是板子代码
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