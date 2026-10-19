#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

void solve() {
	i64 m, x;
	cin >> m >> x;
	i64 money = 0;
	priority_queue<i64> pq;
	for(int i = 0; i < m; i++) {
		i64 c; cin >> c;
		money -= c;
		pq.push(c);
		if(money < 0) {
			money += pq.top(); pq.pop();
		}
		money += x;
	}

	cout << pq.size() << endl;

}

int main() {
	i64 t;
	cin >> t;
	while (t--) {
		solve();
	}
	
}