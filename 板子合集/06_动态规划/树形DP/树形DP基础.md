# 树形DP基础

> 所属分类: 动态规划 › 树形DP
> 复杂度: O(n)(基础选/不选型)
> 备注: 2026-10-18 初稿, 待你核对

## 适用问题
- 树上「选 / 不选」决策的最优化问题; 例题: P1352 没有上司的舞会、P2016 战略游戏、P1122 最大子树和

## 基础模型(选/不选型)

- 状态: `dp[u][0]` / `dp[u][1]` 分别表示「不选 / 选」结点 u 时, 以 u 为根的子树内的最优值
- 转移要点: 约束只发生在父子一条边上, 合并儿子时按 u 选不选分两类:
  - 不选 u: 儿子可选可不选 — `dp[u][0] = Σ max(dp[v][0], dp[v][1])`
  - 选 u: 以没有上司的舞会为例, 上司出席则下属不能出席 — `dp[u][1] = happy[u] + Σ dp[v][0]`
- 合并顺序: 后序 `dfs`, 先递归儿子再拿儿子的 `dp` 更新 u; 无父结点的点即根(代码用 `has_p` 找根), 答案取 `max(dp[root][0], dp[root][1])`

下面收录 P1352 没有上司的舞会的原稿: 结点是员工、`happy[u]` 是员工 u 的快乐值, 父子边表示直接上下级关系; 目标是选出互不冲突的点集使快乐值之和最大, 输出该最大值。

```cpp
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<i64> happy;
vector<vector<i64>> Node; 
vector<bool> has_p;
vector<vector<i64>> dp;

void dfs(i64 u, i64 p) {
	dp[u][1] = happy[u];
	for(auto v:Node[u]) {
		if(v == p) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][1], dp[v][0]); 
		dp[u][1] += dp[v][0];
	}
	
}

void solve() {
	int n;
	cin >> n;
	happy.resize(n + 1);
	Node.resize(n + 1);
	has_p.resize(n + 1, 0);
	dp.resize(n + 1, vector<i64>(2, 0)); //1选该结点 0不选该结点

	for(int i = 1; i <= n; i++) {
		cin >> happy[i];
	}

	for(int i = 1; i <= n - 1; i++) {
		i64 l, k;
		cin >> l >> k;
		Node[l].push_back(k);
		Node[k].push_back(l);
		has_p[l] = 1;
	}




	for(int i = 1; i <= n; i++) {
		if(!has_p[i]) {
			dfs(i, -1);
			cout << max(dp[i][0], dp[i][1]) << endl;
			break;
		}
	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();		
}
```

## 变式

同一个按子树合并的框架, 换转移就能套到其它树上最优化问题; 下面片段只保留转移本体(省略 `dfs` 框架、父结点判断与初始化)。

### 最小点覆盖(P2016 战略游戏)

每条边至少要有一个端点被选中, 求最少选中点数: 不选 u 时每个儿子必须选(否则边 (u, v) 没人覆盖), 选 u 时儿子选不选都行。

- `dp[u][0] = Σ dp[v][1]`
- `dp[u][1] = 1 + Σ min(dp[v][0], dp[v][1])`

```cpp
dp[u][1] += 1;                           // 选 u 自身计 1
for (auto &v : Node[u]) {
    dp[u][0] += dp[v][1];                // 不选 u: 儿子必须选
    dp[u][1] += min(dp[v][0], dp[v][1]); // 选 u: 儿子选不选都行
}
```

### 最大子树和(P1122)

求带权树上连通块的最大权值和: `dp[u]` 表示强制包含 u、只在 u 子树内取点的最大和; 儿子贡献为负就不取, 等价于只加正的 `dp[v]`。

- `dp[u] = w[u] + Σ max(0, dp[v])`(w 是点权, 代码中为 `beauty[u]`)

```cpp
i64 sum = beauty[u];
for (auto v : Node[u])
    if (dp[v] >= 0) sum += dp[v];        // 等价于 sum += max(0, dp[v])
dp[u] = sum;
```

答案对所有 `dp[i]` 取最大值(最大连通块不一定以根为最高点)。

同理, 子树大小、深度分布一类的计数 DP(如 161D)可设 `dp[u][d]` 表示「u 子树内与 u 距离为 d」的信息, 同样按子树逐个合并。
