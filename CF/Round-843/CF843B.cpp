#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

i64 rand_int(i64 l, i64 r) {
    uniform_int_distribution<i64> dist(l, r);
    return dist(rng);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, start, x;
    cin >> n >> start >> x;

    // 采样集合：{值, 下标}
    vector<pair<i64,i64>> samples;
    samples.reserve(1001);

    // 1) 必须先问起始节点
    cout << "? " << start << endl;
    i64 v, nxt;
    cin >> v >> nxt;
    samples.push_back({v, start});

    // 2) 随机采样约 1000 个节点
    i64 sample_cnt = min((i64)1000, n);
    for (i64 i = 1; i < sample_cnt; i++) {
        i64 idx = rand_int(1, n);
        cout << "? " << idx << endl;
        cin >> v >> nxt;
        samples.push_back({v, idx});
    }

    // 3) 找值 < x 且最大的采样点，作为扫描起点
    i64 best_val = LLONG_MIN, best_idx = -1;
    for (auto &p : samples) {
        if (p.first < x && p.first > best_val) {
            best_val = p.first;
            best_idx = p.second;
        }
    }

    // 4) 如果所有采样值都 >= x，直接输出其中最小的
    if (best_idx == -1) {
        i64 ans = LLONG_MAX;
        for (auto &p : samples)
            if (p.first >= x && p.first < ans) ans = p.first;
        cout << "! " << ans << endl;
        return 0;
    }

    // 5) 从 best_idx 顺序扫描
    i64 cur = best_idx;
    while (cur != -1) {
        cout << "? " << cur << endl;
        cin >> v >> nxt;
        if (v >= x) {
            cout << "! " << v << endl;
            return 0;
        }
        cur = nxt;
    }
    cout << "! -1" << endl;
    return 0;
}