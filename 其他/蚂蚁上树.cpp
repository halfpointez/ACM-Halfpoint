#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> leaves;   // 存储当前子树中所有叶子的深度

void dfs(int u, int p, int depth) {
    bool isLeaf = true;
    for (int v : g[u]) {
        if (v == p) continue;
        isLeaf = false;
        dfs(v, u, depth + 1);
    }
    if (isLeaf) leaves.push_back(depth);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    g.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;
    for (int v : g[1]) {          // 枚举根节点的每个子节点，独立处理子树
        leaves.clear();
        dfs(v, 1, 1);             // v 的深度设为 1（根为 0）
        sort(leaves.begin(), leaves.end());
        int cur = 0;
        for (int d : leaves) {
            cur = max(cur + 1, d);
        }
        ans = max(ans, cur);
    }

    cout << ans << endl;
    return 0;
}