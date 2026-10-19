#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(3);
		for(auto &i:a) cin >> i;
		i64 MIN = min(a[0], min(a[2], a[1]));
		cout << n - MIN << endl;
	}
	
}