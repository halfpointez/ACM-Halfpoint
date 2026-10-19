#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64 = long long;
int main() {
	i64 n, hp = 0;
	cin >> n;
	priority_queue<i64, vector<i64>, greater<i64>> pq;

	for(int i = 0; i < n; i++) {
		i64 a; cin >> a;
		pq.push(a);
		hp += a;
		if(hp < 0) {
			hp -= pq.top();
			pq.pop(); 
		}
	}
	cout << pq.size();
}