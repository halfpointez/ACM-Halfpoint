#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		i64 fin_1 = 0, fin_0 = 0, fin_2 = 0;
		for(int i = 0; i < n; i++) {
			i64 cur; cin >> cur;
			if(cur & 1) fin_1++;
			else if((cur / 2) % 2 == 0) fin_0++;
			else  fin_2++;
		}
		cout << max(fin_1, max(fin_0, fin_2)) << endl;
	}
	
}