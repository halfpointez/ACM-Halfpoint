#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

vector<pair<i64, i64>> merge_seg(vector<pair<i64, i64>> &seg) {
	vector<pair<i64, i64>> res;
	if(seg.empty()) return res;
	
	auto[L, R] = seg[0];
	for(auto[l, r] : seg) {
		if(l > R + 1) {
			res.push_back({L, R});
			L = l, R = r;
		} else {
			R = max(r, R);
		}
	}
	res.push_back({L, R});
	return res;
}

bool check(vector<i64> &a, i64 x, i64 h) {
	vector<pair<i64, i64>> seg;
	for(auto &i:a) {
		seg.push_back({i, i + x - 1});
	}
	seg = merge_seg(seg);
	i64 sum = 0;
	for(auto &[l, r]:seg) {
		sum += (r - l + 1);
	}
	if(sum >= h) {
		return 1;
	}
	return 0;
}

int main() {
	i64 t;
	cin >> t;
	while (t--) {
		i64 n, h;
		cin >> n >> h;
		vector<i64> a(n);
		for(auto &i:a) cin >> i;
		i64 l = 0, r = 1e18;
		while (l < r) {
			i64 mid = l + (r - l >> 1);
			if(check(a, mid, h)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		cout << r << endl;
	}
	
}