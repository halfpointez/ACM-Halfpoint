#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
const i64 INF = (1LL << 31) - 1; // 题目要求的上限 依据题目更改

// ==================== SPFA 单源版（入队次数判负环） ====================
// 返回 1 表示存在负环（源点可达），0 表示正常
bool spfa(vector<vector<pair<i64, i64>>> &Node, vector<i64> &dis,
          vector<i64> &pre_node, vector<i64> &cnt, int n, int start) {

    vector<bool> inq(n + 1, false);
    queue<i64> q;

    dis[start] = 0;
    q.push(start);
    inq[start] = true;
    cnt[start] = 1;

    while (!q.empty()) {
        i64 u = q.front();
        q.pop();
        inq[u] = false;

        if (dis[u] == INF) continue;

        for (auto &[v, w] : Node[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pre_node[v] = u;

                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                    cnt[v]++;
                    if (cnt[v] >= n) {
                        return 1; // 存在负环
                    }
                }
            }
        }
    }
    return 0;
}

// ==================== SPFA 全源版（检测任意位置的负环） ====================
// 返回 1 表示存在负环，0 表示正常
bool spfa_all(vector<vector<pair<i64, i64>>> &Node, vector<i64> &dis,
              vector<i64> &pre_node, vector<i64> &cnt, int n) {

    vector<bool> inq(n + 1, true);
    queue<i64> q;

    for (int i = 1; i <= n; i++) {
        dis[i] = 0;   // 超级源点：所有点距离初始为 0
        cnt[i] = 1;
        q.push(i);
    }

    while (!q.empty()) {
        i64 u = q.front();
        q.pop();
        inq[u] = false;

        for (auto &[v, w] : Node[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pre_node[v] = u;

                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                    cnt[v]++;
                    if (cnt[v] > n) { // 全源版阈值是 > n
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// ==================== SPFA 边数法版（更稳健，推荐） ====================
// 返回 1 表示存在负环，0 表示正常
bool spfa_len(vector<vector<pair<i64, i64>>> &Node, vector<i64> &dis,
              vector<i64> &pre_node, vector<i64> &len, int n, int start) {

    vector<bool> inq(n + 1, false);
    queue<i64> q;

    dis[start] = 0;
    len[start] = 0;
    q.push(start);
    inq[start] = true;

    while (!q.empty()) {
        i64 u = q.front();
        q.pop();
        inq[u] = false;

        if (dis[u] == INF) continue;

        for (auto &[v, w] : Node[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pre_node[v] = u;
                len[v] = len[u] + 1;

                if (len[v] >= n) {
                    return 1; // 路径边数达到 n，必有负环
                }

                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return 0;
}

// ==================== 路径回溯 ====================
vector<i64> get_path(vector<i64> &pre_node, i64 start, i64 end) {
    vector<i64> res;
    if (end < 1 || end >= (i64)pre_node.size()) return res;

    i64 cur = end;
    while (cur != -1) {
        res.push_back(cur);
        if (cur == start) { // 关键：遇到 start 就停
            reverse(res.begin(), res.end());
            return res;
        }
        cur = pre_node[cur];
    }
    cout << "不可达" << endl;
    return {};
}

// ==================== 主函数 ====================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        i64 n, m;
        cin >> n >> m;

        vector<vector<pair<i64, i64>>> Node(n + 1);
        vector<i64> pre_node(n + 1, -1);
        vector<i64> dis(n + 1, INF);
        vector<i64> cnt(n + 1, 0);   // 入队次数法用
        // vector<i64> len(n + 1, 0); // 边数法用

        for (int i = 1; i <= m; i++) {
            i64 u, v, w;
            cin >> u >> v >> w;
            Node[u].push_back({v, w});
            // 无向图额外加：Node[v].push_back({u, w});
        }

        // ===== 选择一种调用方式 =====

        // 【1】单源 SPFA（从 1 号点出发），入队次数判负环
        if (spfa(Node, dis, pre_node, cnt, n, 1)) {
            cout << "YES" << endl; // 有负环
        } else {
            cout << "NO" << endl;
            // 最短路输出示例：
            // for (int i = 1; i <= n; i++) {
            //     if (dis[i] == INF) cout << "INF ";
            //     else cout << dis[i] << " ";
            // }
            // cout << endl;
        }

        // 【2】全源 SPFA（检测任意位置负环）
        // if (spfa_all(Node, dis, pre_node, cnt, n)) {
        //     cout << "YES" << endl;
        // } else {
        //     cout << "NO" << endl;
        // }

        // 【3】边数法 SPFA（更稳健）
        // if (spfa_len(Node, dis, pre_node, len, n, 1)) {
        //     cout << "YES" << endl;
        // } else {
        //     cout << "NO" << endl;
        // }
    }
    return 0;
}