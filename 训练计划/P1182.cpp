#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
bool check(i64 x, i64 M, vector<i64> a) {
	i64 res = 0;
	i64 seg_sum = 0;
	for(auto &i:a) {
		if(seg_sum + i > x) {
			seg_sum = i;
			res++;
		} else seg_sum += i;
		if(res > M) return 0;
	}
	if(res >= M) return 0;
	return 1;
}

int main() {
	i64 N, M;
	cin >> N >> M;
	vector<i64> a(N);
	i64 MAX = 0, SUM = 0;
	for(auto &i:a) {
		cin >> i;
		MAX = max(MAX, i);
		SUM += i;
	}

	i64 l = MAX, r = SUM;
	while (l < r) {
		i64 mid = l + ((r - l) >> 1);
		if(check(mid, M, a)) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	
}