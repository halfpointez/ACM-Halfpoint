#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

const i64 INF = 1e9; 
int n, m;
vector<vector<char>> mp;
vector<vector<i64>> dis;
vector<vector<int>> color;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool in(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

i64 dfs(int x, int y) {
    if (color[x][y] == 1) return INF;  
    if (color[x][y] == 2) return dis[x][y];

    color[x][y] = 1; 
    i64 best = 1;

    for (int i = 0; i < 4; i++) {
        int cur_x = x + dx[i], cur_y = y + dy[i];
        if (!in(cur_x, cur_y)) continue;

        if (mp[x][y] == 'D' && mp[cur_x][cur_y] == 'I') {
            i64 sub = dfs(cur_x, cur_y);
            if (sub >= INF) return INF;  
            best = max(best, sub + 1);
        }
        else if (mp[x][y] == 'I' && mp[cur_x][cur_y] == 'M') {
            i64 sub = dfs(cur_x, cur_y);
            if (sub >= INF) return INF;
            best = max(best, sub + 1);
        }
        else if (mp[x][y] == 'M' && mp[cur_x][cur_y] == 'A') {
            i64 sub = dfs(cur_x, cur_y);
            if (sub >= INF) return INF;
            best = max(best, sub + 1);
        }
        else if (mp[x][y] == 'A' && mp[cur_x][cur_y] == 'D') {
            i64 sub = dfs(cur_x, cur_y);
            if (sub >= INF) return INF;
            best = max(best, sub + 1);
        }
    }

    color[x][y] = 2;      
    dis[x][y] = best;    
    return best;
}

void solve() {
    cin >> n >> m;

    mp.assign(n + 1, vector<char>(m + 1));
    dis.assign(n + 1, vector<i64>(m + 1, -1));
    color.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 'D') {
                i64 res = dfs(i, j);
                if (res >= INF) {
                    cout << "Poor Inna!" << endl;
                    return;
                }
                ans = max(ans, res);
            }
        }
    }

    if (ans < 4) {
        cout << "Poor Dima!" << endl;
    } else {
        cout << ans / 4 << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}