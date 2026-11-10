#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 n, r;
vector<i64> path;
void dfs(i64 s) {
	if(path.size() == r) {
		for(auto &i:path) {
			cout << setw(3) << i;
		}
		cout << endl;
		return;
	}
	for(int i = s; i <= n; i++) {
		path.push_back(i);
		dfs(i + 1);
		path.pop_back();
	}
}

int main() {
	cin >> n >> r;
	dfs(1);
}