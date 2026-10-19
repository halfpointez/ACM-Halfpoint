三色dfs本质是tarjan的一个简写方式 对于有环的有向图 能快速的解决相关的简单问题 时间复杂度为o(n)

1.快速的判断图上是否有环
2.给出最近找到的环的路径
3.对每个点进行判断 判断其路径是否是安全的 即是否怎么走都不会走到环中

逻辑如下 在dfs的递归中 定义如下三种状态
0.该节点从未被dfs访问过
1.该节点被访问过并且在栈中 意味着该结点的子结点还在被访问中 不能下定论
2.该节点被访问且已经不在栈中 意味该结点的子结点已经全部访问完了 并且没有环的存在

如果想要记录环的路径 只需要定义一个path数组 记录当前的路径 当遇到环时 回溯path 到上一个相同的结点即可 如 path 1->2->3->2 从2回溯到上一个2就行了

需要判断是否安全 需要保证遍历了所有的结点 不要提前结束就行了 

板
1.判断有没有环
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
bool _3c_dfs(vector<vector<i64>> &Node, vector<i64> &color, i64 cur) {
	if(color[cur] == 0) color[cur] = 1;
	for(auto &i:Node[cur]) {
		i64 jud = 0;
		if(color[i] == 1) return 1;
		else if(color[i] == 0) {
			if(_3c_dfs(Node, color, i)) return 1;
		}
	}
	color[cur] = 2;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 n, m;
	cin >> n >> m;
	vector<vector<i64>> Node(n + 1);
	vector<i64> color(n + 1, 0); //0未访问 1在栈中 2已遍历完全
	for(int i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
	}
	cout << _3c_dfs(Node, color, 1) << endl;
	
}

2.判断环的同时给出路径
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<i64> get_path(vector<vector<i64>> &Node, vector<i64> &color, vector<i64> &Path, i64 node) {
	vector<i64> ans;
	for(int i = Path.size() - 1; i >= 0; i--) {
		ans.push_back(Path[i]);
		if(Path[i] == node) break;
	}
	return ans;
}

bool _3c_dfs(vector<vector<i64>> &Node, vector<i64> &color, vector<i64> &Path, i64 cur, vector<i64> &ans) {
	if(color[cur] == 0) color[cur] = 1;
	Path.push_back(cur);
	for(auto &i:Node[cur]) {
		i64 jud = 0;
		if(color[i] == 1) {
			ans = get_path(Node, color, Path, i);
			return 1;
		}
		else if(color[i] == 0) {
			if(_3c_dfs(Node, color, Path, i)) {
				return 1;
			};
		}
	}
	color[cur] = 2;
	Path.pop_back();
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 n, m;
	cin >> n >> m;
	vector<vector<i64>> Node(n + 1);
	vector<i64> color(n + 1, 0); //0未访问 1在栈中 2已遍历完全
	vector<i64> Path;
	vector<i64> ans;
	for(int i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
	}
	
	
}

3.判断安全 不提前结束的写法
bool _3c_dfs(vector<vector<i64>> &Node, vector<i64> &color, vector<i64> &Path, i64 cur, vector<i64> &ans) {
	if(color[cur] == 0) color[cur] = 1;
	bool jud = 0;
	for(auto &i:Node[cur]) {
		if(color[i] == 2) continue;
		if(color[i] == 1) {
			jud = 1;
			continue;
		}
		if(color[i] == 0) {
			if(_3c_dfs(Node, color, Path, i, ans)) jud = 1;
		}
	}
	if(jud == 1) return 1;
	color[cur] = 2;
	return 0;
}

