#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 M, N, X;
i64 ans = 1e18;
vector<vector<i64>> book;
vector<i64> cost;
void dfs(i64 cur, i64 sum, vector<i64> &path) {
	if(cur == N + 1) {
		for(int i = 1; i <= M; i++) {
			if(path[i] < X) return;
		}
		ans = min(ans, sum);
		return;
	}

	dfs(cur + 1, sum, path);
	sum += cost[cur];
		for(int j = 1; j <= M; j++) path[j] += book[cur][j];
	dfs(cur + 1, sum, path);
		for(int j = 1; j <= M; j++) path[j] -= book[cur][j];

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> X;
	
	book.resize(N + 1, vector<i64>(M + 1));
	cost.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		for (int j = 1; j <= M; j++) cin >> book[i][j];
	}
	vector<i64> path(M + 1, 0);
	dfs(1, 0, path);
	if(ans == 1e18) cout << -1;
	else
	cout << ans;
}