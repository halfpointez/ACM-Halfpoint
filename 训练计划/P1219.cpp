#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<vector<bool>> board;
map<i64, bool> diagonal;
map<i64, bool> row;
map<i64, bool> clo;
i64 cnt = 0;
void dfs(i64 x, i64 y) {
	if(row[x] == 1) return;
	if(clo[y] == 1) return;
	if(diagonal[x - y] == 1) return;
	if(diagonal[x + y] == 1) return;

	board[x][y] = 1;
	i64 nxt_x = x % 6 + 1;
	i64 nxt_y = y;
	if(nxt_x == 0) y + 1;

	dfs(nxt_x, nxt_y);

	row[x] = 1; clo[y] = 1; 
	diagonal[x - y] = 1; diagonal[x + y] = 1;

	dfs(nxt_x, nxt_y);

	row[x] = 0; clo[y] = 0; 
	diagonal[x - y] = 0; diagonal[x + y] = 0;

	
	if(x == 6 && y == 6) {
		cnt++;
		return;	
	}
	
	
}

int main() {

	board.resize(7, vector<bool>(7, 0));

	

}