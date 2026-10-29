#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = double;
#define endl '\n'

struct F {
	f64 a, b, c;
};


f64 f(f64 x, vector<F> &idx) {
	f64 res = -1e9;
	for(auto &[a, b, c] : idx) {
		f64 tmp = a * x * x + b * x + c;
		res = max(tmp, res);
	}
	return res;
}



void solve() {
	i64 n;
	cin >> n;
	vector<F> idx(n);
	for(int i = 0; i < idx.size(); i++) {
		cin >> idx[i].a >> idx[i].b >> idx[i].c;
	}
	f64 l = 0, r = 1000;
	i64 t = 100;
	while (t--) {
		f64 x1 = l + (r - l) / 3, x2 = l + 2 * (r - l) / 3;
		f64 m1 = f(x1, idx), m2 = f(x2, idx);
		if(m1 > m2) l = x1;
		else r = x2;
	}
	cout << fixed << setprecision(4) << f(l, idx) << endl;
	
}

int main() {
	i64 T;
	cin >> T;
	while (T--) {
		solve();	
	}
		

}