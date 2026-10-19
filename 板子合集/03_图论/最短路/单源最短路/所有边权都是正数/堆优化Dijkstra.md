# 堆优化Dijkstra

> 所属分类: 图论 › 最短路 › 单源最短路 › 所有边权都是正数
> 复杂度: O(m log n), 适合稀疏图

## 适用问题
- 非负权图的单源最短路
- 多源最短路(超级源点技巧, 见例题)

## 完整模板

#### 用法
求解非负权图单源最短路，时间复杂度 $\mathcal{O}(m \log n)$。

#### 实现步骤
1. `dist[s] = 0`，其余为 INF
2. 小顶堆存 `(距离, 结点)`，起点入堆
3. 每次取出堆顶，跳过已确定的点，否则标记并松弛邻接点
4. 堆空即得起点到各点的最短路

#### 完整模板
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, m, s;
vector<bool> vis;
int main() {
	cin >> n >> m >> s;
	vis.resize(n + 1, 0);
	vector<vector<pair<int, int>>> E(n + 1);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u].push_back({w, v});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	vector<int> dis(n + 1, 1e9 + 5);
	dis[s] = 0;
	pq.push({0,s});

	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto [w, v]:E[u]) {
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << dis[i] << ' ';
	}
	
}
```

## 例题(超级源点技巧)

值得注意的是, 可以将点权转换为一个点, 每个点都指向这个点0, 路径权就为点权。(作者原话)

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1e18;
#define endl '\n'
int main() {
	i64 n, m;
	cin >> n >> m;
	vector<vector<pair<i64, i64>>> Node(n + 1);
	for(int i = 1; i <= m; i++) {
		i64 u, v, w;
		cin >> u >> v >> w;
		Node[u].push_back({2 * w, v});
		Node[v].push_back({2 * w, u});
	}
	for(int i = 1; i <= n; i++) {
		i64 w; cin >> w;
		Node[0].push_back({w, i});
		Node[i].push_back({w, 0});
	}

	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>> pq;
	pq.push({0, 0});
	vector<bool> vis(n + 1, 0);
	vector<i64> dis(n + 1, INF);
	dis[0] = 0;
	while (!pq.empty()) {
		auto[w, cur] = pq.top();
		pq.pop(); //修复: 原代码漏此行 -> 死循环
		if(vis[cur]) {continue;}
		vis[cur] = 1;
		for(auto [len, u]:Node[cur]) {
			if(dis[cur] + len < dis[u]) dis[u] = dis[cur] + len; //修复: 原用旧距离w
			pq.push({dis[u], u});
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << dis[i] << ' ';
	}
	return 0;
}
```

## 注意
- 稠密图用朴素 Dijkstra O(n^2);有负权边不能用 Dijkstra
