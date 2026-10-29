#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = double;
#define endl '\n'

f64 cacl(i64 N, vector<f64> idx, f64 x) {
	f64 res = 0;
	for(int i = 0; i < idx.size(); i++) {
		f64 tmp = idx[i];
		for(int j = 0; j < N - i; j++) {
			tmp *= x;
		}
		res += tmp;
	}
	return res;
}

int main() {
	i64 N; 
	f64 L, R;
	cin >> N >> L >> R;
	vector<f64> idx(N + 1);
	for(auto &i:idx) cin >> i;
	i64 t = 100;
	f64 l = L, r = R;
	while (t--) {
		f64 m1 = cacl(N, idx, l + (r - l) / 3);
		f64 m2 = cacl(N, idx, l + 2 * (r - l) / 3);
		if(m1 < m2) {
			l = l + (r - l) / 3;
		} else {
			r = l + 2 * (r - l) / 3;
		}
	}
	cout << fixed << setprecision(5) << l;
	
}