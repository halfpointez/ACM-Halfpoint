#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int T;
	cin >> T;
	while (T--) {
		i64 a, b, c;
		cin >> a >> b >> c;
		cout << max(abs(a - b), abs(a + c - b)) << endl;

	}
	
}