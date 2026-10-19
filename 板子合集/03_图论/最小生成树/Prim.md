# Prim

> 所属分类: 图论 › 最小生成树
> 复杂度: O(m log n), 适合稠密图

## 适用问题
- 稠密图最小生成树(MST)
- 判断图是否连通(cnt == n 才成树)

#### 用法
在**稠密图**中求解最小生成树，从任意结点出发，通过维护当前连通块到未连通结点的最小边权，逐步扩展连通块。时间复杂度 $\mathcal{O}(m\log n)$（优先队列实现）。

#### 实现步骤
1. 初始化距离数组 `dist[]` 为无穷大，选择任意起点（如结点1），将其距离设为0
2. 使用优先队列（小顶堆）存储 `(距离, 结点)`，将起点入队
3. 用 `vis[]` 数组维护已加入最小生成树的结点
4. 每次取出队首距离最小的未访问结点，标记为已访问，累加其距离到总权值
5. 遍历该结点的所有邻接点，若邻接点未访问且当前边权小于其 `dist`，更新 `dist` 并入队

#### 完整模板
```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int INF = 0x3f3f3f3f;

vector<vector<pair<int, int>>> G;
vector<int> dist;
vector<bool> vis;

i64 prim(int n, int start = 1) {
    dist.assign(n + 1, INF);
    vis.assign(n + 1, false);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    i64 total = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        total += d;
        cnt++;
        for (auto [v, w] : G[u]) {
            if (!vis[v] && w < dist[v]) {
                dist[v] = w;
                pq.emplace(dist[v], v);
            }
        }
    }
    return cnt == n ? total : -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    G.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    i64 ans = prim(n);
    if (ans == -1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}
```
