#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
	i64 n;
	cin >> n;
	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>> custom;
	vector<i64> a(n), b(n);
	for(auto &i:a) cin >> i; for(auto &i:b) cin >> i;

	i64 sum = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		custom.push({b[i], i});
		sum -= b[i];
		if(sum < 0) {
			sum += custom.top().first;
			custom.pop();
		}
	}

	cout << custom.size() << endl;
	while (!custom.empty()) {
		cout << custom.top().second + 1 << ' ';
		custom.pop();
	}
	
}