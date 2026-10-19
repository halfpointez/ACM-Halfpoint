#include <bits/stdc++.h>
using i64 = long long;
#define endl '\n'
using namespace std;

i64 solve() {
	i64 n;
	cin >> n;
	vector<i64> a(n + 1);
	map<i64, bool> yes;
	map<i64, bool> must_yes;
	map<i64, bool> no;
	vector<pair<i64, i64>> LNR;
	vector<i64> type(n + 1, -1);
	vector<bool> vis(n + 1, 0);
	vector<vector<i64>> Node(n + 1); 
	for(i64 i = 1; i <= n; i++) cin >> a[i];//输入岛屿距离数组

	for(i64 i = 1; i <= n; i++) {
		if(a[i] == -1) continue;
		if(a[i] == 0) {
			yes[i] = 1;
			continue;
		}
		i64 l = max((i64)1, i - a[i]);
		i64 r = min(n, i + a[i]);

		if((l < 1) && (r  > n)) {
			return 0;
		} else if(l < 1) {
			must_yes[r] = 1;
		} else if(r > n) {
			must_yes[l] = 1;
		} else {
			LNR.push_back({l, r});
		}

			
		for(int j = i; j >= max((i64)1, l + 1); j--) {
			no[j] = 1;
		} //标记左侧不能放置宝藏的位置

		for(int j = i; j <= min(n ,r - 1); j++) {
			no[j] = 1;
		} //标记右侧不能放置宝藏的位置

		if(!(l < 1)) {
			yes[l] = 1;
		}

		if(!(r > n)) {
			yes[r] = 1;
		}

	}

	for(i64 i = 1; i <= n; i++) {
		if(must_yes[i] == 1 && no[i] == 0) {
			type[i] = 1;
		} else if(must_yes[i] == 1 && no[i] == 1){
			return 0;
		}
		else if(yes[i] == 0 && no[i] == 0) type[i] = 2;
		else if(yes[i] != no[i]) type[i] = 1;
		else if(yes[i] == 1 && no[i] == 1) type[i] = 3;
	}

	for(auto &i:LNR) {
		auto[l, r] = i;
		if(type[l] == 3 && type[r] == 3) {
			return 0;
		} else if(type[l] == 3 || type[r] == 3){
			type[l] = 1; type[r] = 1;	
		} else {
			Node[l].push_back(r);
			Node[r].push_back(l);
		}
	}

	i64 res = 1;
	for(i64 i = 1; i <= n; i++) {
		if(type[i] != 3) {
			res *= type[i];
		}
	}

	for(int i = 1; i < n; i++) {
		if(!Node[i].empty()) {

		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		
		
	}
	
}