#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
i64 get_time(string s) {
	auto pos = s.find(':');
	i64 res = 0;
    res += (stoll(s.substr(0, pos)) * 60);
    res += (stoll(s.substr(pos + 1)));
	return res;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	i64 n;
	cin >> n;

	i64 TT = get_time(s2) - get_time(s1);
	
	vector<int> c;
	vector<int> t;
	vector<bool> INF(2e6 + 5, 0);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		i64 C, T, P;
		cin >> T >> C >> P;
		if(P == 0) {
			c.push_back(C);
			t.push_back(T);
			INF[cnt] = 1;
			cnt++;
		} else {
			for(int j = 0; j < P; j++) {
				c.push_back(C);
				t.push_back(T);
				cnt++;
			}
		}
	}
	vector<i64> dp(TT + 1, 0);
	for(int i = 0; i < c.size(); i++) {
		if(INF[i]) {
			for(int j = t[i]; j <= TT; j++) {
				dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
			}	
		} else {
			for(int j = TT; j >= t[i]; j--) {
				dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
			}
		}
	}

	cout << dp[TT] << endl;
	 
}