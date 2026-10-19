#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
vector<pair<i64, i64>> merge_seg(vector<pair<i64, i64>> &seg) {
	
	vector<pair<i64, i64>> res;
	if(seg.empty()) {
		return res;
	}
	sort(seg.begin(), seg.end());
	auto[L, R] = seg[0];
	for(auto &i:seg) {
		auto[l, r] = i;
		if(l > R) {
			res.push_back({L, R});
			L = l, R = r;
		} else {
			R = max(r, R);
		}
	}
	res.push_back({L, R});
	return res;
}

void solve() {
    i64 n, m;
    cin >> n >> m;
    vector<pair<i64, i64>> seg;
    vector<i64> in_deg(n + 1, 0);
    vector<vector<i64>> Node(n + 1);
    vector<i64> ans(n + 1);
    vector<bool> vis(n + 1, false);

    for (int i = 0; i < m; i++) {
        i64 l, r;
        cin >> l >> r;
        int cnt = r - l + 1;
        vector<i64> vals(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> vals[j];
        }
        if (l == r) continue;
        seg.push_back({l, r});
        for (int j = 0; j + 1 < cnt; j++) {
            Node[vals[j]].push_back(vals[j + 1]);
            in_deg[vals[j + 1]]++;
        }
    }

    if (seg.empty()) {
        // 没有区间，直接输出 1..n
        for (int i = 1; i <= n; i++) cout << i << (i == n ? '\n' : ' ');
        return;
    }

    vector<pair<i64, i64>> fin_seg = merge_seg(seg);
    for (auto &[l, r] : fin_seg) {
        priority_queue<i64, vector<i64>, greater<i64>> pq;
        vector<i64> ord;
        for (int i = l; i <= r; i++) {
            vis[i] = true;
            if (in_deg[i] == 0) pq.push(i);
        }
        while (!pq.empty()) {
            i64 cur = pq.top(); pq.pop();
            ord.push_back(cur);
            for (auto v : Node[cur]) {
                if (--in_deg[v] == 0) pq.push(v);
            }
        }
        if ((i64)ord.size() != r - l + 1) {
            cout << -1 << '\n';
            return;
        }
        i64 num = l;
        for (int i = l; i <= r; i++) {
            ans[ord[i - l]] = num++;
        }
    }

	for (int i = 1; i <= n; i++) {
            if (vis[i]) cout << ans[i] << (i == n ? '\n' : ' ');
            else cout << i << (i == n ? '\n' : ' ');
    }
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
	
}