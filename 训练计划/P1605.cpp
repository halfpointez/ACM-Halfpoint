#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<pair<i64, i64>> path;
i64 N, M, T, SX, SY, FX, FY;
vector<vector<bool>> vis;
vector<vector<bool>> barrier;
i64 ans = 0;
i64 dx[] = {-1, 0, 0, 1};
i64 dy[] = {0, 1, -1, 0};
void dfs(i64 curx, i64 cury) {
	vis[curx][cury] = 1;
	if(curx == FX && cury == FY) {
		ans++;	
	} 

	for(int i = 0; i < 4; i++) {
		i64 X = curx + dx[i], Y = cury + dy[i];
		if(X < 1 || X > N || Y < 1 || Y > M || vis[X][Y] == 1) continue;
		if (barrier[X][Y]) continue;
		else dfs(X, Y);
	}
	vis[curx][cury] = 0;

}

int main() {
	cin >> N >> M >> T;
	cin >> SX >> SY >> FX >> FY;
	barrier.resize(N + 1, vector<bool>(M + 1));
	vis.resize(N + 1, vector<bool>(M + 1, 0));
	for(int i = 1; i <= T; i++) {
		i64 BX, BY; cin >> BX >> BY;
		barrier[BX][BY] = 1;
	}
	dfs(SX, SY);
	cout << ans;	

}