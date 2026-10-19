# 2-SAT

> 所属分类: 图论 › 连通性问题(Tarjan 应用)
> 复杂度: O(n + m)
> 备注: 2026-10-18 初稿, 待你核对

## 适用问题
- 布尔变量约束的可行解判定: 条件形如 (x_i=a) ∨ (x_j=b)(a,b ∈ {0,1})
- 对应题目: P4782 【模板】2-SAT 问题、CF1971H ±1(已做)

## 建图
- 每个变量 x_i 拆成两个点(本项目约定): 点 i = x_i 取 0, 点 i+n = x_i 取 1
- 条件 (x_i=a) ∨ (x_j=b) 转成两条蕴含边: ¬(x_i=a) → (x_j=b)、¬(x_j=b) → (x_i=a)(「至少一个成立」等价于「其中一个不成立则另一个必须成立」)
- 代码读入 (i,a,j,b) 后: x = x_i 取 a 的点(a=1 取 i+n, 否则取 i), nx = x 的反点(i 与 i+n 互换); y/ny 同理; 加边 nx → y、ny → x
- 建好图后跑一遍 Tarjan 求 SCC(模板见下)

## 模板(Tarjan)
```cpp
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
i64 n, m;
vector<vector<i64>> Node;
vector<i64> dfn, low, root, scc;
vector<bool> instk;
stack<i64> S;
i64 tim = 0, cnt = 0;

void tarjan(i64 u) {
	dfn[u] = low[u] = ++ tim;
	S.push(u);
	instk[u] = 1;
	for(auto &v:Node[u]) {
		if(dfn[v] == 0) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(instk[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(dfn[u] == low[u]) {
		cnt++;
		while (1) {
			i64 v = S.top(); S.pop();
			scc[v] = cnt;
			instk[v] = 0;
			root[v] = u;
			if(v == u) break;
		}
	}

}

void _2SAT() {
	cin >> n >> m;
	Node.resize(2 * n + 1); // 0 到 n - 1 是0 n到2n是1
	scc.assign(2 * n + 1, 0);
	dfn.assign(2 * n + 1, 0);
	low.assign(2 * n + 1, 0);
	root.assign(2 * n + 1, 0);
	instk.assign(2 * n + 1, 0);

	for(int k = 0; k < m; k++) {
		i64 i, a, j, b;
		cin >> i >> a >> j >> b;
		i64 x = i, y = j, nx = x + n, ny = y + n;
		if(a == 1) {x = i + n; nx = i;}
		if(b == 1) {y = j + n; ny = j;}
		Node[nx].push_back(y);
		Node[ny].push_back(x); 
	}
	
	for(int i = 0; i <= 2 * n; i++) {
		if(dfn[i] == 0) {
			tarjan(i);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if(scc[i] == scc[i + n]) {cout << "IMPOSSIBLE"; return;}
	}
	cout << "POSSIBLE" << endl;
	for(int i = 1; i <= n; i++) {
		if(scc[i] > scc[i + n]) cout << 1 << ' ';
		else cout << 0 << ' ';
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	_2SAT();


}
```

注: 模板内 `Node.resize(2 * n + 1); // 0 到 n - 1 是0 n到2n是1` 这行注释按 0-based 描述, 实际本板子按 1-based 使用(1..n / n+1..2n)。

## 判定与取值
- 若存在 i 使 scc[i] == scc[i+n](x_i 的两种取值点在同一 SCC, 矛盾): 无解, 输出 IMPOSSIBLE
- 否则有解: scc[i] > scc[i+n] → x_i = 1, 否则 x_i = 0(与 Tarjan 出栈顺序有关, 直接用本板子即可)
