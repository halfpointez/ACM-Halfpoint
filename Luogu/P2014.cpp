#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
i64 N, M; //N课程数量 M选课上限 即背包上限
vector<vector<i64>> Node;
vector<pair<i64, i64>> course;
vector<vector<i64>> dp;

void dfs(i64 u, i64 p) {
	dp[u][1] = course[u].second;
	for(auto &v:Node[u]) {
		if(v == p) continue;
		dfs(v, u);
		for(int i = M + 1; i >= 1; i--) {
			for(int j = 0; j < i; j++) {
				dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[v][j]);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	Node.resize(N + 1);
	course.resize(N + 2); //k, s;
	course[0] = {0, 0};
	dp.assign(N + 1, vector<i64>(M + 2, 0));

	for(int i = 1; i <= N; i++) {
		i64 k, s;
		cin >> k >> s;
		course[i].first = k, course[i].second = s;
		Node[i].push_back(k);
		Node[k].push_back(i);
	}

	dfs(0, -1);
	

	cout << dp[0][M + 1] << endl;



}