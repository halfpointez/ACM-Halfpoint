#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 n, p, s;
	cin >> n >> p >> s;
	i64 ans = 0;
	vector<i64> type(n + 1, 0); //0none 1p 2s
	vector<i64> a(n); //val, id
	vector<i64> b(n);
	priority_queue<pair<i64, i64>, vector<pair<i64, i64>>> p1, p2, p3; //p1最大的a, p2最大的b, p3最大的b - a 
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) {
		p1.push({a[i], i}); p2.push({b[i], i}); p3.push({b[i] - a[i], i});
	}

	for(int i = 0; i < p; i++) {
		auto[val, id] = p1.top();
		p1.pop();
		ans += val;
		type[id] = 1;
	}

	for(int i = 0; i < s; i++) {
		while (!p1.empty() && type[p1.top().second] != 0) p1.pop();
		while (!p2.empty() && type[p2.top().second] != 0) p2.pop();
		while (!p3.empty() && type[p3.top().second] != 1) p3.pop();
		i64 n1 = -1e9, n2 = -1e9;
		if(!p1.empty() && !p3.empty()) {
			n1 = p1.top().first + p3.top().first;
		}
		if(!p2.empty()) {
			n2 = p2.top().first;
		}
		
		if(n1 > n2) {
			ans += n1;
			i64 itmp = p1.top().second;
			type[p1.top().second] = 1;
			type[p3.top().second]= 2;

			p1.pop(); p3.pop();
			p3.push({b[itmp] - a[itmp], itmp});
		} else {
			ans += n2;
			type[p2.top().second] = 2;
			p2.pop();
		}
	}

	cout << ans << endl;
	for (int i = 0; i < n; i++) if (type[i] == 1) cout << i + 1 << ' ';
	cout << endl;
	for (int i = 0; i < n; i++) if (type[i] == 2) cout << i + 1 << ' ';
	cout << endl;

	

}