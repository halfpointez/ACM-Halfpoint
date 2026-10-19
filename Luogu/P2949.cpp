#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	priority_queue<i64, vector<i64>, greater<i64>> pq;
	vector<pair<i64, i64>> task(N);
	i64 ans = 0;
	for(int i = 0; i < N; i++) cin >> task[i].first >> task[i].second;
	sort(task.begin(), task.end());
	for(int i = 0; i < N; i++) {
		auto[D, P] = task[i];
		ans += P;
		pq.push(P);
		if(pq.size() > D) {
			ans -= pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;
}