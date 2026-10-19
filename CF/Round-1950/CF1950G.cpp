#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;

void solve() {
	int n;
	cin >> n;
	map<string, vector<int>> m1;
	map<string, vector<int>> m2;
	vector<int> P(n + 1);
	vector<int> sz(n + 1, 1);

	for(int i = 1; i <= n; i++) {
		P[i] = i;
		string s1, s2;
		cin >> s1 >> s2;
		for(auto &num:m1[s1]) {
			Union(num, i, P, sz);
		}
		for(auto &num:m2[s2]) {
			Union(num, i, P, sz);
		}
		m1[s1].push_back(i);
		m2[s2].push_back(i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, sz[i]);
	}

	cout << n - ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}