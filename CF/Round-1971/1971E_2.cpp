	#include <bits/stdc++.h>
	using namespace std;
	#define endl '\n'
	using i64 = long long;
	int main() {
		int t;
		cin >> t;
		while (t--) {
			i64 n, k, q;
			cin >> n >> k >> q;
			vector<i64> a(k + 1, 0);
			vector<i64> b(k + 1, 0);
			for(int i = 1; i <= k; i++) cin >> a[i];
			for(int i = 1; i <= k; i++) cin >> b[i];

			while (q--) {
				i64 d; cin >> d;
				if(d == 0) {cout << 0 << ' '; continue;}
				int pos = lower_bound(a.begin(), a.end(), d) - a.begin();
				i64 ans = (d - a[pos - 1]) * (b[pos] - b[pos - 1]) / (a[pos] - a[pos - 1]) + b[pos - 1];
				cout << ans << ' ';
			}
			cout << endl;
			

		}
		
	}