#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 L, N, K;
vector<i64> a;
bool check(i64 X) {
	i64 cur = a[0];
	i64 nxt = a[1];
	i64 cnt = 0;
	for(int i = 0; i < N - 1;) {
		i64 dis = nxt - cur;
		if(dis > X) {
			cnt++;
			cur += X;
		} else {
			i++;
			if(i >= N - 1) break;
			cur = a[i];
			nxt = a[i + 1];
		}
	}
	if(cnt > K) return 0;
	return 1;
}

int main() {
	cin >> L >> N >> K;
	a.resize(N);
	for(auto &i:a) cin >> i;
	i64 MAX = 0;
	for(int i = 1; i < N; i++) {
		MAX = max(a[i] - a[i - 1], MAX);
	}
	i64 l = 1, r = MAX;
	while (l < r) {
		i64 mid = l + ((r - l) >> 1);
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l;
	
}