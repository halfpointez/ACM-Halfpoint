#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

struct p {
	i64 a, b, id;
};

int main() {
	i64 n, A_t = 0, B_t = 0;
	cin >> n;
	vector<p> pd(n);
	vector<p> pd1;
	vector<p> pd2;
	vector<i64> ord;
	for(int i = 0; i < n; i++) cin >> pd[i].a;
	for(int i = 0; i < n; i++) cin >> pd[i].b;
	for(int i = 0; i < n; i++) {
		pd[i].id = i + 1;
		if(pd[i].a < pd[i].b) pd1.push_back(pd[i]);
		if(pd[i].a >= pd[i].b) pd2.push_back(pd[i]);
	}

	sort(pd1.begin(), pd1.end(), [](const auto &A, const auto &B){return A.a < B.a;});
	sort(pd2.begin(), pd2.end(), [](const auto &A, const auto &B){return A.b > B.b;});
	
	for(auto &[a, b, id]:pd1) {
		ord.push_back(id);
		A_t += a;
		B_t = max(A_t, B_t) + b;
	}

	for(auto &[a, b, id]:pd2) {
		ord.push_back(id);
		A_t += a;
		B_t = max(A_t, B_t) + b;
	}

	cout << max(A_t, B_t) << endl;
	for(auto &i:ord) cout << i << ' ';
}