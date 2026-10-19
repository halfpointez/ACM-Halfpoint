#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

bool jud(vector<vector<char>> &mp, vector<pair<i64, i64>> &cell) { //判断当前的消去方式能否成立
	for(auto &[x, y]:cell) {
		i64 cnt = 0;
		if(mp[x][y] != 'B') continue; 
		for(int i = 0; i < 4; i++) {
			i64 curx = x + dx[i], cury = y + dy[i];
			if(curx >= 1 && curx <= 7 && cury >= 1 && cury <= 7) {
				if(mp[curx][cury] == 'B') cnt++;
			} 
		}
		if(cnt == 4) return 0;
	}
	return 1;
}

bool dfs(vector<vector<char>> &mp, vector<pair<i64, i64>> &cell, i64 idx, i64 remain) {
	if(remain == 0) {
	 	return jud(mp, cell);
	} //如果可选的数字选完了 那就进行判断 

	if(idx >= (i64)cell.size()) return 0;

	if(dfs(mp, cell, idx + 1, remain)) return 1;

	auto[x, y] = cell[idx];
	mp[x][y] = 'W';

	if(dfs(mp, cell, idx + 1, remain - 1)) return 1;

	mp[x][y] = 'B';
	return 0;
} //dfs枚举排列数

void solve() {

	vector<pair<i64, i64>> cell1;
	vector<pair<i64, i64>> cell2;
	i64 sum1 = 0, sum2 = 0; 
 	vector<vector<char>> mp(8, vector<char>(8));


	for(int i = 1; i <= 7; i++) {
		for(int j = 1; j <= 7; j++) {
			cin >> mp[i][j];

			if(mp[i][j] != 'B') continue;
			if((i + j) & 1) cell1.push_back({i, j});
			else cell2.push_back({i, j});

		}
	} //循环读入图表 并且进行分类


	for(int i = 0; i <= 4; i++) {
		if(dfs(mp, cell1, 0, i)) {
			sum1 = i;
			break;
		}
	}//对cell1进行从0到4的尝试

	for(int i = 0; i <= 4; i++) {
		if(dfs(mp, cell2, 0, i)) {
			sum2 = i;
			break;
		}
	}//对cell2进行从0到4的尝试

	cout << sum1 + sum2 << endl;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}