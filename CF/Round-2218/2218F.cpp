#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int x, y; //even odd
		cin >> x >> y;
		i64 l_cnt = x + y - 1;
		if((x + y) & 1) {
			y--;
		}
		else x--;

		if(y < x || x < 0 || y < 0) {

			cout << "NO" << endl;
			continue;
		} 
		cout << "YES" << endl;
		int cur = 2;
		while (x--) {
			cout << 1 << ' ' << cur << endl;
			cout << cur << ' ' << cur + 1 << endl;
			cur += 2;
			y--;
		}
		while (y--) {
			cout << 1 << ' ' << cur << endl;
			cur += 1;
		}
		
		

	}
	
}