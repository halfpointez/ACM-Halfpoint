#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		i64 ans = 0;
		for(int i = 0; i < n; i++) {
			i64 tmp = 1;
			int j;
			for(j = i; j < i + k; j++) {
				if(s[j] == '0') {
					tmp = 0;
				}
			}
			i = j - 1;
			ans += tmp;
			
		}
		cout << ans << endl;
	}
	
}