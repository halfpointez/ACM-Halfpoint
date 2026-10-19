#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 n, m;
vector<vector<i64>> Node;
vector<i64> color;

bool isbipartitle(i64 u) {
	queue<i64> q;
	q.push(u);
	color[u] = 1;
	while(!q.empty()) {
		i64 cur = q.front();
		q.pop();
		for(auto &v:Node[cur]) {
			if(color[v] == -1) {
				color[v] = (color[cur] ^ 1LL);
			} else {
				if(color[v] != (color[cur] ^ 1LL) ) return 0;
			}
		}
	}
	return 1;
}

int main() {
	
	cin >> n >> m;
	Node.resize(n + 1);
	color.assign(n + 1, -1);
	for(i64 i = 1; i <= m; i++) {
		i64 u, v;
		cin >> u >> v;
		Node[u].push_back(v);
		Node[v].push_back(u);
	}	
 
	if(isbipartitle(1)) cout << "Yes" << endl;
	else cout << "No" << endl;

}