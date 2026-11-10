// 树的直径有很多种类 对于不同的种类也有不同的求法

// 1.直接的 求树的直径 并且树的直径是非负权边(>=0)  
// 两次BFS/DFS 时间复杂度为o(n)

// 先对树上的任意一点u进行BFS/DFS 找到离这个点最远的v 在树的概念上 就是以一个点为根节点 找他的最深的叶节点
// 然后对找到的u/v再进行一次BFS/DFS 找到离v最远的点 这个距离就是树的直径 这非常的直觉 不需要怎么证明也能知道

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;

void bfs() {}

void dfs(i64 cur, vector<vector<i64>> &Node) {
	for(auto &i:Node[cur])
}

int main() {
	int n;
	cin >> n;
	vector<vector<i64>> Node(n + 1);
	vector<i64> dis1(n + 1, 0);
	vector<i64> dis2(n + 1, 0);
	vector<bool> vis(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}
	
}