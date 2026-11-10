#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 n;
vector<i64> path;
vector<bool> used;
void dfs() {
	if(path.size() == n) {
		for(auto &i:path) cout << setw(5) << i;
		cout << endl;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(used[i]) continue;
		used[i] = 1;
		path.push_back(i);
		dfs();
		used[i] = 0;
		path.pop_back();
	}
}



int main() {
	cin >> n;
	used.resize(n + 1, 0);
	dfs();
}