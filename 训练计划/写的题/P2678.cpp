#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

bool check(vector<i64> &a, i64 M, i64 X) {
	i64 cur = 0, next = 0, cnt = 0;
	for(int i = 0; i < a.size(); i++) {
		next = a[i];
		if(next - cur < X) {
			cnt++;
		} else {
			cur = next;
		}
	}

	if(cnt > M) {
		return 0;
	}
	return 1;
}

int main() {
	i64 L, N, M;
	cin >> L >> N >> M;
	vector<i64> a(N);
	for(auto &i:a) cin >> i;
	a.push_back(L);
	i64 l = 0, r = L;
	while (l < r) {
		i64 mid = l + (r - l + 1 >> 1);
		if(check(a, M, mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	
}