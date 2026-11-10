#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, n, suma = 1, sumb = 1;
		cin >> a >> b >> n;
		while (a % 2 == 0) {
			a /= 2;
			suma *= 2;
		}
		
		while (b % 2 == 0) {
			b /= 2;
			sumb *= 2;
		}
		
		int sum = suma * sumb;
		if(sum >= n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}