#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
	i64 N, T = 0;
	cin >> N;
	vector<pair<i64, i64>> build(N);
	for(auto &i:build) cin >> i.first >> i.second;
	sort(build.begin(), build.end(),[](auto& x,auto& y){
		return x.second < y.second;
	});
	priority_queue<i64> pq;
	for(int i = 0; i < N; i++) {
		auto[T1, T2] = build[i];
		T += T1;
		pq.push(T1);
		if(T > T2) {
			T -= pq.top();
			pq.pop();
		}
	}
	cout << pq.size();
}