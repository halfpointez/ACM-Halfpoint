# Floyd

> 所属分类: 图论 › 最短路 › 多源汇最短路
> 复杂度: O(n^3)

## 适用问题
- 任意两点间的最短路径
- 回溯任意两点的具体路径(前驱矩阵)

## 核心思想
对于一个图(任何的) 我们想知道任意两点之间的最短路径 有两种方法 
1.对每个点djs 这样的时间复杂度是u^2*log(e) 但是有负数或者边很多的时候很亏
2.对每个点floyd 这样时间复杂度是u ^ 3  

floyd的思想
1.对每个点创建一个邻接矩阵 其中是他们边的距离 如果是自身 边距就是0
2.建立一个相同大小的矩阵 前驱节点矩阵 记录当前a -> b 上 离b最近的节点 
3.对每个节点x进行遍历 尝试若a -> b中间走 x 即a -> x -> b 会不会更短 若会更短 就更新走这条路 更新前驱节点矩阵和邻接矩阵
4.对每个节点a -> b进行回溯 回溯到前驱节点为a为止即可

## 完整模板
```cpp
#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;
const i64 INF = 1e9;
using namespace std;
void init(const i64 &n, const i64 &m, vector<vector<i64>> &G, vector<vector<i64>> &Pre) {
	G.resize(n + 1, vector<i64>(n + 1, INF));
	Pre.resize(n + 1, vector<i64>(n + 1, -1));
	for(int i = 0; i < m; i++) {
		i64 u, v, w;
		cin >> u >> v >> w;
		G[u][v] = min(w, G[u][v]);
		G[v][u] = min(w, G[v][u]);
		Pre[u][v] = u;
		Pre[v][u] = v;
	}
	for(int i = 1; i <= n; i++) {
		G[i][i] = 0;
	}
}

void Floyd(i64 n, i64 m) { //n个点m条边
	vector<vector<i64>> G;
	vector<vector<i64>> Pre;
	init(n, m, G, Pre);
	for(int k = 1; k <= n; k++) { //k为当前尝试的前驱点
		for(int i = 1; i <= n; i++) {
			if(i == k) continue; //如果含当前点的临接矩阵 不会变化
			for(int j = 1; j <= n; j++) {
				if(j == k) continue;
				if(G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
					Pre[i][j] = Pre[k][j];
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << G[i][j] << ' ';
		}
		cout << endl;
	}
}

vector<int> getPath(int s, int t, const vector<vector<i64>>& Pre) {
    vector<int> path;
    if (Pre[s][t] == -1) { // 不连通
        return path;
    }
    
    int cur = t;
    while (cur != s) {
        path.push_back(cur);          // 把当前节点加入路径
        cur = Pre[s][cur];            
        if (cur == -1) return {};     // 安全保护
    }
    path.push_back(s);                // 最后加入起点
    reverse(path.begin(), path.end()); // 反转得到正向路径
    return path;
}

int main() {
	int n, m;
	cin >> n >> m;
	Floyd(n, m);
	
}
```
