#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<i64> a(n);
    for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	map<i64, priority_queue<i64, vector<i64>, greater<i64>>> mp;

	for(int i = 0; i < n; i++) {
		auto &pq = mp[a[i] - 1];
		auto &self = mp[a[i]];
		if(pq.empty()) {
			self.push(1);
		} else {
			i64 cur = pq.top();
			pq.pop();
			self.push(cur + 1);
		}
	}
	i64 ans = 1e9;
	for(auto &i:mp) {
		if(i.second.empty()) continue;
		i64 cur = i.second.top();
		ans = min(ans, cur);
	}
	cout << ans;
}