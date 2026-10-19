# LCA(最近公共祖先)

> 所属分类: 图论 › 树上问题
> 复杂度: 树链剖分 预处理 O(n)/查询 O(log n);倍增 预处理 O(n log n)/查询 O(log n)

## 适用问题
- 树上两点的最近公共祖先
- 树上两点距离: dist(u,v) = dep[u] + dep[v] - 2*dep[lca]

### 2.5.1 树链剖分
#### 用法
预处理O(n)，查询O(logn)，通过重链剖分将树划分为若干重链，快速跳转到LCA。

#### 实现步骤
1. 第一个DFS（dfs1）：处理父结点father、深度deepth、子树大小size、重子结点son
2. 第二个DFS（dfs2）：创建链顶top，重子结点的链顶为父结点的链顶，轻子结点的链顶为自己
3. 寻找LCA：
   - 若二者不在同一个重链上，让链顶深度大的点跳转到他链顶的父结点
   - 直到二者在同一个重链上，深度更小的点为LCA


#### 完整模板
```cpp
vector<vector<int>> G;
vector<int> fa, dep, siz, son, top;

void dfs1(int u, int f) {
  fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1;
  for (auto v : G[u]) {
    if (v == f) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}

void dfs2(int u, int f) {
    if (son[f] == u)
        top[u] = top[f];
    else
        top[u] = u;
    for (int v : G[u]) {
        if (v != f)
            dfs2(v, u);
    }
}

int LCA(int a, int b) {
    while(top[a] != top[b]) {
        if (dep[top[a]] > dep[top[b]]) a = fa[top[a]];
        else b = fa[top[b]];
    }
    return dep[a] <= dep[b] ? a : b;
}
```

### 2.5.2 倍增
#### 用法
预处理O(nlogn)，查询O(logn)，利用二进制思想，通过倍增表快速跳转到祖先结点。

#### 实现步骤
1. DFS：处理父亲函数fa[0][]（2^0 = 1）和深度dep
2. 倍增表初始化：第2^k祖先是第2^(k-1)祖先的第2^(k-1)祖先
3. LCA函数：
   - 先将二者跳到同一深度
   - 若相同则直接返回
   - 否则从2^k到2^0尝试跳转，直到找到LCA

#### 完整模板
```cpp
vector<vector<int>> Edge;
vector<vector<int>> fa;
vector<int> dep;
int n;

void dfs(int u, int f) {
    fa[0][u] = f;
    dep[u] = dep[f] + 1;
    for(auto &i:Edge[u]) {
        if(i != f) dfs(i, u);
    }
}

void init() {
    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= n; j++) {
            fa[i][j] = fa[i - 1][fa[i - 1][j]];   
        }
    }
}

int LCA(int a, int b) {
    if(dep[a] < dep[b]) swap(a, b);
    for(int i = 20; i >= 0; i--) {
        if(dep[fa[i][a]] >= dep[b]) a = fa[i][a];
    }
    if(a == b) return a;
    for(int i = 20; i >= 0; i--) {
        if(fa[i][a] != fa[i][b]) {
            a = fa[i][a];
            b = fa[i][b];
        }
    }
    return fa[0][a];
}
```
