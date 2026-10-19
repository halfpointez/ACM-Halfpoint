#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

i64 sum(i64 x, vector<i64>& T) {
	i64 res = 0;
	for(auto &i:T) {
		if(i - x <= 0) continue;
		res += i - x;
	}
	return res;
}

int main() {
	i64 N, M;
	cin >> N >> M;
	vector<i64> Tree(N);
	for(auto &i:Tree) cin >> i;
	i64 l = 0, r = 2e9 + 5;
	while (l < r) {
		i64 mid = l + ((r - l + 1) >> 1);
		i64 cur = sum(mid, Tree);
		if(cur >= M) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
	
}