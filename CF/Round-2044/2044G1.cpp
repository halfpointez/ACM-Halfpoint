	#include <bits/stdc++.h>
	using namespace std;
	using i64 = long long;
	#define endl '\n'

	i64 topo_sort(vector<i64> &In_Deg, vector<vector<i64>> &Node, queue<pair<i64, i64>> &q) {
		i64 n = Node.size() - 1;
		i64 ans = 0;
		for(int i = 1; i <= n; i++) {
			if(In_Deg[i] == 0) q.push({i, 0});
		}
		while (!q.empty()) {
			auto [u, deep] = q.front();
			ans = max(deep, ans);
			q.pop();
			for(auto &i:Node[u]) {
				In_Deg[i]--;
				if(In_Deg[i] == 0) {
					q.push({i, deep + 1});
				}
			}
		}
		if(ans == 0) return ans + 2;

		return ans + 3;
	}

	int main() {
		int t;
		cin >> t;
		while (t--) {
			int n;
			cin >> n;
			vector<i64> In_Deg(n + 1); //记录每个节点的入度
			vector<vector<i64>>	Node(n + 1); //记录每个节点
			for(int i = 1; i <= n; i++) {
				int tmp = 0;
				cin >> tmp;
				Node[i].push_back(tmp);
				In_Deg[tmp]++;
			}
			queue<pair<i64, i64>> q; //当前入度为0的节点	
			cout <<  topo_sort(In_Deg, Node, q) << endl;

		}
		
		
		
		
	}