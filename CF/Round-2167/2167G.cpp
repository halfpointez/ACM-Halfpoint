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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		map<int, int> mp, in;
		bool j = 0;
		for(auto &i:a) {cin >> i; mp[i]++;}
		for(auto &i:mp) {
			if(i.second % k != 0) {
				cout << 0 << endl; 
				j = 1;
				break;
			}
		}
		if(j) continue;

		i64 ans = 0, l = 0, r = 0;
		for(r = 0; r < n; r++) {
			in[a[r]]++;
			if(in[a[r]] <= mp[a[r]] / k) {
				ans += r - l + 1;
				continue;
			} else {
				while (l <= r) {
					if(in[a[r]] <= mp[a[r]] / k) {
						ans += r - l + 1;
						break;
					}
					in[a[l]]--;
					l++;
				}
			}
			
			
		}
		
		cout << ans << endl;
	}
	
}