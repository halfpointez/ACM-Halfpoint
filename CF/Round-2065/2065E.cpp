#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int n;
	cin >> n;
	vector<i64> a(n);
	for(auto &i:a) cin >> i;
	i64 MAX = a[0], pre = a[0];
	for(int i = 1; i < n; i++) {
		if(pre + a[i] >= pre) {
			pre += a[i]; MAX = max(MAX, pre);
		} else {
			pre = a[i];
			MAX = max(MAX, pre);
		}
	}
	cout << MAX << endl;
	
}