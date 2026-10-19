#include <bits/stdc++.h>
using namespace std;

void dfs_front(int u, vector<vector<int>> &Node) {
    if (u == 0) return;
    cout << u << ' ';
    dfs_front(Node[u][0], Node); // 左
    dfs_front(Node[u][1], Node); // 右
}

void dfs_mid(int u, vector<vector<int>> &Node) {
    if (u == 0) return;
    dfs_mid(Node[u][0], Node);   // 左
    cout << u << ' ';
    dfs_mid(Node[u][1], Node);   // 右
}

void dfs_back(int u, vector<vector<int>> &Node) {
    if (u == 0) return;
    dfs_back(Node[u][0], Node);  // 左
    dfs_back(Node[u][1], Node);  // 右
    cout << u << ' ';
}

int main() {
    int n;
    cin >> n;
    // 每个节点固定两个位置：0 左孩子，1 右孩子
    vector<vector<int>> Node(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        Node[i][0] = l;
        Node[i][1] = r;
    }

    dfs_front(1, Node);
    cout << endl;
    dfs_mid(1, Node);
    cout << endl;
    dfs_back(1, Node);
    cout << endl;

    return 0;
}