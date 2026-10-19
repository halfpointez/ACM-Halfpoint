# BFS

> 所属分类: 图论 › 最短路 › 无权或0-1边权最短路 | 图论 › 图的遍历
> 复杂度: O(n + m)

## 适用问题
- 无权图单源最短路(首次到达即最短路)
- 层序遍历、连通块
- 多源版本见 多源BFS

#### 用法
用于无权图最短路、拓扑排序、层序遍历，按层次逐层扩展，首次到达即为最短路。

#### 完整模板
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> vis;
vector<int> dis;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
```
