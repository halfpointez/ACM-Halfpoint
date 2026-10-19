#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 n, m, cnt = 1;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0}; 
void test1(vector<vector<char>> &a) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
}

void test2(vector<vector<int>> &id) {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cout << id[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void refresh(vector<array<i64, 4>> &range, i64 x, i64 y) {
	auto &[up, down, left, right] = range[cnt];

	up = max(x, up);
	down = min(down, x);
	left = min(left, y);
	right = max(right, y);

}

void bfs(vector<vector<char>> &a, vector<vector<bool>> &vis, vector<vector<int>> &id, i64 i, i64 j, vector<i64> &SUM, vector<array<i64, 4>> &range) {
	queue<pair<int, int>> q;
	q.push({i, j});
	i64 sum = 0;
	range.push_back({0, 0, 0, 0});
	auto &[up, down, left, right] = range[cnt];
	up = 0; down = 1e9, left = 1e9, right = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();

		if(vis[x][y]) continue;

		refresh(range, x, y);

		sum++;
		vis[x][y] = 1;
		id[x][y] = cnt;


		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx <= n && nx >= 1 && ny <= m && ny >= 1 && a[nx][ny] == '#') {
				if(vis[nx][ny]) continue;
				q.push({nx, ny});
			}
		}
	}
	
	up = min(up + 1, n);
	down = max(1LL, down - 1);
	left = max(1LL, left - 1);
	right = min(right + 1, m);

	SUM.push_back(sum);

}

bool legal(int x, int y, vector<vector<int>> &id) {
	if(x >= 1 && x <= n && y >= 1 && y <= m && id[x][y] != -1) return 1;
	return 0;
}

void solve() {
	cnt = 1;

	cin >> n >> m;
	vector<vector<char>> a(n + 1, vector<char>(m + 1));
	vector<vector<bool>> vis(n + 1, vector<bool>(m + 1, 0));
	vector<vector<int>> id(n + 1, vector<int>(m + 1, -1));
	vector<array<i64, 4>> range;
	range.push_back({0, 0, 0, 0});
	vector<i64> SUM(1, 0);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(vis[i][j] || a[i][j] == '.') continue;
			bfs(a, vis, id, i, j, SUM, range);
			cnt++;
		}
	}
	

	vector<i64> diff_row(n + 3, 0);
	vector<i64> diff_col(m + 3, 0);
	vector<i64> pre_row(n + 3, 0);
	vector<i64> pre_col(m + 3, 0);


	vector<int> row_dot(n + 1, 0), col_dot(m + 1, 0);
	for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
        	if (a[i][j] == '.') {
            	row_dot[i]++;
            	col_dot[j]++;
        	}
    	}
	}

	for(int i = 1; i < range.size() ; i++) {
		auto &[up, down, left, right] = range[i];
		diff_row[down] += SUM[i];
		diff_row[up + 1] -= SUM[i];
	}

	for(int i = 1; i < range.size(); i++) {
		auto &[up, down, left, right] = range[i];
		diff_col[left] += SUM[i];
		diff_col[right + 1] -= SUM[i];
	}

	for(int i = 1; i <= n; i++) {
		pre_row[i] = pre_row[i - 1] + diff_row[i]; 
	}

	for(int i = 1; i <= m; i++) {
		pre_col[i] = pre_col[i - 1] + diff_col[i]; 
	}

	vector<vector<i64>> sq(n + 5, vector<i64>(m + 5, 0));	
	vector<vector<i64>> pre_sum(n + 5, vector<i64>(m + 5, 0));

	for(int i = 1; i < range.size(); i++) {
		auto &[up, down, left, right] = range[i];
		sq[down][left] += SUM[i];
		sq[down][right + 1] -= SUM[i];
		sq[up + 1][left] -= SUM[i];
		sq[up + 1][right + 1] += SUM[i];
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			pre_sum[i][j] = pre_sum[i - 1][j] + pre_sum[i][j - 1] + sq[i][j] - pre_sum[i - 1][j - 1]; 
		}
	}

	i64 ans = 0;
for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= m; c++) {
        // 新增的 # 格子数：第 r 行 + 第 c 列 - 交叉点重复算的一次
        i64 add = row_dot[r] + col_dot[c] - (a[r][c] == '.' ? 1 : 0);

        // 最终连通块大小 = 新增格子 + 通过行连上的原连通块 + 通过列连上的 - 行列都连上的（去重）
        i64 cur = add + pre_row[r] + pre_col[c] - pre_sum[r][c];

        ans = max(ans, cur);
    }
}
cout << ans << endl;

}

int main() {
	i64 t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}