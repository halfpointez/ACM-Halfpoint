# Tarjan强连通分量

> 所属分类: 图论 › 连通性问题
> 复杂度: O(V + E)

## 适用问题
- 求有向图的强连通分量
- 缩点(把每个 SCC 缩成一个点)
- 缩点后在 DAG 上做 DP(如点权最长路)
## 原理

tarjan算法 能找出图中的最大联通量 从而帮助缩点 时间复杂度为O(n + m)

对于一个图 是否联通 其实就是看这个结点是否能从一个结点到另一个结点	
对于一个点 如果他的下一个结点能到达之前的结点 那它自身也可以到达 如果通过回溯边他能到达之前的结点 那它以及能到达他的边也能到达他能到达的结点
这个思想非常递归
所以只需要维护dfn 和 low 即自己的dfs序 以及自己能到达的dfn序最小的前结点

对于每次dfs 遍历每个结点 如果当前的结点是不在dfs栈中的 就认为是一个新的结点 要先对当前结点递归 因为他有可能是能找到更优路径的 更新low[u] = min(low[u], low[v])

若当前节点已经在栈中了 那么此时遍历到的节点一定是前面的节点 此时更新low[u] = min(low[u], dfn[v]) 这里是为了避免割点的时候错误 让点错误拿到子树的信息 一定要用dfn

在无向割点边中 在递归结束后 如果发现
1.low[u] >= dfn[v] 那就是说 不经过点v 点u没有办法到达之前的节点 v是一个割点
2.low[u] > dfn[v] 也就是说 不经过边uv 点u没办法到达之前节点 uv是一个割边

#include <bits/stdc++.h>
using i64 = long long;
const i64 INF = 1e18;
#define endl '\n'
using namespace std;
i64 n, m;
i64 tim = 0;
i64 cnt = 0;
vector<i64> a, dfn, low, root, scc, scc_w;
vector<bool> instk;
vector<vector<i64>> Node;
stack<i64> S;
void tarjan(i64 u) {
	dfn[u] = low[u] = ++tim;//对每个刚进入的结点初始化并且入栈
	S.push(u);
	instk[u] = 1;
	for(auto &v:Node[u]) {
		if(dfn[v] == 0) {//如果dfs到的结点没有入栈 入栈 
			tarjan(v);
			low[u] = min(low[u], low[v]);//自己的子结点是否有回溯路径更短
		} else if(instk[v]){
			low[u] = min(low[u], dfn[v]);//如果instk == 1 此时的路径是回溯结点 比对下是否更短 low的定义是自己的一条回溯结点 所以不要用low
		}
	}

	if(dfn[u] == low[u]) {
		cnt++;
		i64 sum = 0;
    	while (true) {	
        	i64 v = S.top(); S.pop();
			scc[v] = cnt;
			sum += a[v];
        	instk[v] = false;
        	root[v] = u;
        	if (v == u) break;
    	}
		scc_w.push_back(sum);
		
	}//出栈 给每个结点缩点绑定根 并且统计总点权 标号从1开始
}

int main() {
	
	cin >> n >> m;
	a.assign(n + 1, 0);
	scc.assign(n + 1, 0);
	Node.resize(n + 1);
	dfn.assign(n + 1, 0);
	low.assign(n + 1, 0);
	root.assign(n + 1, 0);
	instk.assign(n + 1, 0);
	for(i64 i = 1; i <= n; i++) cin >> a[i];
	for(i64 i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
	}
	scc_w.push_back(0); //入一个空结点 从而从1开始
	// 关键：对每个未访问节点运行 Tarjan 避免森林的存在
    for(i64 i = 1; i <= n; i++) {
        if (dfn[i] == 0) {
            tarjan(i);
        }
    }
	vector<vector<i64>> dag(cnt + 1);
	for (i64 u = 1; u <= n; u++) {
    	for (auto v : Node[u]) {
        	if (scc[u] != scc[v]) {
            	dag[scc[u]].push_back(scc[v]);
        	}
    	}
	}


	vector<i64> dp(cnt + 1, 0);
    i64 ans = 0;

    for (i64 i = cnt; i >= 1; i--) {
        if (dp[i] == 0) dp[i] = scc_w[i];
        ans = max(ans, dp[i]);
        for (auto v : dag[i]) {
            dp[v] = max(dp[v], dp[i] + scc_w[v]);
        }
    }

    cout << ans << endl;
    return 0;



}
