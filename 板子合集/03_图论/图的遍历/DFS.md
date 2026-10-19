# DFS

> 所属分类: 图论 › 图的遍历
> 复杂度: O(n + m)

## 适用问题
- 连通性判断、连通块
- 回溯搜索(排列/组合枚举)
- 有向图判环参见 三色DFS;拓扑序参见 拓扑排序

#### 完整模板
```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (int v : G[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}
```
