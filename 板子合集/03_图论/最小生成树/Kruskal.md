# Kruskal

> 所属分类: 图论 › 最小生成树
> 复杂度: O(m log m), 适合稀疏图

## 适用问题
- 稀疏图最小生成树(MST)
- 判断图是否连通

#### 用法
在**稀疏图**中更优，通过将所有边按权值排序，结合并查集逐步合并连通分量，每次选择连接两个不同连通分量的最小边。时间复杂度 $\mathcal{O}(m\log m)$（主要为边排序的时间）。

#### 实现步骤
1. 定义边的结构体，包含起点、终点、权值
2. 将所有边按权值从小到大排序
3. 初始化并查集，每个结点独立成一个集合
4. 遍历排序后的边，若边的两个端点不在同一连通分量，则合并它们，并累加该边权值到总权值
5. 当合并次数达到 `n-1` 时（已形成生成树），提前退出

#### 完整模板
```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
vector<int> P;

int Find(int x) {
    if (P[x] != x) P[x] = Find(P[x]);
    return P[x];
}

i64 kruskal(int n) {
    sort(edges.begin(), edges.end());
    P.resize(n + 1);
    for (int i = 1; i <= n; i++) P[i] = i;
    i64 total = 0;
    int cnt = 0;
    for (auto& e : edges) {
        int rootu = Find(e.u);
        int rootv = Find(e.v);
        if (rootu != rootv) {
            P[rootu] = rootv;
            total += e.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return cnt == n - 1 ? total : -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    i64 ans = kruskal(n);
    if (ans == -1) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}
```
