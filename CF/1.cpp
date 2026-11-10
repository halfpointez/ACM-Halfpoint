#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		i64 n, m;
		cin >> n >> m;
		vector<vector<i64>> a(n, vector<i64>(m));
		vector<pair<i64, i64>> sum(n); //sum, pos
		for(int i = 0; i < n; i++) {
			i64 tmp = 0;
			for(int j = 0; j < m; j++) {
				cin >> a[i][j];
				tmp += a[i][j];
			}
			sum[i] = {tmp, i};
		}
		sort(sum.begin(), sum.end(), greater<>());
		i64 ans = 0;
		i64 pre = 0;
	
		for(auto &i:sum) {
			i64 curr = i.second;
			for(auto &j:a[curr]) {
				pre += j;
				ans += pre;
			}
		}
		cout << ans << endl;


	}
	
}