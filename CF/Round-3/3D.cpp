#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
	string s;
	cin >> s;
	string s1 = s;
	i64 n = 0;

	vector<bool> is_qus(s.size(), 0);
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '?') {
			is_qus[i] = 1; 
			n++;
			s1[i] = ')';
		}
	} 
	i64 ans = 0;
	i64 blc = 0;
	vector<pair<i64, i64>> qus(n);
	for(auto &[a, b]:qus) {
		cin >> a >> b;
		ans += b;
	}
	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<pair<i64, i64>>> pq;
	i64 cnt = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s1[i] == '(') blc++;
		else if(s1[i] == ')') blc--;
		if(is_qus[i]) {
			auto[a, b] = qus[cnt];
			pq.push({a - b, i});
			cnt++;
		}

		if(blc < 0) {
			while (!pq.empty() && blc < 0) {
				auto [val, pos] = pq.top();
				pq.pop();
				ans += val;
				blc += 2;
				s1[pos] = '(';
			}
		}

		if(blc < 0) {
			cout << -1;
			return 0;
		}
		
	}
	if (blc != 0) {
    	cout << -1;
    	return 0;
	}
	cout << ans << endl;
	for(auto &c:s1) cout << c;

}