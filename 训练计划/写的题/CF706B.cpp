#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	i64 n;
	cin >> n;
	vector<i64> x(n);
	
	for(auto &i:x) cin >> i;
	x.push_back(0);
	sort(x.begin(), x.end());
	i64 q; cin >> q;

	while(q--) {
		i64 m; cin >> m;
		i64 l = 0, r = n;
		while (l < r) {
			i64 mid = l + ((r - l + 1) >> 1);
			if(x[mid] <= m) {
				l = mid;
			} else r = mid - 1;
		}	
		if(l == 0) {
			cout << 0 << endl;
		} else {
			cout << r << endl;
		}
	}
	
}