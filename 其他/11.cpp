#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vis, ans;
int cnt = 0;

void dfs(int step) {
    if (step == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
		cnt++;
		cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans.push_back(i);
            dfs(step + 1);
            ans.pop_back();
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    vis.assign(n + 1, 0);
    dfs(0);
	cout << cnt;
    return 0;
}