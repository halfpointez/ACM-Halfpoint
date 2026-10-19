#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> a(3);
		cin >> a[0] >> a[1] >> a[2];
		sort(a.begin(), a.end());
		if(a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) cout << 0 << endl;
		else {
			int ans = 0;
			ans = min((a[2] - a[0]) / 2, min((a[1] - a[0]), a[2] - a[1]));
			
			cout << ans << endl; 
		}
		
		
	}
	
}