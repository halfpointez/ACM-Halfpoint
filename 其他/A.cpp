#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
	int n;
	cin >> n;
	map<int, int> last; //记录每个数最后出现的T在原输入中的位置 从1开始
	map<int, int> cnt; //计数每个数
	vector<pair<char, int>> op(n + 1);
	stack<int> S;
	for(int i = 1; i <= n; i++) {
		cin >> op[i].first >> op[i].second;
	}

	for(int i = 1; i <= n; i++) {
		auto [c, num] = op[i];
		if(c == 'T') {
			last[num] = i;
		}
	}

	string ans;

	for(int i = 1; i <= n; i++) {
		auto [c, num] = op[i];

		while (!S.empty() && last[S.top()] < i) {
    		cnt[S.top()]--;
    		S.pop();
    		ans.push_back('-');
		}


		if(c == '+') {
			while(cnt[num] > 0) {
				cnt[S.top()]--;
				S.pop();
				ans.push_back('-');
			}
			S.push(num);
			ans.push_back('+');
			cnt[num]++;
			if(last[num] == 0 || last[num] < i) {
				ans.push_back('-');
				S.pop();
				cnt[num]--;
			}
		}

		if(c == 'T') {
			ans.push_back('?');
		}

		if(c == 'F') {
			
			while(cnt[num] > 0) {
				cnt[S.top()]--;
				S.pop();
				ans.push_back('-');
			}
			ans.push_back('?');
		}
	}

	while (!(S.empty())) {
		S.pop();
		ans.push_back('-');
	}
	
	for(auto &i:ans) {
		cout << i;
	}
	cout << endl;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
}