#include <bits/stdc++.h>
using i64 = long long;
using namespace std;
#define endl '\n'

int n;
vector<vector<int>> Node;
vector<int> dis;
int far;
int MAX;

void dfs(int cur) {
	if(dis[cur] > MAX) {
		MAX = dis[cur];
		far = cur;
	}
	for(auto &i : Node[cur]) {
		if(dis[i] != -1) continue;
		dis[i] = dis[cur] + 1;
		dfs(i);           
	}
}

void run(int start) {
	dis.assign(n + 1, -1);
	dis[start] = 0;
	MAX = -1;
	dfs(start);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	Node.assign(n + 1, {});
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		Node[a].push_back(b);
		Node[b].push_back(a);
	}

	run(1);          
	int p = far;
	run(p);         
	cout << MAX << endl;
}