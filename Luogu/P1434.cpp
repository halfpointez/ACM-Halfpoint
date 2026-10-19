#include <bits/stdc++.h>
using i64 = long long;
#define endl '\n'
using namespace std;
i64 dx[] = {0, 0, -1, 1};
i64 dy[] = {-1, 1, 0, 0};
int n, m;
bool in_edge(int x, int y) {
	if(x >= 1 && x <= n && y >= 1 && y <= m) {
		return 1;
	}
	return 0;
}

i64 dfs(i64 x, i64 y, vector<vector<i64>> &mp, vector<vector<i64>> &dis) {
	if(dis[x][y] != 0) return dis[x][y];
	i64 best = 1;
	for(int i = 0; i < 4; i++) {
		i64 cur_x = x + dx[i];
		i64 cur_y = y + dy[i];
		if(in_edge(cur_x, cur_y) && mp[cur_x][cur_y] < mp[x][y]) {
			best = max(best, 1 + dfs(cur_x, cur_y, mp, dis));
		}
	}
	dis[x][y] = best;
	return best;
}

int main() {

	cin >> n >> m;

	vector<vector<i64>> mp(n + 1,vector<i64>(m + 1));
	vector<vector<i64>> dis(n + 1,vector<i64>(m + 1, 0));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dfs(i, j, mp, dis));
        }
    }
	cout << ans << endl;
	return 0;


}