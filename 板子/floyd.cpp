#include <bits/stdc++.h>
#define endl '\n'
using i64 = long long;
const i64 INF = 1e9;
using namespace std;
void init(const i64 &n, const i64 &m, vector<vector<i64>> &G, vector<vector<i64>> &Pre) {
	G.resize(n + 1, vector<i64>(n + 1, INF));
	Pre.resize(n + 1, vector<i64>(n + 1, -1));
	for(int i = 0; i < m; i++) {
		i64 u, v, w;
		cin >> u >> v >> w;
		G[u][v] = min(w, G[u][v]);
		G[v][u] = min(w, G[v][u]);
		Pre[u][v] = u;
		Pre[v][u] = v;
	}
	for(int i = 1; i <= n; i++) {
		G[i][i] = 0;
	}
}

void Floyd(i64 n, i64 m) { //n个点m条边
	vector<vector<i64>> G;
	vector<vector<i64>> Pre;
	init(n, m, G, Pre);
	for(int k = 1; k <= n; k++) { //k为当前尝试的前驱点
		for(int i = 1; i <= n; i++) {
			if(i == k) continue; //如果含当前点的临接矩阵 不会变化
			for(int j = 1; j <= n; j++) {
				if(j == k) continue;
				if(G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
					Pre[i][j] = Pre[k][j];
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << G[i][j] << ' ';
		}
		cout << endl;
	}
}

vector<int> getPath(int s, int t, const vector<vector<i64>>& Pre) {
    vector<int> path;
    if (Pre[s][t] == -1) { // 不连通
        return path;
    }
    
    int cur = t;
    while (cur != s) {
        path.push_back(cur);          // 把当前节点加入路径
        cur = Pre[s][cur];            
        if (cur == -1) return {};     // 安全保护
    }
    path.push_back(s);                // 最后加入起点
    reverse(path.begin(), path.end()); // 反转得到正向路径
    return path;
}

int main() {
	int n, m;
	cin >> n >> m;
	Floyd(n, m);
	
}