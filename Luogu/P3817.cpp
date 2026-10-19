#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	i64 n, x;
	cin >> n >> x;
	vector<i64> a(n);
	i64 ans = 0;
	for(auto &i:a) cin >> i;
	for(int i = 0; i < n; i++) {
		i64 sum = a[i];
		if(i < n - 1) {
			sum += a[i + 1];
		}
		if(sum > x) {
			a[i + 1] -= min(sum - x, a[i + 1]);
			ans += min(sum - x, a[i + 1]);
			sum -= min(sum - x, a[i + 1]);
		} 
			
			
		if(sum > x) {
			a[i] -= sum - x;
			ans += sum - x;
			sum -= sum - x;
		} 
		
	}
	cout << ans;

	

}