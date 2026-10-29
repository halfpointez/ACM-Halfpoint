#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = double;
#define endl '\n'

f64 F(vector<f64> &x, vector<f64> &t, f64 x0) {
	f64 res = -1e9;
	for(int i = 0; i < x.size(); i++) {
		res = max(res, fabs(x0 - x[i]) + t[i]);
		
	}
	return res;
}

void solve() {
	i64 n;
	cin >> n;
	vector<f64> x(n);
	vector<f64> t(n);
	for(auto &i:x) cin >> i;
	for(auto &i:t) cin >> i;
	f64 l = 0, r = 1e8;
	i64 t1 = 100;
	while (t1--) {
		f64 x1 = l + (r - l) / 3, x2 = l + 2 * (r - l) / 3;
		f64 f1 = F(x, t, x1), f2 = F(x, t, x2);
		if(f1 < f2) r = x2;
		else l = x1;
	}
	cout << fixed << setprecision(10) << l << endl;
	
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}