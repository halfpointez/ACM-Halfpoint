#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 INF = -1e18;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 n, k, ans = 0;
	cin >> n >> k;
	vector<i64> a(n + 2);
	vector<i64> pre(n + 2);
	vector<i64> nxt(n + 2);
	vector<i64> val(n + 2);
	vector<bool> used(n + 2, 0);
	val[0] = INF, val[n + 1] = INF;
	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>> pq;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = i - 1;
		nxt[i] = i + 1;
		val[i] = a[i];
		pq.push({val[i], i}); //val, id
	}
	pre[n + 1] = n;
	nxt[0] = 1;
	i64 cnt = 0;
	while (!pq.empty() && cnt < k) {
		while (!pq.empty() && used[pq.top().second]) {
			pq.pop();
		}
		if (pq.empty()) break;
		auto[v, id] = pq.top();
		pq.pop();
		if(v <= 0) break;
		ans += v;
		i64 L = pre[id], R = nxt[id];
		i64 L1 = pre[L], R1 = nxt[R];
		i64 nv = val[L] + val[R] - val[id];
		val[id] = nv;
		used[L] = 1, used[R] = 1;
		pre[id] = L1, nxt[id] = R1;
		nxt[L1] = id;
		pre[R1] = id;
		pq.push({nv, id});
		cnt++;
	}

	cout << ans;

	
} 
