#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<int, bool> mp;
	stack<int> st;
	int cnt = n;
	for(int i = 1; i <= n; i++) {
		if(s[i - 1] == '1') st.push(i);
		else if(s[i - 1] == '2') {
			if(!st.empty()) {
				
				mp[st.top()] = 1;
				st.pop();
			} else {
				mp[i] = 1;
			}
			
			cnt--;
		} else if(s[i - 1] == '3') {
			mp[i] = 1;
			cnt--;
		}
	}
	if(cnt <= 0) cout << 0 << endl;
	else {
		cout << cnt << endl;
	}
	for(int i = 1; i <= n; i++) {
		if(!mp[i]) cout << i << ' ';
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}