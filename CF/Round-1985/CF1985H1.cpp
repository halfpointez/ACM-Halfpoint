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

void bfs(vector<vector<char>> &a, vector<vector<bool>> &vis, vector<vector<int>> &id, i64 i, i64 j, vector<i64> &SUM) {
	queue<pair<int, int>> q;
	q.push({i, j});
	i64 sum = 0;
	while (!q.empty()) {
		auto [x, y] = q.front();
		q.pop();
		if(vis[x][y]) continue;
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
	vector<i64> SUM(1, 0);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(vis[i][j] || a[i][j] == '.') continue;
			bfs(a, vis, id, i, j, SUM);
			cnt++;
		}
	}
	
	i64 ans = 0;
	
	for(int i = 1; i <= n; i++) {
		set<int> Node;
		i64 sum = 0;
		for(int j = 1; j <= m; j++) {
			if(!vis[i][j]) sum++;
			if(legal(i, j, id)) Node.insert(id[i][j]); 
			if(legal(i - 1, j, id)) Node.insert(id[i - 1][j]);
			if(legal(i + 1, j, id)) Node.insert(id[i + 1][j]);
		}

		for(auto &k:Node) {
			sum += SUM[k];
		}
		
		ans = max(sum, ans);
	}

	for(int i = 1; i <= m; i++) {
		set<int> Node;
		i64 sum = 0;
		for(int j = 1; j <= n; j++) {
			if(!vis[j][i]) sum++;
			if(legal(j, i, id)) Node.insert(id[j][i]); 
			if(legal(j, i - 1, id)) Node.insert(id[j][i - 1]);
			if(legal(j, i + 1, id)) Node.insert(id[j][i + 1]);
		}

		for(auto &k:Node) {
			sum += SUM[k];
		}
		
		ans = max(sum, ans);
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