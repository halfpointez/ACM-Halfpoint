# 多源BFS

> 所属分类: 图论 › 最短路 › 无权或0-1边权最短路
> 复杂度: O(n + m)

## 适用问题
- 无权图中每个点到最近源点的距离(多个起点)
- 多源传染/燃烧蔓延的最短时间(每层 BFS = 一个时间单位)
- 多起点到目标的最短距离(反向多源)

## 核心思想
多源BFS
本质:
你可以想象在棋盘外有一个虚拟的“超级源点”，用权值为0的边连接所有真实源点。多源BFS就是从该超级源点出发的单源BFS，保证了所有源点处于同一“起跑线”上，公平竞争最近领地。

适用问题
. 最近距离 / 最近服务点（静态图）
这是最经典的应用。给定若干个“服务点”（源点）和若干个“居民点”，求每个居民点离它最近的服务点有多远。

典型题目：LeetCode 542. 01矩阵（求每个格子到最近0的距离）、LeetCode 1162. 地图分析（求离陆地最远的海洋，本质先求最近陆地距离）。

关键逻辑：所有源点初始距离为0，同时入队，扩散时取 dist[新] = dist[旧] + 1。

2. 多源传染 / 燃烧蔓延（动态模拟）
模拟多个感染源、火源或病毒同时向四周扩散的过程，求整个图被“占领”所需的最短时间，或每个节点被“感染”的时间戳。

典型题目：LeetCode 994. 腐烂的橘子（求所有橘子腐烂的最短分钟数）。

关键逻辑：每一层BFS代表一个时间单位，队列中所有节点同步向外扩展一层，记录层数即为时间。

3. 多起点最优路径（简化状态）
当求解从“多个可能的起点”出发，到达某个终点的最短路径时，如果终点唯一，反向思维即可：把终点当作单源，反向BFS；但若起点是一大片区域（而非离散点），多源BFS能极快求出起点集合到目标的最短距离。

4. 解决“被多个障碍物影响”的问题
在地图路径规划中，如果多个障碍物（或敌人）会周期性扩张领土，多源BFS可以预先计算出每个格子被扩张势力覆盖的“危险时间”，从而帮助主角找到一条避开所有危险源的安全路径（常用于游戏AI寻路）。

多源BFS的板子很简单 只需要在正常的BFS初始队列中 一次性加入所有的源头结点即可

## 完整模板

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = 1e18;
#define endl '\n'

// 多源BFS: 无权图, 求每个点到最近源点的距离
// sources: 所有源点; dis[i] == INF 表示不可达
void multi_source_bfs(i64 n, const vector<vector<i64>> &Node, const vector<i64> &sources, vector<i64> &dis) {
	queue<i64> q;
	dis.assign(n + 1, INF);
	for(auto &s : sources) {
		dis[s] = 0;
		q.push(s);
	}
	while (!q.empty()) {
		i64 cur = q.front();
		q.pop();
		for(auto &i : Node[cur]) {
			if(dis[i] == INF) {
				dis[i] = dis[cur] + 1;
				q.push(i);
			}
		}
	}
}
```

## 例题(CF 986A Fair, 原题解仅修 3 处 bug)

n 个点每个点一种颜色(1..k), 求每个点离它最近的 s 种颜色的距离之和。

```cpp
#include <bits/stdc++.h>
#include <iostream>
#include <queue>

using i64 = long long;
const i64 INF = 1e18;
#define endl '\n';
using namespace std;

void h_BFS(i64 n, vector<vector<i64>> &Node, vector<vector<i64>> &Good, deque<i64> &q, i64 good_now) {
	vector<bool> vis(n + 1, 0);
	vector<i64> dis(n + 1, INF);
	for(auto &i:q) {
		vis[i] = 1; //修复: 原为 0, 源点应标记已访问
		dis[i] = 0;
	}

	while (!q.empty()) {
		i64 cur = q.front();
		q.pop_front(); //修复: 原为 pop_back(), 与 front() 不一致
		for(auto &i:Node[cur]) {
			if(vis[i]) continue;
			vis[i] = 1;
			dis[i] = dis[cur] + 1;
			q.push_back(i); //修复: 原代码从不入队, BFS 不扩散
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
```

## 注意
- 边权全为 1 才能用 BFS;0-1 边权用 0-1BFS;正权用 Dijkstra
- 多源BFS 和多源djs 几乎写法一致, 思想也一致(作者原话)
