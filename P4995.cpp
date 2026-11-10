#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
int main() {
	i64 n;
	cin >> n;
	vector<i64> h(n);
	for(auto &i:h) cin >> i;
	i64 l = 0, r = n;
	h.push_back(0);
	i64 ans = 0;
	sort(h.begin(), h.end());
	while (l < r) {
		ans += (i64)(h[l] - h[r]) * (h[l] - h[r]);
		l++;
		if(l >= r) break;
		ans += (i64)(h[l] - h[r]) * (h[l] - h[r]);
		r--;
		if(l >= r) break;
	}
	cout << ans;
}