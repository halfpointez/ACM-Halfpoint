#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> color(n + 1, -1);
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;
        color[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }

    vector<int> A, B;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 1) A.push_back(i);
        else B.push_back(i);  // color[i] == 0
    }

    // 输出 A
    cout << A.size() << '\n';
    for (int x : A) cout << x << ' ';
    cout << '\n';

    // 输出 B
    cout << B.size() << '\n';
    for (int x : B) cout << x << ' ';
    cout << '\n';

    return 0;
}