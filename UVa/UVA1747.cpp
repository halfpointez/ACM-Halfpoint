#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

struct dist {
	i64 a, b;

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	i64 n, now = 0, buy = 0;
	cin >> n;
	vector<dist> d1, d2;
	for(int i = 0; i < n; i++) {
		dist dtmp;
		cin >> dtmp.a >> dtmp.b;
		if(dtmp.a < dtmp.b) d1.push_back(dtmp);
		else d2.push_back(dtmp); 
	}

	sort(d1.begin(), d1.end(), [](auto A, auto B){return A.a < B.a;});
	for(auto &[a, b]:d1) {
		i64 plus = b - a;
		if(now < a) {buy += (a - now); now += (a - now); }
		now += plus;
	}
	i64 sum_minus = 0;
	for(auto &[a, b]:d2) {
		sum_minus += a - b;
	}
	now -= sum_minus;
	if(now < 0) {
		buy += -now;
	}

	cout << buy;

}