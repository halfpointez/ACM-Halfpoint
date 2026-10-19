#include <bits/stdc++.h>
using namespace std;

int main() {
	int w, n;
	cin >> w >> n;
	vector<int> a(n); for(auto &i:a) cin >> i;
	vector<bool> ok(n, 0);
	sort(a.begin(), a.end());
	int l = 0, r = n - 1;
	int ans = 0;
	while (l < r) {
		if(a[l] + a[r] > w) {r--; continue;}
		if(a[l] + a[r] <= w) {ok[l] = 1, ok[r] = 1, l++, r--; ans++;}
	}

	for(int i = 0; i < n; i++) {
		if(!ok[i]) ans++;
	}

	cout << ans;
	
}