#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = double;
#define endl '\n'
f64 a, b, c, d;
f64 cacl(f64 x) {
	f64 res = a * x * x * x + b * x * x + c * x + d;
	return res;
}

bool check(f64 l, f64 r, f64 mid) {
	if(cacl(l) * cacl(mid) <= 0) {
		return 1;
	} 
	return 0;
}

int main() {
	vector<f64> ans;
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(2);
	for(int i = -100; i <= 100; i++) {
		if(ans.size() >= 3) break;
		f64 l = i, r = i + 1;

		if(cacl(l) == 0) {
			ans.push_back(l);
			continue;
		} 

		if(cacl(l) * cacl(r) >= 0) continue;
		i64 t = 100; 
		while (t--) {
			f64 mid = (l + r) / 2;
			if(check(l, r, mid)) {
				r = mid;
			} else l = mid;
		}
		if(cacl(l) * cacl(r) <= 0) {
			ans.push_back((l + r) / 2);
		}
	}
	for(auto &i:ans) cout << i << ' ';
}