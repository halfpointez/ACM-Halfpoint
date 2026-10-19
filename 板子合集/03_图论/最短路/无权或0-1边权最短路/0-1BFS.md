# 0-1 BFS

> 所属分类: 图论 › 最短路 › 无权或0-1边权最短路
> 复杂度: O(n + m)

## 适用问题
- 边权值可能有也可能没有(一般为 0 或 1)的最短路问题

### 适用范围
边权值为可能有，也可能没有（由于 BFS 适用于权值为 1 的图，所以一般权值是 0 或 1），或者能够转化为这种边权值的最短路问题．

例如在走迷宫问题中，你可以花 1 个金币走 5 步，也可以不花金币走 1 步，这就可以用 0-1 BFS 解决．

### 实现
一般情况下，我们把没有权值的边扩展到的点放到队首，有权值的边扩展到的点放到队尾．这样即可保证像普通 BFS 一样整个队列队首到队尾权值单调不下降．

### 完整模板
```cpp
void bfs01(int s) {
	deque<int> dq;
	vector<int> dis(n + 1, INF);
	dis[s] = 0;
	dq.push_front(s);
	while (!dq.empty()) {
		int u = dq.front();
		dq.pop_front();
		for (auto [v, w] : E[u]) { // w 为 0 或 1
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				if (w == 0) dq.push_front(v); // 无权边放队首
				else dq.push_back(v);         // 有权边放队尾
			}
		}
	}
}
```
