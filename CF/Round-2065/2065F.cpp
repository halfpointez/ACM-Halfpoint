#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	int t;
	cin >> t;
	while (t--) {
		i64 n;
		cin >> n;
		map<i64, bool> ans;
		vector<vector<i64>> Node(n + 1);
		vector<i64> w(n + 1);
		for(int i = 1; i <= n; i++) {
			cin >> w[i];
		}
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			Node[u].push_back(v);
			Node[v].push_back(u);
		}

		for(int i = 1; i <= n; i++) {
			map<i64, i64> mp;
				mp[w[i]]++;
				for(auto &j:Node[i]) {
					mp[w[j]]++;
					if(mp[w[j]] >= 2) {
						ans[w[j]] = 1;
					}
				}
		}

		for(int i = 1; i <= n; i++) {
			if(ans[i]) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	
}